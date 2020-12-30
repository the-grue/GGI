/* Tests error message and status.stat for
 * functions graphresult() and grapherrormsg()
 *
 * This test can be compiled with:
 * 	gcc -o t1 t1.c ../src/grapherrormsg.c ../src/graphresult.c -I../include
 */

#include <stdio.h>
#include <graphics.h>

struct status status;

int main(void)
{
	printf("Testing error messages with grapherrormsg()...\n");
	for(int counter=0; counter<19; counter++) {
		printf("%d is %s\n", counter, grapherrormsg(counter));
	}

	printf("Testing error messages with grapherrormsg(graphresult())...\n");
	for(int counter=0; counter>-19; counter--) {
		status.stat = counter;
		printf("%d is %s\n", counter, grapherrormsg(graphresult()));
	}

	printf("graphresult() should now return 0 and it returns %d.\n", graphresult());

	return graphresult();
}
