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

void print_people(struct person array[], size_t array_size) {
	for (size_t i = 0; i < array_size; ++i)
		printf("number = %d, name = %s, age = %d, score = %d\n",
			array[i].number, array[i].name, array[i].age, array[i].score);
}

void sort(void *array, size_t elem_size, size_t array_size, int (*cmp)(void *, void *));
		
int person_cmp(void *a, void *b)
{
	struct person *ap = a;
	struct person *bp = b;
	
	return ap->number - bp->number;
}

int main() {
	print_people(people, ARRAYS_SIZE(people));
	putchar('\n');
	sort(people, sizeof people[0], ARRAYS_SIZE(people), person_cmp); 
	print_people(people, ARRAYS_SIZE(people)); 
}
