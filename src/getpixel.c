#include <graphics.h>

extern unsigned int * ylookup;
extern struct status status;

unsigned int getpixel(int x, int y)
{
	char * pixaddr;
#ifdef SAFENSLOW
	if(x > status.xres || x < 0 || y > status.yres || y < 0)
		return 0;		// Out of bounds, do nothing
#endif

	pixaddr = (char *) (ylookup[y] + x);

	return *pixaddr;	
}
