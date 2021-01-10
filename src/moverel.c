#include <graphics.h>

extern unsigned int cp_x;
extern unsigned int cp_y;
extern struct status status;

void moverel(int dx, int dy)
{
	cp_x += dx;
	cp_y += dy;

	if(cp_x < 0)
		cp_x = 0;
	if(cp_y < 0)
		cp_y = 0;
	if(cp_x > status.xres)
		cp_x = status.xres;
	if(cp_y > status.yres)
		cp_y = status.yres;
}
