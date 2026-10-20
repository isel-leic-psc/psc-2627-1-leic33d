/*
void unpack_date(uint16_t date, int *year, int *month, int *day)
{
	int d = date >> DAY_POSITION & DAY_MASK;
	    r8d
	int m = date >> MONTH_POSITION & MONTH_MASK;
	    r9d
	int y = (date >> YEAR_POSITION & YEAR_MASK) + 2000;
	    r10d
	*year = y;
	*month = m;
	*day = d;
}
*/

	.equ	DAY_POSITION, 0
	.equ	DAY_MASK, 0b11111
	
	.equ	MONTH_POSITION, 5
	.equ	MONTH_MASK, 0b1111
	
	.equ	YEAR_POSITION, 9
	.equ	YEAR_MASK, 0b1111111
	
	.global	unpack_date
unpack_date:
	mov	%di, %r8w
	shr	$DAY_POSITION, %r8w
	and	$DAY_MASK, %r8w
	movzwl	%r8w, %r8d

	mov	%di, %r9w
	shr	$MONTH_POSITION, %r9w
	and	$MONTH_MASK, %r9w
	movzwl	%r9w, %r9d

	mov	%di, %r10w
	shr	$YEAR_POSITION, %r10w
	and	$YEAR_MASK, %r10w
	movzwl	%r10w, %r10d
	add	$2000, %r10d
	
	mov	%r10d, (%rsi)
	mov	%r9d, (%rdx)
	mov	%r8d, (%rcx)
	
	ret

	
	
	
	.section .note.GNU-stack
	
	
	
