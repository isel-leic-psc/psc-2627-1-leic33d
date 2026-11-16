#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, size_t elem_size)
{
	char tmp[elem_size];
	memcpy(tmp, a, elem_size);
	memcpy(a, b, elem_size);
	memcpy(b, tmp, elem_size);
}

void sort(void *array, size_t elem_size, size_t array_size,
		int (*cmp)(void *, void *));
/*
{
	for (size_t i = 0; i < array_size - 1; ++i)
		for (size_t j = 0; j < array_size - 1 - i; ++j)
			if (cmp((char *)array + j * elem_size, (char *)array + (j + 1) * elem_size) > 0)
				swap((char *)array + j * elem_size, (char *)array + (j + 1) * elem_size, elem_size);
}
*/
