#include <graphics.h>

extern struct textsettingstype textsettingstype;

int textheight(char *textstring)
{
	if(textsettingstype.font == DEFAULT_FONT)
		return (textsettingstype.charsize << 3);
	else
		return 0;
}
