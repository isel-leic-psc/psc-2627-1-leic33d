#include <stdio.h>

char long_line[100];
int long_size;

char current_line[100];
int current_size;

void copy_line(char dst[], char src[], size_t src_size)
{
	int i = 0;
	while (i < src_size) {
		dst[i] = src[i];
		i++;
	}
}

void print_line(char line[], size_t line_size)
{
	int i = 0;
	while (i < line_size) {
		putchar(line[i]);
		i++;
	}
}

int main()
{
	int c = getchar();
	while (c >= 0) {
		if (c == '\n') {
			if (current_size > long_size) {
				copy_line(long_line, current_line, current_size);
				long_size = current_size;
			}
			current_size = 0;
		}
		else {
			current_line[current_size++] = c;
		}
//		putchar(c);
		c = getchar();
	}
	
	print_line(long_line, long_size);
	putchar('\n');
}
