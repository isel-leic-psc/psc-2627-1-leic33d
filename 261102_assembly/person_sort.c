#include <stdio.h>
#include <string.h>

#define ARRAYS_SIZE(a)  sizeof a / sizeof a[0]

struct person {
	char name[30];
	int score;
	char age;
	int number;
};

struct person people[] = {
	{.name = "Ana", .number = 50456, .age = 20},
	{"Rui", 0, 79, 50234},
	{"Luis", 0, 87, 55464}
};

void person_swap(struct person *a, struct person *b) {
	struct person tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(struct person array[], size_t array_size);
/*
{
	for (size_t i = 0; i < array_size - 1; ++i)
		for (size_t j = 0; j < array_size - 1 - i; ++j)
			if (array[j].number > array[j + 1].number)
				person_swap(&array[j], &array[j + 1]);
}
*/

void print_people(struct person array[], size_t array_size) {
	for (size_t i = 0; i < array_size; ++i)
		printf("number = %d, name = %s, age = %d, score = %d\n",
			array[i].number, array[i].name, array[i].age, array[i].score);
}

int main() {
	print_people(people, ARRAYS_SIZE(people));
	putchar('\n');
	sort(people, ARRAYS_SIZE(people)); 
	print_people(people, ARRAYS_SIZE(people)); 
}
