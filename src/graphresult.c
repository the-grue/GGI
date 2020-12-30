#include <graphics.h>

extern struct status status;

int graphresult(void)
{
	int tmp = (int) status.stat;

	status.stat = 0;

	return tmp;
}
