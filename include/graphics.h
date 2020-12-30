/* Include file for GGI Library
 *
 * References:
 * (1) Borland C++ Version 5 Programmer's Guide
 * (2) BGI.DOC (The BGI Driver Toolkit)
 * (3) Borland C++ Version 4.0 DOS Reference
 */

#ifndef __GRAPHICS_H
#define __GRAPHICS_H

/*
 * status structure (enhanced) as defined on
 * page 4 (2) with additions as required
 * originally 20 bytes expanded to 32 bytes
 */

struct status {
	char	stat;		// Current Device Status (0 = No Errors)
	char	devtyp;		// Device Type Identifier (must be 0)
	short	xres;		// Device Full Resolution in X Direction
	short	yres;		// Device Full Resolution in Y Direction
	short	xefres;		// Device Effective X Resolution
	short	yefres;		// Device Effective Y Resolution
	short	xinch;		// Device X Size in inches * 1000
	short	yinch;		// Device Y Size in inches * 1000
	short	aspec;		// Aspect Ratio = (y_size/x_size) * 10000
	char	res1[4];	// Reserved values (8h, 8h, 90h, 90h per doc)
/* This is the end of the BGI status structure type
 * variables below here are additions for GGI
 */
	short	scanlinebytes;	// For VESA or other scan lines longer than
#ifdef	X64
	void	*framebuffer;	// Accommodate for 64bit pointer to framebuffer
	char	res2[2];	// Future expansion
#else
	void	*framebuffer;	// Accommodate for 32bit pointer to framebuffer
	char	res2[6];	// Future expansion
#endif
};

/*
 * arccoordstype structure as defined on
 * page 60 (3)
 */

struct arccoordstype {
	int	x;		// Center point x
	int	y;		// Center point y
	int	xstart;		// Starting point x
	int	ystart;		// Starting point y
	int	xend;		// Ending point x
	int	yend;		// Ending point y
};

/* graphics_errors constants as defined on
 * page 312 (1)
 */

enum graphics_errors {
	grOk			= 0,	// No error
	grNoInitGraph		= -1,	// (GGI) graphics not installed (use initgraph)
	grNotDetected		= -2,	// Graphics hardware not detected
	grFileNotFound		= -3,	// Device driver file not found
	grInvalidDriver		= -4,	// Invalid device driver file
	grNoLoadMem		= -5,	// Not enough memory to load driver
	grNoScanMem		= -6,	// Out of memory in scan fill
	grNoFloodMem		= -7,	// Out of memory in flood fill
	grFontNotFound		= -8,	// Font file not found
	grNoFontMem		= -9,	// Not enough memory to load font
	grInvalidMode		= -10,	// Invalid graphics mode for selected driver
	grError			= -11,	// Graphics error
	grIOerror		= -12,	// Graphics I/O error
	grInvalidFont		= -13,	// Invalid font file
	grInvalidFontNum	= -14,	// Invalid font number
	grInvalidDeviceNum	= -15,	// Invalid device number
	grInvalidVersion	= -18	// Invalid version of file
};

/* COLORS constants defined on
 * page 311 (1)
 */

enum COLORS {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

/* Structure for palettetype as defined on
 * page 84 (3)
 * colors has been changed from signed char 
 * to char to hold 255 colors
 */

#define	MAXCOLORS	255		// 256 Color mode only for palette
					// High color uses mixed values and no palette

struct palettetype {
	unsigned char size;
	unsigned char colors[MAXCOLORS + 1];
};

/* Function prototypes for callable functions as
 * defined in (3)
 */

char * grapherrormsg(int errorcode);
int graphresult(void);
void getarccoords(struct arccoordstype *arccoords);
void getaspectratio(int *xasp, int *yasp);
int getbkcolor(void);
int getcolor(void);
void setbkcolor(int color);
void setcolor(int color);

#endif	/* __GRAPHICS_H */
