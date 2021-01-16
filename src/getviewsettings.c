#include <graphics.h>

extern struct viewporttype viewporttype;

void getviewsettings(struct viewporttype *viewport)
{
	viewport->left = viewporttype.left;
	viewport->top = viewporttype.top;
	viewport->right = viewporttype.right;
	viewport->bottom = viewporttype.bottom;
	viewport->clip = viewporttype.clip;
}
