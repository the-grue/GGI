#include <graphics.h>

extern unsigned char currcolor;
extern struct linesettingstype linesettingstype;

void circle(int x, int y, int radius)
{
	int xm = -radius, ym = 0, err = 2 - 2 * radius;

	do {
		if(linesettingstype.thickness == THICK_WIDTH)
		{
			putpixel(x-xm-1, y+ym-1, currcolor);
			putpixel(x-xm-1, y+ym, currcolor);
			putpixel(x-xm-1, y+ym+1, currcolor);
			putpixel(x-xm, y+ym-1, currcolor);
			putpixel(x-xm, y+ym+1, currcolor);
			putpixel(x-xm+1, y+ym+1, currcolor);
			putpixel(x-xm+1, y+ym, currcolor);
			putpixel(x-xm+1, y+ym-1, currcolor);

			putpixel(x-xm-1, y-ym-1, currcolor);
			putpixel(x-xm-1, y-ym, currcolor);
			putpixel(x-xm-1, y-ym+1, currcolor);
			putpixel(x-xm, y-ym-1, currcolor);
			putpixel(x-xm, y-ym+1, currcolor);
			putpixel(x-xm+1, y-ym+1, currcolor);
			putpixel(x-xm+1, y-ym, currcolor);
			putpixel(x-xm+1, y-ym-1, currcolor);

			putpixel(x+xm-1, y-ym-1, currcolor);
			putpixel(x+xm-1, y-ym, currcolor);
			putpixel(x+xm-1, y-ym+1, currcolor);
			putpixel(x+xm, y-ym-1, currcolor);
			putpixel(x+xm, y-ym+1, currcolor);
			putpixel(x+xm+1, y-ym+1, currcolor);
			putpixel(x+xm+1, y-ym, currcolor);
			putpixel(x+xm+1, y-ym-1, currcolor);

			putpixel(x+xm-1, y+ym-1, currcolor);
			putpixel(x+xm-1, y+ym, currcolor);
			putpixel(x+xm-1, y+ym+1, currcolor);
			putpixel(x+xm, y+ym-1, currcolor);
			putpixel(x+xm, y+ym+1, currcolor);
			putpixel(x+xm+1, y+ym+1, currcolor);
			putpixel(x+xm+1, y+ym, currcolor);
			putpixel(x+xm+1, y+ym-1, currcolor);
		}
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
