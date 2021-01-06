/* Tests line drawing on MMURTL
 * Clears the screen and draws 100 random
 * lines in cycling colors with .2 second
 * delay between lines.
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

	unsigned int *clrblast = (unsigned int *) status.framebuffer;

	unsigned int white = (WHITE << 24) + (WHITE << 16) + (WHITE << 8) + WHITE;

	for(int counter = 0; counter <= 16000; counter++)
		clrblast[counter] = white;


	for(int counter = 0; counter < 100; counter++) {
		setcolor(counter & 0x000F);

		line(rand() % status.xres,
		     rand() % status.yres,
		     rand() % status.xres,
		     rand() % status.yres);
		Sleep(20);
	}

	Sleep(500);

	closegraph();

	SetVidMode(0);
	ClrScr();

	return 0;
}
