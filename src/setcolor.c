#include <graphics.h>

extern unsigned char currcolor;
extern struct status status;

void setcolor(int color)
{
	if(color < 0 || color > MAXCOLORS)
	{
		status.stat = grError;
		return;
	}

	currcolor = (unsigned char) color;
}
