//
// Intel 8080 CPU emulation on an Arduino Nano
//            derived from Z80PACK
// Copyright 2024, Udo Munk
//
// History:
// 04-MAY-2024 Release 1.0 implements a very basic 8080 system
// 06-MAY-2024 Release 1.1 add support for a ROM in flash
// 07-MAY-2024 Release 1.2 move 8080 memory into a FRAM
// 18-MAY-2024 Release 1.4 read 8080 code from a file on SD into FRAM
// 19-MAY-2024 Release 1.5 use SdFat lib instead of SD lib to save memory
//

// 64 KB unbanked memory in FRAM
// we want hardware SPI, the 2 and 4 MBit modules can be clocked
// with 40 MHz, the smaller ones with 20 MHz
Adafruit_FRAM_SPI fram = Adafruit_FRAM_SPI(FRAM_CS, 40000000);

// setup FRAM
void init_memory(void)
{
  uint32_t i;

  // fill top page of 8080 memory with 0xff, write protected ROM
  for (i = 0xff00; i <= 0xffff; i++)
    fram.write8(i, 0xff);
}

// read a byte from 8080 CPU memory at address addr
static inline BYTE memrdr(WORD addr)
{
  return fram.read8((uint32_t) addr);
}

// write a byte data into 8080 CPU RAM at address addr 
static inline void memwrt(WORD addr, BYTE data)
{
  if (addr < 0xff00) // top memory page write protected for MITS BASIC
    fram.write8((uint32_t) addr, data);
}

// load a file 'name' into FRAM
void load_file(char *name)
{
  uint32_t i = 0;
  unsigned char c;
  FatFile sd_file;
  char SFN[25];
 
  strcpy(SFN, "/CODE80/");
  strcat(SFN, name);
  strcat(SFN, ".BIN");

#ifdef DEBUG
  Serial.print(F("Filename: "));
  Serial.println(SFN);
#endif

  if (!sd_file.openExistingSFN(SFN)) {
    Serial.println(F("File not found\n"));
    return;
  }

  while(sd_file.read(&c, 1))
    fram.write8(i++, c);

  sd_file.close();
}
