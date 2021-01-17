// Test textheight and textwidth functions
// gcc -o t7 -I../include t7.c ../src/textheight.c ../src/textwidth.c
#include <graphics.h>
#include <stdio.h>

struct textsettingstype textsettingstype;

int main(void)
{
	char x[] = "This is a test!";
	int y;

	textsettingstype.font = DEFAULT_FONT;
	textsettingstype.direction = HORIZ_DIR;
	textsettingstype.horiz = LEFT_TEXT;
	textsettingstype.vert = TOP_TEXT;

	printf("Enter character size multiplier: ");
	scanf("%d", &y);

	textsettingstype.charsize = y;

	printf("String is '%s' and multiplier is %d\n", x, y);
	printf("String height is %d and string width is %d.\n", textheight(x), textwidth(x));
}
