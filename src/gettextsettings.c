#include <graphics.h>

extern struct textsettingstype textsettingstype;

void gettextsettings(struct textsettingstype *texttypeinfo)
{
	texttypeinfo->font = textsettingstype.font;	
	texttypeinfo->direction = textsettingstype.direction;	
	texttypeinfo->charsize = textsettingstype.charsize;	
	texttypeinfo->horiz = textsettingstype.horiz;	
	texttypeinfo->vert = textsettingstype.vert;	
}
