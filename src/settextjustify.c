#include <graphics.h>

extern struct status status;
extern struct textsettingstype textsettingstype;

void settextjustify(int horiz, int vert)
{
	if(horiz < LEFT_TEXT || vert < BOTTOM_TEXT || 
	   horiz > RIGHT_TEXT || vert > TOP_TEXT)
	{
		status.stat = grError;
		return;
	}

	textsettingstype.horiz = horiz;
	textsettingstype.vert = vert;
}
