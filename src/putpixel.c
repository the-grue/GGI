#include <graphics.h>

extern unsigned int * ylookup;
extern struct status status;

void putpixel(int x, int y, int color)
{
	char * pixaddr;
#ifdef SAFENSLOW
	if(x > status.xres || x < 0 || y > status.yres || y < 0)
		return;		// Out of bounds, do nothing
#endif

	pixaddr = (char *) (status.framebuffer + ylookup[y] + x);

	*pixaddr = (unsigned char) color;	
}
