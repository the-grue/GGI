#include <graphics.h>

extern unsigned char currcolor;

void circle(int x, int y, int radius)
{
	int xm = -radius, ym = 0, err = 2 - 2 * radius;

	do {
		putpixel(x-xm, y+ym, currcolor);
		putpixel(x-ym, y-xm, currcolor);
		putpixel(x+xm, y-ym, currcolor);
		putpixel(x+ym, y+xm, currcolor);
		radius = err;
		if(radius <= ym)
			err += ++ym * 2 + 1;
		if(radius > xm || err > ym)
			err += ++xm * 2 + 1;
	} while (xm < 0);
}
