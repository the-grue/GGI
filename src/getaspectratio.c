#include <graphics.h>

extern struct status status;

void getaspectratio(int *xasp, int *yasp)
{
	*yasp = 10000;
	*xasp = status.aspec;
}
