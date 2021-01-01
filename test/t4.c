/* Tests initgraph and detectgraph
 *
 * This test can be compiled with:
 * 	gcc -o t4 t4.c -I../include ../src/initgraph.c ../src/graphresult.c ../src/grapherrormsg.c
 */

#include <stdio.h>
#include <graphics.h>

struct ModeInfoBlock vmib;
extern struct ModeInfoBlock * MIB;
extern struct status status;

int main(void)
{
	int gdriver = DETECT;
	int gmode;
	int errorcode;

	printf("Testing initgraph() with DETECT...\n");
	initgraph(&gdriver, &gmode, "");
	printf("gdriver = %d, gmode = %d\n", gdriver, gmode);
	printf("%s\n",grapherrormsg(graphresult()));

	printf("Testing initgraph() with VGA256...\n");
	gdriver = VGA256;
	initgraph(&gdriver, &gmode, "");
	printf("gdriver = %d, gmode = %d\n", gdriver, gmode);
	printf("%s\n",grapherrormsg(graphresult()));

	printf("Testing initgraph() with VESA256 to fail...\n");
	gdriver = VESA256;
	initgraph(&gdriver, &gmode, "");
	printf("gdriver = %d, gmode = %d\n", gdriver, gmode);
	printf("%s\n",grapherrormsg(graphresult()));

	printf("Testing initgraph() with VESA256 to pass...\n");
	gdriver = VESA256;
	vmib.ModeAttributes = 0xFF;
	vmib.XResolution = 1024;
	vmib.YResolution = 768;
	vmib.BytesPerScanLine = 1024;
	vmib.PhysBasePtr = 0xDEADC0DE;
	initgraph(&gdriver, &gmode, (char *) &vmib);
	printf("gdriver = %d, gmode = %d\n", gdriver, gmode);
	printf("%s\n",grapherrormsg(graphresult()));

	printf("Validate MIB:\n");
	printf("\tXResolution = %d\n", MIB->XResolution);
	printf("\tYResolution = %d\n", MIB->YResolution);
	printf("\tBytesPerScanLine = %d\n", MIB->BytesPerScanLine);
	printf("\tPhysBasePtr = %p\n", (void *) MIB->PhysBasePtr);

	printf("Validate status:\n");
	printf("\tStat = %d\n", status.stat);
	printf("\txres = %d\n", status.xres);
	printf("\tyres = %d\n", status.yres);
	printf("\txefres = %d\n", status.xefres);
	printf("\tyefres = %d\n", status.yefres);
	printf("\txinch = %d\n", status.xinch);
	printf("\tyinch = %d\n", status.yinch);
	printf("\taspec = %d\n", status.aspec);
	printf("\tscanlinebytes = %d\n", status.scanlinebytes);
	printf("\tframebuffer = %p\n", (void *) status.framebuffer);

	return 0;
}
