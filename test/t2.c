/* Tests some get functions
 * functions getarccoords()
 *
 * This test can be compiled with:
 * 	gcc -o t2 t2.c ../src/getarccoords.c ../src/getaspectratio.c -I../include
 */

#include <stdio.h>
#include <graphics.h>

struct arccoordstype arccoordstype;
struct status status;

int main(void)
{
	struct arccoordstype arccoords;
	int xasp, yasp;

	printf("Setting arccoordstype values...\n");
	arccoordstype.x = 50;
	arccoordstype.y = 40;
	arccoordstype.xstart = 90;
	arccoordstype.ystart = 80;
	arccoordstype.xend = 5;
	arccoordstype.yend = 0;
	printf("Setting aspect ratio...\n");
	status.aspec = 4500;

	printf("Testing getarccoords()...\n");
	getarccoords(&arccoords);

	printf("Values returned should be 50, 40, 90, 80, 5, 0\n");
	printf("x      = %d\n", arccoords.x);
	printf("y      = %d\n", arccoords.y);
	printf("xstart = %d\n", arccoords.xstart);
	printf("ystart = %d\n", arccoords.ystart);
	printf("xend   = %d\n", arccoords.xend);
	printf("yend   = %d\n", arccoords.yend);

	printf("Testing getaspectratio()...\n");
	getaspectratio(&xasp, &yasp);

	printf("Values returned should be 4500, 10000\n");
	printf("xasp = %d\n", xasp);
	printf("yasp = %d\n", yasp);

	return 0;
}
