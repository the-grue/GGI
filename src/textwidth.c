#include <graphics.h>
#include <string.h>

extern struct textsettingstype textsettingstype;

int textwidth(char *textstring)
{
	if(textsettingstype.font == DEFAULT_FONT)
		return ((textsettingstype.charsize << 3) * strlen(textstring));
	else
		return 0;
}
