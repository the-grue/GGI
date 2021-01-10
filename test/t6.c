// Test imagesize function
// gcc -o t6 -I../include t6.c ../src/imagesize.c
#include <graphics.h>
#include <stdio.h>

int main(void)
{
	int x1, y1, x2, y2;

	printf("Enter x1: ");
	scanf("%d", &x1);
	printf("Enter x2: ");
	scanf("%d", &x2);
	printf("Enter y1: ");
	scanf("%d", &y1);
	printf("Enter y2: ");
	scanf("%d", &y2);

	printf("Imagesize for %d, %d x %d, %d is %d\n",
			x1, y1, x2, y2, imagesize(x1, y1, x2, y2));
}
