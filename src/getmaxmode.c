#include <graphics.h>

extern struct status status;
extern struct current_gmode current_gmode;
extern int ingraphics;

int getmaxmode(void)
{
	if(ingraphics)
		return current_gmode.gmode;
	else
		status.stat = grError;
	return 0;
}
