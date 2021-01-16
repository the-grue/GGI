#include <graphics.h>

extern unsigned int cp_x, cp_y;
extern struct palettetype palettetype;
extern struct viewporttype viewporttype;

void cleardevice(void)
{
	viewporttype.left = 0;
	viewporttype.top = 0;
	viewporttype.right = getmaxx();
	viewporttype.bottom = getmaxy();

	clearviewport();
}

void clearviewport(void)
{
	int width, height;

	for(height = viewporttype.top; height <= viewporttype.bottom; height++)
		for(width = viewporttype.left; width <= viewporttype.right; width++)
			putpixel(width, height, palettetype.colors[0]);

	cp_x = viewporttype.left;
	cp_y = viewporttype.top;

}
