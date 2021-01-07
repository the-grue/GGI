#include <graphics.h>

#define SAFENSLOW 1

extern unsigned int * ylookup;
extern struct status status;
extern struct palettetype palettetype;

void putpixel(int x, int y, int color)
{
	char * pixaddr;
#ifdef SAFENSLOW
	if(x > status.xres || x < 0 || y > status.yres || y < 0)
		return;		// Out of bounds, do nothing
#endif

	pixaddr = (char *) (ylookup[y] + x);

#ifdef USEPALETTE
	*pixaddr = palettetype.colors[color];
#else
	*pixaddr = (unsigned char) color;	
#endif
}
