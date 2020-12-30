/* Tests some color functions
 * functions getbkcolor() getcolor() setbkcolor() setcolor()
 *
 * This test can be compiled with:
 * 	gcc -o t3 t3.c ../src/getbkcolor.c ../src/getcolor.c \
 * 	../src/setcolor.c ../src/setbkcolor.c ../src/graphresult.c \
 * 	../src/grapherrormsg.c -I../include
 */

#include <stdio.h>
#include <graphics.h>

struct palettetype palettetype;
struct status status;
unsigned char currcolor;

int main(void)
{
	for(int counter = 0; counter <= MAXCOLORS; counter++)
		palettetype.colors[counter] = (unsigned char) counter;
	status.stat = 0;
	
	printf("Setting color with setcolor()\n");
	setcolor(BLUE);
	printf("%s\n", grapherrormsg(graphresult()));
	printf("Setting bkcolor with setbkcolor()\n");
	setbkcolor(WHITE);
	printf("%s\n", grapherrormsg(graphresult()));

	printf("Values returned should be 1, 15\n");
	printf("color   = %d\n", getcolor());
	printf("bkcolor = %d\n", getbkcolor());

	printf("Bounds check negative...\n");
	setcolor(-5);
	printf("%s\n", grapherrormsg(graphresult()));
	setbkcolor(-5);
	printf("%s\n", grapherrormsg(graphresult()));

	printf("Bounds check greater than MAXCOLORS...\n");
	setcolor(MAXCOLORS+5);
	printf("%s\n", grapherrormsg(graphresult()));
	setbkcolor(MAXCOLORS+5);
	printf("%s\n", grapherrormsg(graphresult()));

	return 0;
}
