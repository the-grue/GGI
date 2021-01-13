#include <graphics.h>

extern struct fillsettingstype fillsettingstype;
extern struct palettetype palettetype;
extern char fill_blocks[12][8];
extern unsigned char currcolor;

void dobarpattern(int left, int top, int right, int bottom);	

void bar(int left, int top, int right, int bottom)
{
	dobarpattern(left, top, right, bottom);	
}

void dobarpattern(int left, int top, int right, int bottom)
{
	int width, height, swap;

	if(left > right)
	{
		swap = left;
		left = right;
		right = swap;	
	}
	if(top > bottom)
	{
		swap = top;
		top = bottom;
		bottom = swap;	
	}

	for(width = left; width <= right; width++)
		for(height = top; height <= bottom; height++)
			if(((fill_blocks[fillsettingstype.pattern][height&7]) >> (width&7)) & 0x1)
				putpixel(width, height, fillsettingstype.color);
			else
				putpixel(width, height, currcolor);
}
