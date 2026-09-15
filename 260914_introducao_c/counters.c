#include <stdio.h>
#include <ctype.h>

/*
 * Contar caracteres
 * Contar linhas
 * Contar palavras
 * Contar digitos
 * Contar digitos individualmente 
 */
int main()
{
	int char_counter = 0;
	int line_counter = 0;
	int word_counter = 0;
	int digit_counter = 0;
	bool in_word = false;
	
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
		if (isdigit(c))
			digit_counter++;
		putchar(c);
		c = getchar();
	}
	printf("character counter = %d\nline counter = %d\n"
		   "word_counter = %d\ndigit_counter = %d\n",
		char_counter, line_counter, word_counter, digit_counter);
}
