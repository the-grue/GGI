#include <graphics.h>

extern unsigned int cp_x;
extern unsigned int cp_y;
extern struct status status;

void linerel(int dx, int dy)
{
	line(cp_x, cp_y, cp_x + dx, cp_y + dy);

	moverel(dx, dy);
}
