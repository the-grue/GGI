#include <stdlib.h>
#include <graphics.h>

extern unsigned short line_patterns[];
extern struct linesettingstype linesettingstype;

void line(int x1, int y1, int x2, int y2)
{
	int dx, sx, dy, sy, err, e2;
	int counter = 0;
	int color = getcolor();

	dx = abs(x2 - x1);
	sx = x1 < x2 ? 1 : -1;
	dy = -abs(y2 - y1);
	sy = y1 < y2 ? 1 : -1;
	err = dx + dy;

	for(;;)
	{
		if((linesettingstype.linestyle == SOLID_LINE) ||
		   ((line_patterns[linesettingstype.linestyle] >> (counter & 0xF)) & 0x1))
		{
			if(linesettingstype.thickness == THICK_WIDTH)
			{
				putpixel(x1-1, y1-1, color); 
				putpixel(x1-1, y1, color); 
				putpixel(x1-1, y1+1, color); 
				putpixel(x1, y1-1, color); 
				putpixel(x1, y1+1, color); 
				putpixel(x1+1, y1+1, color); 
				putpixel(x1+1, y1, color); 
				putpixel(x1+1, y1-1, color); 
			}
			putpixel(x1, y1, color); 
		}

		if(x1 == x2 && y1 == y2)
			break;

		e2 = (err << 1);

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

		counter++;
	}
}
