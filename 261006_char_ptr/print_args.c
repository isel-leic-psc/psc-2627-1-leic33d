#include <stdio.h>

int main(char argc, char *argv[])
{
	for (size_t i = 0; i < argc; ++i)
		printf("argv[%ld] = %s\n", i, argv[i]);
}
