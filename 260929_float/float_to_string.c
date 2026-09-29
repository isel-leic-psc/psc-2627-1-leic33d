#include <stdio.h>

int main()
{
	float f = 2.898353248;
	
	unsigned int l = *(int *)&f;
	
	unsigned long w = 1 << 23;
		      w = w + (l & ((1 << 23) - 1)); 	/* máscara com 23 uns */

	unsigned exp = (l >> 23) & ((1 << 8) - 1);
	if (exp > 127)
		w = w << exp - 127;
	else if (exp < 127)
		w = w >> exp - 127;
	
	w = w * 1000000;
	
	w = w >> 23;
	
	char buffer[20];
	
	int index = 0;
	while (w > 0) {
		buffer[index++] = w % 10 + '0';
		w = w / 10;
	}
	buffer[index] = 0;
	
	int i = index - 1;
	int j = 0;
	while (j < i) {
		char tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		j++;
		i--;
	}
	
	printf("%s\n", buffer);
}

	
