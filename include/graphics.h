/* Include file for GGI Library
 *
 * References:
 * (1) Borland C++ Version 5 Programmer's Guide
 * (2) BGI.DOC (The BGI Driver Toolkit)
 * (3) Borland C++ Version 4.0 DOS Reference
 * (4) Borland PowerPack for DOS User's Guide
 * (5) VESA BIOS EXTENSION (VBE) Core Functions Standard Version 3.0
 */

#ifndef __GRAPHICS_H
#define __GRAPHICS_H

/*
 * VESA Mode Info Block structure as defined on
 * pages 30-31 (5)
 */

struct ModeInfoBlock {
						// * Mandatory for all VBE revisions
	unsigned short ModeAttributes;		// Mode attributes
	unsigned char WinAAttributes;		// Window A attributes
	unsigned char WinBAttributes;		// Window B attributes
	unsigned short WinGranularity;		// Window granularity
	unsigned short WinSize;			// Window size
	unsigned short WinASegment;		// Window A start segment
	unsigned short WinBSegment;		// Window B start segment
	unsigned int WinFuncPtr;		// Real mode pointer to window function
	unsigned short BytesPerScanLine;	// Bytes per scan line
						// * Mandatory for VBE 1.2 and above
	unsigned short XResolution;		// Horizontal resolution in pixels or chars
	unsigned short YResolution;		// Vertical resolution in pixels or chars
	unsigned char XCharSize;		// Character cell width in pixels
	unsigned char YCharSize;		// Character cell height in pixels
	unsigned char NumberOfPlanes;		// Number of memory planes
	unsigned char BitsPerPixel;		// Bits per pixel
	unsigned char NumberOfBanks;		// Number of banks
	unsigned char MemoryModel;		// Memory model type
	unsigned char BankSize;			// Bank size in KB
	unsigned char NumberOfImagePages;	// Number of images
	unsigned char Reserved1;		// Reserved for page function
						// * Direct Color Fields (direct/6 and YUV/7)
	unsigned char RedMaskSize;		// Size of direct color red mask in bits
	unsigned char RedFieldPosition;		// Bit position of lsb of red mask
	unsigned char GreenMaskSize;		// Size of direct color green mask in bits
	unsigned char GreenFieldPosition;	// Bit position of lsb of green mask
	unsigned char BlueMaskSize;		// Size of direct color blue mask in bits
	unsigned char BlueFieldPosition;	// Bit position of lsb of blue mask
	unsigned char RsvdMaskSize;		// Size of direct color reserved mask in bits
	unsigned char RsvdFieldPosition;	// Bit position of lsb of reserved mask
	unsigned char DirectColorModeInfo;	// Direct color mode attributes
						// * Mandatory for VBE 2.0 and above
	unsigned int PhysBasePtr;		// Physical address for flat memory frame buffer
	unsigned int Reserved2;			// Reserved - always set to 0
	unsigned short Reserved3;		// Reserved - always set to 0
						// Mandatory for VBE 3.0 and above
	unsigned short LinBytesPerScanLine;	// Bytes per scan line for linear modes
	unsigned char BnkNumberOfImagePages;	// Number of images for banked modes
	unsigned char LinNumberOfImagePages;	// Number of images for Linear modes
	unsigned char LinRedMaskSize;		// Size of direct color red mask (linear)
	unsigned char LinRedFieldPosition;	// Bit position of lsb of red mask (linear)
	unsigned char LinGreenMaskSize;		// Size of direct color green mask (linear)
	unsigned char LinGreenFieldPosition;	// Bit position of lsb of green mask (linear)
	unsigned char LinBlueMaskSize;		// Size of direct color blue mask (linear)
	unsigned char LinBlueFieldPosition;	// Bit position of lsb of blue mask (linear)
	unsigned char LinRsvdMaskSize;		// Size of direct color reserved mask (linear)
	unsigned char LinRsvdFieldPosition;	// Bit position of lsb of reserved mask (linear)
	unsigned int MaxPixelClock;		// Masimum pixel clock (in Hz) for graphics mode

	unsigned char Reserved4[190];		// Remainder of ModeInfoBlock (256 bytes total)
} __attribute__ ((packed));

/*
 * graphics_drivers constants as defined on
 * page 74 (3) with additions/changes for 
 * VGA/VESA only as defined on page 113 (4)
 */

enum graphics_drivers {
	DETECT  = 0, 		// Autodetect
	VGA256  = 11, 		// VGA 320x200x256 mode 13h
	VESA256 = 19		// VESA 256 color modes
};

/*
 * graphics_modes numbers as defined on
 * page 114 (4) replacing RES640x350 with
 * VGA 320x200 mode 13h as RES320x200
 */

enum graphics_modes {
	RES320x200   = 0,	// VGA 320x200x256 mode 13h
	RES640x480   = 1,	// VESA 640x480x256 mode 101h
	RES800x600   = 2,	// VESA 800x600x256 mode 103h
	RES1024x768  = 3,	// VESA 1024x768x256 mode 105h
	RES1280x1024 = 4	// VESA 1280x1024x256 mode 107h
};

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

/* Fill pattern constants defined on
 * page 61 (3)
 */

enum fill_patterns {
	EMPTY_FILL,		// Fill with background color
	SOLID_FILL,		// Solid fill
	LINE_FILL,		// Fill with ---
	LTSLASH_FILL,		// Fill with ///, thin lines
	SLASH_FILL,		// Fill with ///, thick lines
	BKSLASH_FILL,		// Fill with \\\, thick lines
	LTBKSLASH_FILL,		// Fill with \\\, thin lines 
	HATCH_FILL,		// Light hatch fill
	XHATCH_FILL,		// Heavy crosshatch fill
	INTERLEAVE_FILL,	// Interleaving line fill
	WIDE_DOT_FILL,		// Widely spaced dot fill
	CLOSE_DOT_FILL,		// Closely spaced dot fill
	USER_FILL		// User-defined fill pattern
};

/* Structure for fill settings as defined on
 * page 61 (3)
 */

struct fillsettingstype {
	int pattern;
	int color;
};

/* Line style constants defined on
 * page 63 (3)
 */

enum line_styles {
	SOLID_LINE 	= 0,
	DOTTED_LINE 	= 1,
	CENTER_LINE 	= 2,
	DASHED_LINE 	= 3,
	USERBIT_LINE 	= 4
};

/* Line thickness constants defined on
 * page 64 (3)
 */

enum line_widths {
	NORM_WIDTH	= 1,
	THICK_WIDTH	= 3
};

/* Structure for line settings defined on
 * page 63 (3)
 */

struct linesettingstype {
	int linestyle;
	unsigned upattern;
	int thickness;
};

/* Ops for putimage function defined on
 * page 83 (3)
 */

enum putimage_ops {
	COPY_PUT,
	XOR_PUT,
	OR_PUT,
	AND_PUT,
	NOT_PUT
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

/* Structure for viewporttype as defined on
 * page 70 (3)
 */

struct viewporttype {
	int left, top, right, bottom;
	int clip;
};

/* Text justification constants as defined on
 * page 97 (3)
 */

enum text_just {
	LEFT_TEXT	= 0,		// Left justify text
	CENTER_TEXT	= 1,		// Center text horiz or vert
	RIGHT_TEXT	= 2,		// Right justify text
	BOTTOM_TEXT	= 0,		// Justify from bottom
	TOP_TEXT	= 2		// Justify from top
};

/* Font name constants as defined on
 * page 98 (3)
 */

enum font_names {
	DEFAULT_FONT	= 0,		// 8x8 bit-mapped font
	TRIPLEX_FONT	= 1,		// Stroked triplex font
	SMALL_FONT	= 2,		// Stroked small font
	SANS_SERIF_FONT	= 3,		// Stroked sans-serif font
	GOTHIC_FONT	= 4,		// Stroked gothic font
	SCRIPT_FONT	= 5,		// Stroked script font
	SIMPLEX_FONT	= 6,		// Stroked simplex font
	TRIPLEX_SCR_FONT= 7,		// Stroked triplex script font
	COMPLEX_FONT	= 8,		// Stroked complex font
	EUROPEAN_FONT	= 9,		// Stroked European font
	BOLD_FONT	= 10,		// Stroked bold font
};

/* Direction constants as defined on
 * page 99 (3)
 */

enum font_direction {
	HORIZ_DIR	= 0,		// Left to right
	VERT_DIR	= 1,		// Bottom to top
};

/* Structure for textsettingstype as defined on
 * page 69 (3)
 */

struct textsettingstype {
	int font;
	int direction;
	int charsize;
	int horiz;
	int vert;
};

/* GGI Internal Structures
 */

struct current_gmode {
        int gdriver;
        int gmode;
};

/* GGI specific function prototypes
 */

void setsystemfont(unsigned char *userfont);

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
void initgraph(int *graphdriver, int *graphmode, char *pathtodriver);
void detectgraph(int *graphdriver, int *graphmode);
int getgraphmode(void);
char * getdrivername(void);
int getgraphmode(void);
int getmaxcolor(void);
int getmaxmode(void);
int getmaxx(void);
int getmaxy(void);
char * getmodename(int mode_number);
void getmoderange(int graphdriver, int *lomode, int *himode);
void getpalette(struct palettetype *palette);
int getpalettesize(void);
void closegraph(void);
void putpixel(int x, int y, int color);
void line(int x1, int y1, int x2, int y2);
unsigned int getpixel(int x, int y);
int getx(void);
int gety(void);
void linerel(int dx, int dy);
void lineto(int x, int y);
void moverel(int dx, int dy);
void moveto(int x, int y);
void rectangle(int left, int top, int right, int bottom);
void circle(int x, int y, int radius);
unsigned int imagesize(int left, int top, int right, int bottom);
void getimage(int left, int top, int right, int bottom, void *bitmap);
void putimage(int left, int top, void *bitmap, int op);
void bar(int left, int top, int right, int bottom);
void bar3d(int left, int top, int right, int bottom, int depth, int topflag);
void cleardevice(void);
void clearviewport(void);
void getviewsettings(struct viewporttype *viewport);
void setviewport(int left, int top, int right, int bottom, int clip);
void gettextsettings(struct textsettingstype *texttypeinfo);
void settextjustify(int horiz, int vert);
void settextstyle(int font, int direction, int charsize);
void outtext(char *textstring);
int textheight(char *textstring);
int textwidth(char *textstring);
void drawpoly(int numpoints, int *polypoints);
void outtextxy(int x, int y, char *textstring);

#endif	/* __GRAPHICS_H */
