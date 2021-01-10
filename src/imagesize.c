#include <graphics.h>

unsigned int imagesize(int left, int top, int right, int bottom)
{
	int swap;
	//  Size of image is based on rectangle size plus
	//  two words for width and height which are stored
	//  as the first two words in the image
	
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
	
	return ((right - left + 1) * (bottom - top + 1) + 4);
}
