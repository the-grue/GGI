#include <graphics.h>
#include <stdlib.h>

/* GGI doesn't use driver files, so we can co-opt the third parameter
 * to initgraph as a pointer to a valid VESA Mode Info Block
 * as described on pages 30-31 (5) - see graphics.h for resources
 * referenced in parentheses
 */

#ifdef NULL
#ifdef MMURTL
#undef NULL
#define NULL 0
#endif
#endif

struct ModeInfoBlock * MIB = NULL;
struct status status;
int ingraphics = 0;
struct current_gmode current_gmode; 
unsigned int *ylookup = 0;
struct palettetype palettetype;
unsigned char currcolor;
unsigned int cp_x, cp_y;
struct fillsettingstype fillsettingstype;
struct linesettingstype linesettingstype;
struct viewporttype viewporttype;
struct textsettingstype textsettingstype;
unsigned char * systemfont = NULL;

/* fill blocks as defined in (2)
 */

char fill_blocks[12][8] = {
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
	{ 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00 },
	{ 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 },
	{ 0xE0, 0xC1, 0x83, 0x07, 0x0E, 0x1C, 0x38, 0x70 },
	{ 0xF0, 0x78, 0x3C, 0x1E, 0x0F, 0x87, 0xC3, 0xE1 },
	{ 0xA5, 0xD2, 0x69, 0xB4, 0x5A, 0x2D, 0x96, 0x4B },
	{ 0xFF, 0x88, 0x88, 0x88, 0xFF, 0x88, 0x88, 0x88 },
	{ 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 },
	{ 0xCC, 0x33, 0xCC, 0x33, 0xCC, 0x33, 0xCC, 0x33 },
	{ 0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x08, 0x00 },
	{ 0x88, 0x00, 0x22, 0x00, 0x88, 0x00, 0x22, 0x00 }
};

/* line style patterns as defined in (2)
 */

unsigned short line_patterns[5] = { 0xFFFF, 0xCCCC, 0xFC78, 0xF8F8, 0xFFFF };

void initgraph(int *graphdriver, int *graphmode, char *pathtodriver)
{
	status.devtyp = 0;
	status.res1[0] = 8;
	status.res1[1] = 8;
	status.res1[2] = 0x90;
	status.res1[3] = 0x90;

	palettetype.size = MAXCOLORS;
	currcolor = WHITE;
	cp_x = 0;
	cp_y = 0;
	fillsettingstype.pattern = EMPTY_FILL;
	fillsettingstype.color = palettetype.colors[0];
	linesettingstype.linestyle = SOLID_LINE;
	linesettingstype.upattern = 0;
	linesettingstype.thickness = NORM_WIDTH;
	textsettingstype.font = DEFAULT_FONT;
	textsettingstype.direction = HORIZ_DIR;
	textsettingstype.charsize = 1;
	textsettingstype.horiz = LEFT_TEXT;
	textsettingstype.vert = TOP_TEXT;

	for(int counter = 0; counter <= palettetype.size; counter++)
		palettetype.colors[counter] = (unsigned char) counter;

	if((*graphdriver == VGA256) || ((*graphdriver == DETECT) && (*pathtodriver == NULL)))
	{
		*graphmode = RES320x200;	
		*graphdriver = VGA256;
		status.xres = 319;
		status.yres = 199;
		status.xefres = 319;
		status.yefres = 199;
		status.xinch = 9000;
		status.yinch = 7000;
		status.aspec = 10000;
		status.scanlinebytes = status.xres;
		status.framebuffer = (char *) 0x000A0000;

		status.stat = grOk;
		current_gmode.gdriver = *graphdriver;
		current_gmode.gmode = *graphmode;
		ingraphics = 1;

		ylookup = malloc((status.yres+1) * sizeof(unsigned int));

		for(int counter = 0; counter <= status.yres; counter++)
			ylookup[counter] = (unsigned int) (status.framebuffer + (counter * (status.scanlinebytes + 1)));

		cleardevice();

		return;
	}
	else if(*pathtodriver != NULL)
        {
		MIB = (struct ModeInfoBlock *) pathtodriver;
                if((MIB->ModeAttributes & 7) && (MIB->BitsPerPixel == 8))
                {
                        switch(MIB->XResolution) {
                                case 640:       if(MIB->YResolution == 480) {
                                                        *graphmode = RES640x480;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 800:       if(MIB->YResolution == 600) {
                                                        *graphmode = RES800x600;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 1024:      if(MIB->YResolution == 768) {
                                                        *graphmode = RES1024x768;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 1280:      if(MIB->YResolution == 1024) {
                                                        *graphmode = RES1280x1024;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                 }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                default:        status.stat = grInvalidDriver;
                                                break;
                        };
			if(status.stat == grOk)
			{
				status.xres = MIB->XResolution - 1;
				status.yres = MIB->YResolution - 1;
				status.xefres = status.xres;
				status.yefres = status.yres;
				status.xinch = 9000;
				status.yinch = 7000;
				status.aspec = 10000;	// Need to find out how to calc this!
				status.scanlinebytes = MIB->BytesPerScanLine;
				status.framebuffer = (char *) MIB->PhysBasePtr;

				ingraphics = 1;
				current_gmode.gdriver = *graphdriver;
				current_gmode.gmode = *graphmode;

				ylookup = malloc((status.yres+1) * sizeof(unsigned int));

				for(int counter = 0; counter <= status.yres; counter++)
					ylookup[counter] = (unsigned int) (status.framebuffer + (counter * (status.scanlinebytes + 1)));
			}
                }
                else
                        status.stat = grInvalidDriver;
        }
        else
                status.stat = grNotDetected;

	cleardevice();
}

void detectgraph(int *graphdriver, int *graphmode)
{
	if((*graphdriver == VGA256) || (*graphdriver == DETECT) && (MIB == NULL))
	{
		*graphmode = RES320x200;
		*graphdriver = VGA256;
		status.stat = grOk;
	}
	else if(MIB != NULL)
	{
		if((MIB->ModeAttributes & 7) && (MIB->BitsPerPixel == 8))
		{
			switch(MIB->XResolution) {
				case 640:	if(MIB->YResolution == 480) {
							*graphmode = RES640x480;
							*graphdriver = VESA256;
							status.stat = grOk;
						}
						else
							status.stat = grNotDetected;
						break;
	
				case 800: 	if(MIB->YResolution == 600) {
							*graphmode = RES800x600;
							*graphdriver = VESA256;
							status.stat = grOk;
						}
						else
							status.stat = grNotDetected;
						break;
					  
				case 1024:	if(MIB->YResolution == 768) {
							*graphmode = RES1024x768;
							*graphdriver = VESA256;
							status.stat = grOk;
					  	}
					  	else
							status.stat = grNotDetected;
					  	break;
	
				case 1280: 	if(MIB->YResolution == 1024) {
							*graphmode = RES1280x1024;
							*graphdriver = VESA256;
							status.stat = grOk;
					 	 }
					  	else
							status.stat = grNotDetected;
					 	break;
	
				default: 	status.stat = grNotDetected;
						break;
			};
		}
		else
			status.stat = grNotDetected;
	}
	else
		status.stat = grNotDetected;
}
