#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define ARRAYS_SIZE(a)  sizeof a / sizeof a[0]

int a[] = {1, 4, 3, 20, 4, 20 , 65, 2 , 5};

void print_int(int array[], size_t array_size) {
	for (size_t i = 0; i < array_size; ++i)
		printf("[%ld] = %d\n", i, array[i]);
}

void sort(void *array, size_t elem_size, size_t array_size,
		int (*cmp)(void *, void *));

int cmp_int(void *a, void *b)
{
	int *ap = a;
	int *bp = b;
	return *ap - *bp;
}

int main() {
	print_int(a, ARRAYS_SIZE(a));
	putchar('\n');
	sort(a, sizeof a[0], ARRAYS_SIZE(a), cmp_int); 
	print_int(a, ARRAYS_SIZE(a)); 
}
