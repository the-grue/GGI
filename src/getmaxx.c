#include <graphics.h>

extern struct status status;
extern int ingraphics;

int getmaxx(void)
{
	if(ingraphics)
		return status.xres;
	else
		status.stat = grError;
	return 0;
}
