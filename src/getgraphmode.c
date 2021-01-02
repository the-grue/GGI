#include <graphics.h>

extern int ingraphics;
extern struct current_gmode current_gmode;
extern struct status status;

int getgraphmode(void)
{
	if(ingraphics)
		return current_gmode.gmode;
	else
		status.stat = grError;
	return 0;
}
