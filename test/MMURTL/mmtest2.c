/* Tests pixel plotting on MMURTL with GGI
 * Requires mmlib and libc for MMURTL as well
 * as the vga branch.
 *
 * Same as mmtest1.c but with optimizations.
 */

#include <mmlib.h>
#include <stdlib.h>
#include <graphics.h>

struct ModeInfoBlock vmib;
extern struct ModeInfoBlock * MIB;
extern struct status status;
extern unsigned int * ylookup;

int main(void)
{
	int gdriver = DETECT;
	int gmode;
	int errorcode;
	unsigned int blue = (BLUE << 24) + (BLUE << 16) + (BLUE << 8) + BLUE;

	SetVidMode(3);

	initgraph(&gdriver, &gmode, "");

	unsigned int *fb = (unsigned int *) status.framebuffer;

	for(int counter = 0; counter <= 16000; counter++)
		fb[counter] = blue;

	for(int counter = 0; counter <= status.xres; counter++)
	{
		putpixel(counter, 0, counter&0x000F);
		putpixel(counter, status.yres, counter&0x000F);
	}
	for(int counter = 0; counter <= status.yres; counter++)
	{
		putpixel(0, counter, counter&0x000F);
		putpixel(status.xres, counter, counter&0x000F);
	}

	for(int counter = 0; counter <= 64000; counter++)
		putpixel(rand() % status.xres, rand() %status.yres, rand() %16);

	Sleep(500);

	closegraph();

	SetVidMode(0);
	ClrScr();

	return 0;
}
