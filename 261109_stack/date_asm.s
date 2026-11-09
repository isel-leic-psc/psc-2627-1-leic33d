/*
uint16_t pack_date(int year, int month, int day)
{                       edi       esi       edx
	uint16_t date = (day & DAY_MASK) << DAY_POSITION;
	         4(%rsp)
	date = date | (month & MONTH_MASK) << MONTH_POSITION;
	date = date | ((year - 2000) & YEAR_MASK) << YEAR_POSITION;
	return date;
}
*/
	.equ	DAY_MASK, 0b11111
	.equ	DAY_POSITION, 0

	.equ	MONTH_MASK, 0b1111
	.equ	MONTH_POSITION, 5
	
	.equ	YEAR_MASK, 0b1111111
	.equ	YEAR_POSITION, 9
	
	.global	pack_date
pack_date:
	sub	$8, %rsp
	
	and	$DAY_MASK, %edx
	shl	$DAY_POSITION, %edx	
	mov	%dx, 4(%rsp)

	and	$MONTH_MASK, %esi
	shl	$MONTH_POSITION, %esi
	or	%si, 4(%rsp)

	sub	$2000, %edi
	and	$YEAR_MASK, %edi
	shl	$YEAR_POSITION, %edi
	or	%di, 4(%rsp)
	
	mov	4(%rsp), %ax

	add	$8, %rsp
	
	ret

	.section .note.GNU-stack 
