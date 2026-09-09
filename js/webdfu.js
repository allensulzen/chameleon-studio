/**
 * Chameleon Studio — WebUSB DfuSe driver for the STM32H750 bootloader on the Daisy Seed.
 *
 * Real protocol (USB DFU 1.1 + ST DfuSe extensions), no simulation:
 *   connect()   pick the device (0483:DF11), claim interface 0 / alt 0 (Internal Flash @0x08000000)
 *   flash(buf)  erase the sector(s) the image covers, set address pointer, DNLOAD in transfer-size
 *               blocks with GETSTATUS polling, then manifest (jump to the new firmware)
 *
 * The Daisy Seed's internal flash is a single 128 KB sector at 0x08000000. Images built with
 * APP_TYPE=BOOT_NONE (the default firmware/Makefile) go there. Bigger builds that use the Daisy
 * bootloader live in QSPI (0x90040000) — pass {address} to flash() for those.
 */
class ChameleonDFU {
  constructor() {
    this.device = null; this.interfaceNumber = 0; this.isConnected = false;
    this.onStatus = null; this.onProgress = null; this.transferSize = 1024;
  }
  static isSupported() { return 'usb' in navigator; }
  log(msg) { if (this.onStatus) this.onStatus(msg); console.log('[ChameleonDFU]', msg); }

  // ---- USB DFU constants
  static get REQ() { return { DETACH: 0, DNLOAD: 1, UPLOAD: 2, GETSTATUS: 3, CLRSTATUS: 4, GETSTATE: 5, ABORT: 6 }; }
  static get STATE() { return { appIDLE: 0, appDETACH: 1, dfuIDLE: 2, dfuDNLOAD_SYNC: 3, dfuDNBUSY: 4, dfuDNLOAD_IDLE: 5, dfuMANIFEST_SYNC: 6, dfuMANIFEST: 7, dfuMANIFEST_WAIT_RESET: 8, dfuUPLOAD_IDLE: 9, dfuERROR: 10 }; }

  async connect() {
    if (!ChameleonDFU.isSupported()) throw new Error('WebUSB is not supported in this browser — use Chrome, Edge or Brave.');
    const devs = await navigator.usb.getDevices();
    this.device = devs.find(d => d.vendorId === 0x0483 && d.productId === 0xdf11) || await navigator.usb.requestDevice({ filters: [{ vendorId: 0x0483, productId: 0xdf11 }, { vendorId: 0x0483 }] });
    await this.device.open();
    if (this.device.configuration === null) await this.device.selectConfiguration(1);
    // alt 0 of interface 0 is "@Internal Flash /0x08000000/..."
    const iface = this.device.configuration.interfaces[0];
    this.interfaceNumber = iface.interfaceNumber;
    await this.device.claimInterface(this.interfaceNumber);
    await this.device.selectAlternateInterface(this.interfaceNumber, 0);
    await this.readTransferSize();
    this.isConnected = true;
    this.log(`Connected: ${this.device.productName || 'STM32 BOOTLOADER'} (transfer size ${this.transferSize})`);
    await this.clearToIdle();
    return { productName: this.device.productName || 'Daisy Seed (DFU)', serialNumber: this.device.serialNumber || '' };
  }

  async disconnect() {
    if (this.device && this.device.opened) { try { await this.device.releaseInterface(this.interfaceNumber); await this.device.close(); } catch (e) {} }
    this.device = null; this.isConnected = false;
  }

  // DFU functional descriptor (type 0x21) carries wTransferSize; ST uses 1024 (0x400)
  async readTransferSize() {
    try {
      const r = await this.device.controlTransferIn({ requestType: 'standard', recipient: 'device', request: 6, value: 0x0200, index: 0 }, 512);
      const d = new DataView(r.data.buffer);
      for (let i = 0; i + 1 < d.byteLength;) { const len = d.getUint8(i), type = d.getUint8(i + 1); if (type === 0x21 && len >= 9) { this.transferSize = d.getUint16(i + 5, true); return; } i += len || 1; }
    } catch (e) { /* keep default */ }
  }

  ctrlOut(request, value, data) { return this.device.controlTransferOut({ requestType: 'class', recipient: 'interface', request, value, index: this.interfaceNumber }, data); }
  ctrlIn(request, length) { return this.device.controlTransferIn({ requestType: 'class', recipient: 'interface', request: request, value: 0, index: this.interfaceNumber }, length); }

  async getStatus() {
    const r = await this.ctrlIn(ChameleonDFU.REQ.GETSTATUS, 6);
    const d = new DataView(r.data.buffer);
    return { status: d.getUint8(0), pollTimeout: d.getUint8(1) | (d.getUint8(2) << 8) | (d.getUint8(3) << 16), state: d.getUint8(4) };
  }
  async getState() { const r = await this.ctrlIn(ChameleonDFU.REQ.GETSTATE, 1); return new DataView(r.data.buffer).getUint8(0); }
  async clearToIdle() {
    const S = ChameleonDFU.STATE;
    let st = await this.getState();
    if (st === S.dfuERROR) { await this.ctrlOut(ChameleonDFU.REQ.CLRSTATUS, 0, new ArrayBuffer(0)); st = await this.getState(); }
    if (st !== S.dfuIDLE) { await this.ctrlOut(ChameleonDFU.REQ.ABORT, 0, new ArrayBuffer(0)); st = await this.getState(); }
    if (st !== S.dfuIDLE) throw new Error(`Bootloader not idle (state ${st}) — re-enter DFU: hold BOOT, tap RESET`);
  }
  // After a DNLOAD the device sits in DNBUSY for pollTimeout ms; poll until it's back to DNLOAD_IDLE
  async waitDownloadDone() {
    const S = ChameleonDFU.STATE;
    for (let i = 0; i < 400; i++) {
      const s = await this.getStatus();
      if (s.state === S.dfuDNLOAD_IDLE || s.state === S.dfuIDLE) return s;
      if (s.state === S.dfuERROR) { const msg = ChameleonDFU.errorText(s.status); await this.ctrlOut(ChameleonDFU.REQ.CLRSTATUS, 0, new ArrayBuffer(0)); throw new Error(`DFU error: ${msg}`); }
      await new Promise(r => setTimeout(r, Math.max(s.pollTimeout, 5)));
    }
    throw new Error('Timed out waiting for the bootloader');
  }
  static errorText(code) { return ({ 0: 'OK', 1: 'target not writable', 2: 'file not for this device', 3: 'write failed', 4: 'erase failed', 5: 'erase check failed', 6: 'program failed', 7: 'verify failed', 8: 'address out of range', 9: 'received too little data', 10: 'firmware corrupt', 11: 'vendor error', 12: 'unexpected USB request', 13: 'unexpected PoR', 14: 'unknown', 15: 'stalled' })[code] || `code ${code}`; }

  // DfuSe commands go through DNLOAD block 0
  async dfuseCommand(cmd, address) {
    const b = new Uint8Array(5); b[0] = cmd; b[1] = address & 0xff; b[2] = (address >> 8) & 0xff; b[3] = (address >> 16) & 0xff; b[4] = (address >>> 24) & 0xff;
    await this.ctrlOut(ChameleonDFU.REQ.DNLOAD, 0, b);
    await this.waitDownloadDone();
  }
  eraseSector(address) { return this.dfuseCommand(0x41, address); }
  setAddress(address) { return this.dfuseCommand(0x21, address); }

  /**
   * @param {ArrayBuffer} binaryData  raw .bin image
   * @param {{address?:number, sectorSize?:number}} opts  address defaults to internal flash
   */
  async flash(binaryData, opts = {}) {
    if (!this.isConnected || !this.device) throw new Error('Not connected — pair the Seed in DFU mode first.');
    const address = opts.address ?? 0x08000000;
    const sectorSize = opts.sectorSize ?? (address >= 0x90000000 ? 4096 : 128 * 1024);
    const total = binaryData.byteLength;
    if (!total) throw new Error('Empty firmware image');
    if (address === 0x08000000 && total > 128 * 1024) throw new Error(`Image is ${(total / 1024).toFixed(0)} KB — internal flash holds 128 KB. Build for the Daisy bootloader (APP_TYPE=BOOT_QSPI) instead.`);
    const progress = (p) => { if (this.onProgress) this.onProgress(Math.round(p)); };

    await this.clearToIdle();
    this.log(`Erasing ${Math.ceil(total / sectorSize)} sector(s) at 0x${address.toString(16)}…`);
    for (let a = address; a < address + total; a += sectorSize) { await this.eraseSector(a); progress(5 + 10 * (a - address) / total); }

    this.log(`Writing ${total} bytes in ${this.transferSize}-byte blocks…`);
    await this.setAddress(address);
    const blocks = Math.ceil(total / this.transferSize);
    for (let i = 0; i < blocks; i++) {
      const chunk = binaryData.slice(i * this.transferSize, Math.min((i + 1) * this.transferSize, total));
      await this.ctrlOut(ChameleonDFU.REQ.DNLOAD, 2 + i, chunk);   // block n writes at address + n*transferSize
      await this.waitDownloadDone();
      progress(15 + 80 * (i + 1) / blocks);
    }

    // manifest: zero-length DNLOAD from the start address makes the bootloader jump into the image
    this.log('Starting the new firmware…');
    await this.setAddress(address);
    try { await this.ctrlOut(ChameleonDFU.REQ.DNLOAD, 0, new ArrayBuffer(0)); await this.getStatus(); } catch (e) { /* device re-enumerates / drops off USB here — expected */ }
    progress(100);
    this.isConnected = false;
    try { await this.device.close(); } catch (e) {}
    this.log('Flash complete — the Seed has rebooted into Chameleon.');
  }
}
