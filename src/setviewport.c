#include <graphics.h>

extern struct viewporttype viewporttype;
extern unsigned int cp_x, cp_y;
extern struct status status;

void setviewport(int left, int top, int right, int bottom, int clip)
{
	int swap;

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

	if(left < 0 || top < 0 || right > getmaxx() || bottom > getmaxy())
	{
		status.stat = grError;
		return;
	}

	viewporttype.left = left;
	viewporttype.top = top;
	viewporttype.right = right;
	viewporttype.bottom = bottom;
	viewporttype.clip = clip;

	cp_x = left;
	cp_y = top;
}
