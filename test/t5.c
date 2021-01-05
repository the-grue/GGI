/* Tests initgraph and detectgraph
 *
 * This test can be compiled with:
 * 	gcc -o t5 t5.c -I../include ../src/initgraph.c ../src/graphresult.c ../src/grapherrormsg.c ../src/closegraph.c
 */

#include <stdio.h>
#include <string.h>
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

	printf("Testing initgraph() with DETECT...\n");
	initgraph(&gdriver, &gmode, "");
	printf("gdriver = %d, gmode = %d\n", gdriver, gmode);
	printf("%s\n",grapherrormsg(graphresult()));

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

	printf("Print lookup values:\n");
	for(int counter = 0; counter <= status.yres; counter++)
	{
		if(counter % 8 == 0)
			printf("\n");
		printf("%d\t", ylookup[counter]);
	}

	printf("\n");

	closegraph();

	return 0;
}
