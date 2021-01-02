#include <graphics.h>

extern struct palettetype palettetype;

void getpalette(struct palettetype *palette)
{
	palette->size = palettetype.size;
	for(int counter = 0; counter < MAXCOLORS + 1; counter++)
		palette->colors[counter] = palettetype.colors[counter];
}
