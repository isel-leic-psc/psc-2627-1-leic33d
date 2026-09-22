#include <stdio.h>

int main()
{
	int char_counter = 0;
//	int c = getchar();
	while ((c = getchar()) >= 0) {
		char_counter++;
		putchar(c);
//		c = getchar();
	}
	printf("character counter = %d\n", char_counter);
}
