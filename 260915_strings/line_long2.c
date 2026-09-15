#include <stdio.h>

char long_line[100];


char current_line[100];
int current_size;

void copy_line(char dst[], char src[])
{
	int i = 0;
	while (src[i] != 0) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void print_line(char line[])
{
	int i = 0;
	while (line[i] != 0) {
		putchar(line[i]);
		i++;
	}
}

size_t line_length(char line[]) {
	size_t size = 0;
	while (line[size] != 0)
		size++;
	return size;
}


int main()
{
	int c = getchar();
	while (c >= 0) {
		if (c == '\n') {
			if (current_size > line_length(long_line)) {
				copy_line(long_line, current_line);
			}
			current_size = 0;
		}
		else {
			current_line[current_size++] = c;
		}
//		putchar(c);
		c = getchar();
	}
	
	print_line(long_line);
	putchar('\n');
}
