#include <stddef.h>
#include <stdio.h>

char *a[] = {
	"1234", "abcd"
};

/*
char a[][5] = {
	"1234", "abcd"
};
*/
/*
void print(char *ptr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		printf("%c", ptr[i]);
	putchar('\n');
}
*/

void print(char *array[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
		printf("%s\n", array[i]);
}

int main() {
	print(a, 2);

	char *tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	
	putchar('\n');
	
	print(a, 2);
}
