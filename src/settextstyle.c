#include <graphics.h>

extern struct textsettingstype textsettingstype;

void settextstyle(int font, int direction, int charsize)
{
	textsettingstype.font = font;
	textsettingstype.direction = direction;
	textsettingstype.charsize = charsize;
}
