#include <graphics.h>

extern struct status status;
extern int ingraphics;

int getmaxy(void)
{
	if(ingraphics)
		return status.yres;
	else
		status.stat = grError;
	return 0;
}
