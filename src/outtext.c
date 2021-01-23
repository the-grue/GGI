#include <graphics.h>
#include <stdlib.h>

extern unsigned char *systemfont;
extern struct status status;
extern unsigned int cp_x, cp_y;
extern unsigned char currcolor;

void outtext(char *textstring)
{
	unsigned char ch;

	if(systemfont == NULL)
	{
		status.stat = grInvalidFont;	
		return;
	}

	while((ch = *textstring++) != '\0')
	{
		for(int height = cp_y, hi = 0; hi < 8; height++, hi++)
		{
			for(int width = cp_x, lo = 7; lo >= 0; width++, lo--)
			{
				if(((systemfont[(ch * 8) + hi] >> lo) & 0x1) == 1)
					putpixel(width, height, currcolor);
			}
		}

		cp_x = cp_x + 8;
	}
}

void outtextxy(int x, int y, char *textstring)
{
	int savex, savey;

	savex = cp_x;
	cp_x = x;
	savey = cp_y;
	cp_y = y;

	outtext(textstring);

	cp_x = savex;
	cp_y = savey;
}
