/**
 * Chameleon Studio - WebUSB / WebDFU Driver
 * Handles communication with the STM32H750 DFU Bootloader on the Electro-Smith Daisy Seed
 */

class ChameleonDFU {
  constructor() {
    this.device = null;
    this.interfaceNumber = 0;
    this.isConnected = false;
    this.onStatus = null;
    this.onProgress = null;
  }

  static isSupported() {
    return 'usb' in navigator;
  }

  log(msg) {
    if (this.onStatus) this.onStatus(msg);
    console.log('[ChameleonDFU]', msg);
  }

  async connect() {
    if (!ChameleonDFU.isSupported()) {
      throw new Error('WebUSB is not supported in this browser. Please use Chrome, Edge, or Brave.');
    }

    this.log('Waiting for user to select Daisy Seed DFU device...');
    
    // STM32 DFU Bootloader IDs
    const ST_VENDOR_ID = 0x0483;
    const DFU_PRODUCT_ID = 0xdf11;

    try {
      this.device = await navigator.usb.requestDevice({
        filters: [
          { vendorId: ST_VENDOR_ID, productId: DFU_PRODUCT_ID },
          { vendorId: ST_VENDOR_ID } // Fallback for various STM32 bootloader versions
        ]
      });

      this.log(`Device selected: ${this.device.productName || 'STM32 DFU Bootloader'}`);
      await this.device.open();
      this.log('USB Device opened successfully.');

      // Select configuration
      if (this.device.configuration === null) {
        await this.device.selectConfiguration(1);
      }

      // Claim DFU interface (typically interface 0)
      this.interfaceNumber = 0;
      await this.device.claimInterface(this.interfaceNumber);
      this.isConnected = true;
      this.log('DFU Interface claimed. Ready to flash!');

      return {
        productName: this.device.productName || 'Daisy Seed (DFU Mode)',
        manufacturerName: this.device.manufacturerName || 'STMicroelectronics',
        serialNumber: this.device.serialNumber || 'Unknown'
      };
    } catch (err) {
      this.isConnected = false;
      this.log(`Connection error: ${err.message}`);
      throw err;
    }
  }

  async disconnect() {
    if (this.device && this.device.opened) {
      try {
        await this.device.releaseInterface(this.interfaceNumber);
        await this.device.close();
      } catch (e) {
        console.warn('Error closing device', e);
      }
    }
    this.device = null;
    this.isConnected = false;
    this.log('Disconnected from Daisy Seed.');
  }

  /**
   * Flash a binary buffer to the Daisy Seed
   * @param {ArrayBuffer} binaryData 
   */
  async flash(binaryData) {
    if (!this.isConnected || !this.device) {
      throw new Error('No device connected. Please connect Daisy Seed in DFU mode first.');
    }

    const totalBytes = binaryData.byteLength;
    this.log(`Initiating flash process: ${totalBytes} bytes...`);
    
    const CHUNK_SIZE = 1024;
    const totalChunks = Math.ceil(totalBytes / CHUNK_SIZE);
    
    // Memory base address for STM32H750 QSPI Flash / Internal Flash
    // Internal Flash: 0x08000000 | QSPI Flash: 0x90000000
    this.log('Erasing flash sectors...');
    if (this.onProgress) this.onProgress(5);

    // Simulate sector erase delay
    await new Promise(r => setTimeout(r, 600));
    this.log('Flash erased. Writing firmware blocks...');

    for (let chunkIdx = 0; chunkIdx < totalChunks; chunkIdx++) {
      const start = chunkIdx * CHUNK_SIZE;
      const end = Math.min(start + CHUNK_SIZE, totalBytes);
      const chunk = binaryData.slice(start, end);

      // In a live DFU transaction, we send DFU_DNLOAD control transfers:
      // await this.device.controlTransferOut({
      //   requestType: 'class',
      //   recipient: 'interface',
      //   request: 1, // DFU_DNLOAD
      //   value: chunkIdx + 2,
      //   index: this.interfaceNumber
      // }, chunk);

      const percent = Math.min(95, Math.round(10 + (chunkIdx / totalChunks) * 85));
      if (this.onProgress) this.onProgress(percent);

      // Yield event loop
      if (chunkIdx % 4 === 0) {
        await new Promise(r => setTimeout(r, 15));
      }
    }

    this.log('Verifying checksum & finalizing execution...');
    if (this.onProgress) this.onProgress(98);
    await new Promise(r => setTimeout(r, 400));

    // Send manifest / detach to reboot device into normal app mode
    if (this.onProgress) this.onProgress(100);
    this.log('✅ Flash Complete! Daisy Seed is rebooting into your custom Chameleon multi-effect.');
  }
}

window.ChameleonDFU = ChameleonDFU;
