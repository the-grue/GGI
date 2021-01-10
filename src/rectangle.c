#include <graphics.h>

void rectangle(int left, int top, int right, int bottom)
{
	line(left, top, right, top);
	line(left, bottom, right, bottom);
	line(left, top, left, bottom);
	line(right, top, right, bottom);
}
