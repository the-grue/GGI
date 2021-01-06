#include <graphics.h>

#ifdef MMURTL
int abs(int x) {
        return (x < 0 ? -x : x);
}
#endif

void line(int x1, int y1, int x2, int y2)
{
	int dx, sx, dy, sy, err, e2;
	int color = getcolor();

	dx = abs(x2 - x1);
	sx = x1 < x2 ? 1 : -1;
	dy = -abs(y2 - y1);
	sy = y1 < y2 ? 1 : -1;
	err = dx + dy;

	for(;;)
	{
		putpixel(x1, y1, color); 

		if(x1 == x2 && y1 == y2)
			break;

		e2 = 2 * err;

		if(e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}

		if(e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
