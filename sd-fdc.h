//
// Intel 8080 CPU emulation on an Arduino Nano
//            derived from Z80PACK
// Copyright 2024, Udo Munk
//
// FDC for bare metal with disk images on SD drive
// Work in progress, don't try to use yet
// Needed for research what can be done with the memory left
//
// History:
// ??-MAY-2024
//

// offsets in disk command descriptor
#define DD_TRACK	0 // track number
#define DD_SECTOR	1 // sector number
#define DD_DMAL		2 // DMA address low
#define DD_DMAH		3 // DMA address high

// controller commands: MSB command, LSB drive number
#define FDC_SETDD	0x10  // set address of disk descriptor from
			                  // following two OUT's
#define FDC_READ	0x20  // read sector from disk
#define FDC_WRITE	0x40  // write sector to disk

static BYTE fdc_cmd[4];    // fdc command
static BYTE fdc_state = 0; // state of the fdc state machine
static BYTE fdc_stat;      // status of last FDC command
static WORD fdc_cmd_addr;  // address of the disk command
static WORD fdc_dma_addr;  // address for a DMA transfer

// I/O out interface to the 8080 CPU
const void fdc_out(BYTE data)
{
  switch (fdc_state) {
  case 0:	// start of command phase
    switch (data & 0xf0) {
    case FDC_SETDD:
      fdc_state++;
      break;

    case FDC_READ:
      get_fdccmd(fdc_cmd, fdc_cmd_addr);
      fdc_dma_addr = fdc_cmd[DD_DMAL] + (fdc_cmd[DD_DMAH] << 8);
      fdc_stat = read_sec(data & 0x0f, fdc_cmd[DD_TRACK], fdc_cmd[DD_SECTOR], fdc_dma_addr);
      break;

    case FDC_WRITE:
      break;
    }
    break;

  case 1:	// LSB of disk command address
    fdc_cmd_addr = data;
    fdc_state++;
    break;

  case 2:	// MSB of disk command address
    fdc_cmd_addr += data << 8;
    fdc_state = 0;
    break;
  }
}

// I/O in interface to the 8080 CPU
const BYTE fdc_in(void)
{
  return fdc_stat;
}
