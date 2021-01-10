#include <graphics.h>

void putimage(int left, int top, void *bitmap, int op)
{
	unsigned short width, height;
	unsigned char *bits = (unsigned char *) bitmap;
	unsigned short *hw = (unsigned short *) bitmap;
	unsigned int masked;

	width = *hw++;
	height = *hw;

	bits += 4;

	if(op == COPY_PUT)
	{
		for(int w = left; w < left + width; w++)
			for(int h = top; h < top + height; h++)
			{
				putpixel(w, h, *bits++);
			}
	}
	else if(op == XOR_PUT)
	{
		for(int w = left; w < left + width; w++)
			for(int h = top; h < top + height; h++)
			{
				putpixel(w, h, getpixel(w, h) ^ *bits++);
			}
	}
	else if(op == OR_PUT)
	{
		for(int w = left; w < left + width; w++)
			for(int h = top; h < top + height; h++)
			{
				putpixel(w, h, getpixel(w, h) | *bits++);
			}
	}
	else if(op == AND_PUT)
	{
		for(int w = left; w < left + width; w++)
			for(int h = top; h < top + height; h++)
			{
				putpixel(w, h, getpixel(w, h) & *bits++);
			}
	}
	else if(op == AND_PUT)
	{
		for(int w = left; w < left + width; w++)
			for(int h = top; h < top + height; h++)
			{
				putpixel(w, h, ! *bits++);
			}
	}
}
