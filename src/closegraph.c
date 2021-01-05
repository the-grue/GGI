#include <graphics.h>
#include <stdlib.h>

extern unsigned int * ylookup;

void closegraph(void)
{
	if(ylookup != NULL)
		free(ylookup);
}
