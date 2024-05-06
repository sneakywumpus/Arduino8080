//build from source file turnmon.asm
const unsigned char PROGMEM code[MEMSIZE] = {
	0x31, 0x00, 0x0a, 0xcd, 0x8e, 0x00, 0xcd, 0x8e, 0x00, 0x3e, 0x2e, 0xcd,
	0xea, 0x00, 0xcd, 0xe0, 0x00, 0xfe, 0x4d, 0xca, 0x24, 0x00, 0xfe, 0x44,
	0xca, 0x4c, 0x00, 0xfe, 0x4a, 0xc2, 0x00, 0x00, 0xcd, 0x98, 0x00, 0xe9,
	0xcd, 0x98, 0x00, 0xc3, 0x2b, 0x00, 0x23, 0xcd, 0x8e, 0x00, 0x54, 0x5d,
	0xcd, 0xbe, 0x00, 0x1a, 0x67, 0xcd, 0xc4, 0x00, 0xcd, 0x9d, 0x00, 0xeb,
	0xda, 0x2a, 0x00, 0x77, 0xbe, 0xca, 0x2a, 0x00, 0x3e, 0x3f, 0xcd, 0xea,
	0x00, 0xc3, 0x00, 0x00, 0xcd, 0x98, 0x00, 0xeb, 0xd4, 0xdb, 0x00, 0xcd,
	0x98, 0x00, 0xe5, 0x62, 0x6b, 0xcd, 0x8e, 0x00, 0xcd, 0xbe, 0x00, 0xcd,
	0xdb, 0x00, 0x01, 0x10, 0x00, 0x1a, 0x67, 0xc5, 0x3e, 0x08, 0xb9, 0xc2,
	0x76, 0x00, 0x3e, 0x2d, 0xcd, 0xea, 0x00, 0xcd, 0xdb, 0x00, 0xcd, 0xc4,
	0x00, 0xc1, 0xe1, 0x7c, 0xba, 0xc2, 0x85, 0x00, 0x7d, 0xbb, 0xca, 0x00,
	0x00, 0xe5, 0x13, 0x0d, 0xc2, 0x65, 0x00, 0xc3, 0x57, 0x00, 0x3e, 0x0d,
	0xcd, 0xea, 0x00, 0x3e, 0x0a, 0xc3, 0xea, 0x00, 0x06, 0x06, 0xc3, 0x9f,
	0x00, 0x06, 0x03, 0x21, 0x00, 0x00, 0xcd, 0xe0, 0x00, 0x4f, 0xfe, 0x20,
	0x37, 0xc8, 0xe6, 0xb8, 0xee, 0x30, 0xc2, 0x44, 0x00, 0x79, 0xe6, 0x07,
	0x29, 0x29, 0x29, 0x85, 0x6f, 0x05, 0xc2, 0xa2, 0x00, 0xc9, 0x06, 0x06,
	0xaf, 0xc3, 0xce, 0x00, 0x06, 0x03, 0xaf, 0xc3, 0xcb, 0x00, 0x29, 0x17,
	0x29, 0x17, 0x29, 0x17, 0xe6, 0x07, 0xf6, 0x30, 0xcd, 0xea, 0x00, 0x05,
	0xc2, 0xca, 0x00, 0x3e, 0x20, 0xc3, 0xea, 0x00, 0xdb, 0x00, 0x0f, 0xda,
	0xe0, 0x00, 0xdb, 0x01, 0xe6, 0x7f, 0xf5, 0x81, 0x4f, 0xdb, 0x00, 0x07,
	0xda, 0xed, 0x00, 0xf1, 0xd3, 0x01, 0xc9
};
unsigned short code_length = 247;
unsigned short code_load_addr = 0x0000;
unsigned short code_start_addr = 0x0000;
