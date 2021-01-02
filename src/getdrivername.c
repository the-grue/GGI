#include <graphics.h>

extern int ingraphics;
extern struct current_gmode current_gmode;
extern struct status status;

char * drivernames[] = {
	"VGA256",
	"VESA256",
};

char * getdrivername(void)
{
	if(ingraphics)
		return drivernames[current_gmode.gdriver];
	else
		status.stat = grError;
	return 0;
}
