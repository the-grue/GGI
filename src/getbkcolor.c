#include <graphics.h>

extern struct palettetype palettetype;

int getbkcolor(void)
{
	return (int) palettetype.colors[0];
}
