#include <graphics.h>

extern unsigned int cp_x;
extern unsigned int cp_y;
extern struct status status;

void lineto(int x, int y)
{
	line(cp_x, cp_y, x, y);

	moveto(x, y);
}
