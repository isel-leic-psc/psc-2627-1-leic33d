/*
void sort(struct person array[], size_t array_size);
{			rdi, r12		rsi, r13
	for (size_t i = 0; i < array_size - 1; ++i)
		rbx
		for (size_t j = 0; j < array_size - 1 - i; ++j)
			rbp
			if (array[j].number > array[j + 1].number)
				person_swap(&array[j], &array[j + 1]);
}
*/

	.equ	number, 40
	.equ	sizeof_struct_person, 44
	
	.text
	.global	sort
sort:
	push	%r12
	push	%r13
	push	%rbx
	push	%rbp
	mov	%rdi, %r12
	mov	%rsi, %r13
	mov	$0, %rbx
	sub	$1, %r13
for1:	cmp	%rbx, %r13
	jbe	for1_end
	mov	$0, %rbp
for2:
	mov	%r13, %rax
	sub	%rbx, %rax
	cmp	%rbp, %rax
	jbe	for2_end
	mov	%rbp, %rax	/* j * 44 = 32 + 8 + 4 = (8 + 2 + 1) * 4
	shl	$3, %rax
	mov	%rbp, %r8
	shl	$1, %r8
	add	%rax, %r8	/* r8 = 8 * j + 2 * j */
	add	%rbp, %r8	/* r8 = 8 * j + 2 * j + j */
	mov	number(%r12, %r8, 4), %eax
	cmp	sizeof_struct_person + number(%rdi, %r8, 4), %eax
	jge	if_end
	lea	(%r12, %r8, 4), %rdi
	lea	sizeof_struct_person(%r12, %r8, 4), %rsi
	call	person_swap
if_end:
	inc	%rbp
	jmp	for2

for2_end:
	inc	%rbx
	jmp	for1

for1_end:
	pop	%rbp
	pop	%rbx
	pop	%r13
	pop	%r12
	ret

	.section	.note.GNU-stack
	
