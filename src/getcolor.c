#include <graphics.h>

extern unsigned char currcolor;
extern struct palettetype palettetype;

int getcolor(void)
{
	return (int) palettetype.colors[currcolor];
}
