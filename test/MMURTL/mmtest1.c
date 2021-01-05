/* Tests pixel plotting on MMURTL with GGI
 * Requires mmlib and libc for MMURTL as well
 * as the vga branch.
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

	SetVidMode(3);

	initgraph(&gdriver, &gmode, "");

	char *fb = status.framebuffer;

	for(int counter = 0; counter <= 64000; counter++)
		fb[counter] = BLUE;


	for(int counter = 0; counter <= status.xres; counter++)
	{
		putpixel(counter, 0, counter%16);
		putpixel(counter, status.yres, counter%16);
	}
	for(int counter = 0; counter <= status.yres; counter++)
	{
		putpixel(0, counter, counter%16);
		putpixel(status.xres, counter, counter%16);
	}

	for(int counter = 0; counter <= 64000; counter++)
		putpixel(rand() % status.xres, rand() %status.yres, rand() %16);

	Sleep(500);

	closegraph();

	SetVidMode(0);
	ClrScr();

	return 0;
}
