#include <graphics.h>

extern struct status status;
extern struct current_gmode current_gmode;
extern int ingraphics;

void getmoderange(int graphdriver, int *lomode, int *himode)
{
	if(graphdriver != -1 && graphdriver != VGA256 && graphdriver != VESA256)
	{
		*lomode = -1;
		*himode = -1;
		status.stat = grInvalidDriver;
	}	
	else if(ingraphics && graphdriver == -1)
	{
		*lomode = current_gmode.gmode;
		*himode = current_gmode.gmode;
	}
	else if(graphdriver == VGA256)
	{
		*lomode = RES320x200;
		*himode = RES320x200;
	}
	else if(graphdriver == VESA256)
	{
		*lomode = RES640x480;
		*himode = RES1280x1024;
	}
	else
	{
		*lomode = -1;
		*himode = -1;
		status.stat = grInvalidDriver;
	}
}
