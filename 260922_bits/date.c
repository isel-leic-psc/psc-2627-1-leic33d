#include <stdio.h>
#include <stdint.h>

#define	DAY_POSITION	0
#define	MONTH_POSITION	5
#define	YEAR_POSITION	9

#define	DAY_MASK	0b11111
#define	MONTH_MASK	0b1111
#define	YEAR_MASK	0b1111111

uint16_t pack_date(int year, int month, int day)
{
	uint16_t date = (day & DAY_MASK) << DAY_POSITION;
	date = date | (month & MONTH_MASK) << MONTH_POSITION;
	date = date | ((year - 2000) & YEAR_MASK) << YEAR_POSITION;
	return date;
}

void unpack_date(uint16_t date, int *year, int *month, int *day)
{
	int d = date >> DAY_POSITION & DAY_MASK;
	int m = date >> MONTH_POSITION & MONTH_MASK;
	int y = (date >> YEAR_POSITION & YEAR_MASK)+ 2000;
	*year = y;
	*month = m;
	*day = d;
}

int main()
{
	int day = 22;
	int month = 9;
	int year = 2026;
	
	uint16_t date = pack_date(year, month, day);
	
	printf("unpack date: %d-%d-%d, pack date: %b\n", year, month, day, date);

	int y;
	int m;
	int d;
	unpack_date(date, &y, &m, &d);

	printf("\npack date: %b, unpack date: %d-%d-%d\n", date, y, m, d);
}

/*
 * &y - ponteiro para ; endereço de
 * int *year - variável que recebe um ponteiro; referência explicita
 * *year - valor apontoado por; conteúdo apontado por; conteúdo de; desreferenciar
 */
