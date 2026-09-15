#include <stdio.h>
#include <ctype.h>

/*
 * Contar caracteres
 * Contar linhas
 * Contar palavras
 * Contar digitos
 * Contar digitos individualmente 
 */
 
int digit_counter[10];

int main()
{
	int char_counter = 0;
	int line_counter = 0;
	int word_counter = 0;
	int digit_counter = 0;
	bool in_word = false;
	int digit_counters[10] = {0};
	
	int c = getchar();
	while (c >= 0) {
		char_counter++;
		if (c == '\n')
			line_counter++;
		if (isalnum(c)) {
			if (!in_word) {
				in_word = true;
				word_counter++;
			}
		}
		else {
			in_word = false;
		}
		if (isdigit(c)) {	// if (c >= '0' && c <= '9')
			digit_counter++;
			digit_counters[c - '0']++;
		}
		putchar(c);
		c = getchar();
	}
	printf("character counter = %d\nline counter = %d\n"
		   "word_counter = %d\ndigit_counter = %d\n",
		char_counter, line_counter, word_counter, digit_counter);
	int i = 0;
	while (i < 10) {
		printf("digit \'%d\' = %d\n", i, digit_counters[i]);
		i++;
	}
}
