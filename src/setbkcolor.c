#include <graphics.h>

extern struct palettetype palettetype;
extern struct status status;

void setbkcolor(int color)
{
	if(color < 0 || color > MAXCOLORS)
	{
		status.stat = grError;
		return;
	}

	palettetype.colors[0] = palettetype.colors[(unsigned char) color];
}
