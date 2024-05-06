//build from source file serial.asm
const unsigned char PROGMEM code[MEMSIZE] = {
	0xf3, 0x31, 0x00, 0x0c, 0x21, 0x3c, 0x00, 0x7e, 0xb7, 0xca, 0x13, 0x00,
	0xcd, 0x31, 0x00, 0x23, 0xc3, 0x07, 0x00, 0xdb, 0x00, 0x0f, 0xda, 0x13,
	0x00, 0xdb, 0x01, 0xcd, 0x31, 0x00, 0xfe, 0x58, 0xca, 0x30, 0x00, 0xfe,
	0x0d, 0xc2, 0x13, 0x00, 0x3e, 0x0a, 0xcd, 0x31, 0x00, 0xc3, 0x13, 0x00,
	0x76, 0xf5, 0xdb, 0x00, 0x07, 0xda, 0x32, 0x00, 0xf1, 0xd3, 0x01, 0xc9,
	0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x74,
	0x68, 0x65, 0x20, 0x38, 0x30, 0x38, 0x30, 0x20, 0x43, 0x50, 0x55, 0x0d,
	0x0a, 0x49, 0x20, 0x77, 0x69, 0x6c, 0x6c, 0x20, 0x65, 0x63, 0x68, 0x6f,
	0x20, 0x77, 0x68, 0x61, 0x74, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x74, 0x79,
	0x70, 0x65, 0x2c, 0x20, 0x74, 0x79, 0x70, 0x65, 0x20, 0x58, 0x20, 0x69,
	0x66, 0x20, 0x64, 0x6f, 0x6e, 0x65, 0x0d, 0x0a, 0x00
};
unsigned short code_length = 129;
unsigned short code_load_addr = 0x0000;
unsigned short code_start_addr = 0x0000;
