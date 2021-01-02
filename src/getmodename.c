#include <graphics.h>

extern int ingraphics;
extern struct current_gmode current_gmode;
extern struct status status;

char * modenames[] = {
	"VGA 320x200x256",
	"VESA 640x480x256",
	"VESA 800x600x256",
	"VESA 1024x768x256",
	"VESA 1280x1024x256"
};

char * getmodename(int mode_number)
{
	if(mode_number < 0 || mode_number > 4)
		status.stat = grInvalidMode;
	else
		return modenames[mode_number];
	return 0;
}
