#include <graphics.h>

void getimage(int left, int top, int right, int bottom, void *bitmap)
{
	unsigned short width, height;
	int swap;
	unsigned char *bits = (unsigned char *) bitmap;
	unsigned short *hw = (unsigned short *) bitmap;

	if(right < left)
	{
		swap = left;
		left = right;
		right = swap;
	}

	if(bottom < top)
	{
		swap = top;
		top = bottom;
		bottom = swap;
	}

	width = (right - left + 1);
	height = (bottom - top + 1);

	bits += 4;

	for(int w = left; w <= right; w++)
		for(int h = top; h <= bottom; h++)
		{
			*bits = getpixel(w, h);
			bits++;
		}

	*hw = width;
	hw++;
	*hw = height;
}
