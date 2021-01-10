#include <graphics.h>

extern unsigned int cp_x;
extern unsigned int cp_y;
extern struct status status;

void moveto(int x, int y)
{
	cp_x = x;
	cp_y = y;

	if(cp_x < 0)
		cp_x = 0;
	if(cp_y < 0)
		cp_y = 0;
	if(cp_x > status.xres)
		cp_x = status.xres;
	if(cp_y > status.yres)
		cp_y = status.yres;
}
