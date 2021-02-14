//  BGI Stroke File Format
//  As defined in Appendix 1 (7) 
//
//  Magic is "PK", 8, 8
//  Followed by a text string or strings that end in 0, 26
//  before the header structure below

struct chrheader {
	unsigned short HeaderSize;
	char fname[4];
	unsigned short DataSize;
	unsigned char MajorVersion, MinorVersion;
};

//  The following structure is the prefix to the actual
//  stroke data and starts at HeaderSize bytes in the file

struct chrinfo {
	unsigned char filetype;		// '+' flags stroke file type
	unsigned short numchars;	// number chars in font file (n)
	unsigned char undefined1;	// undefined
	unsigned char firstchar;	// ASCII value of first char in file
	unsigned short strokeoffset;	// offset to stroke definitions (8+3n)
	unsigned char scanflag;		// scan flag (normally 0)
	unsigned char dtop;		// distance from origin to top of capital
	unsigned char dbase;		// distance from origin to baseline
	unsigned char ddec;		// distance from origin to bottom of descender
	unsigned char undefined2[5];	// undefined
};

//  Following the above structure in the file, you have
//  offsets to individual character definitions (2n)
//  width table (one word per character) (n)
//  character definitions begin after this table

//  Opcode definitions
//
//  Byte 1	 7   6   5   4   3   2   1   0  bit #
//  		op1  < 7 bit signed X coord  >
//  Byte 2	 7   6   5   4   3   2   1   0  bit #
//  		op2  < 7 bit signed Y coord  >

#define OP_END	0
#define OP_MOVE	2
#define OP_DRAW	3
