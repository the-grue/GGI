#include <graphics.h>

char * errmsg[] = {
	"No error",
	"(GGI) graphics not installed (use initgraph)",
	"Graphics hardware not detected",
	"Device driver file not found",
	"Invalid device driver file",
	"Not enough memory to load driver",
	"Out of memory in scan fill",
	"Out of memory in flood fill",
	"Font file not found",
	"Not enough memory to load font",
	"Invalid graphics mode for selected driver",
	"Graphics error",
	"Graphics I/O error",
	"Invalid font file",
	"Invalid font number",
	"Invalid device number",
	"",
	"",
	"Invalid version of file"
};

char * grapherrormsg(int errorcode)
{
	return errmsg[errorcode < 0 ? -errorcode : errorcode];
}
