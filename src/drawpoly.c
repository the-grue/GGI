#include <graphics.h>

void drawpoly(int numpoints, int *polypoints)
{
	moveto(polypoints[0], polypoints[1]);

	for(int counter = 0; counter < numpoints - 1; counter++)
	{
		polypoints = polypoints + 2;
		lineto(polypoints[0], polypoints[1]);
	}
}
