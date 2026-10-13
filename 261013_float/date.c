#include <stdio.h>

struct date {
	unsigned short	day:5;
	unsigned short	month:4;
	unsigned short	year:7;
}; 


struct date date = {.day = 13, .year = 2026 - 2000, .month = 10};

int main()
{
	printf("sizeof  date = %ld\n", sizeof date);
	printf("date: %d-%d-%d\n", date.day, date.month, date.year + 2000);
}
