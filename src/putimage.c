#include <graphics.h>

void putimage(int left, int top, void *bitmap, int op)
{
	unsigned short width, height;
	unsigned char *bits = (unsigned char *) bitmap;
	unsigned short *hw = (unsigned short *) bitmap;

	width = *hw++;
	height = *hw;

	bits += 4;

	for(int w = left; w < left + width; w++)
		for(int h = top; h < top + height; h++)
		{
			putpixel(w, h, *bits++);
		}
}
