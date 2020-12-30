#include <graphics.h>

extern struct arccoordstype arccoordstype;

void getarccoords(struct arccoordstype *arccoords)
{
	arccoords->x = arccoordstype.x;
	arccoords->y = arccoordstype.y;
	arccoords->xstart = arccoordstype.xstart;
	arccoords->ystart = arccoordstype.ystart;
	arccoords->xend = arccoordstype.xend;
	arccoords->yend = arccoordstype.yend;
}
