/*
void sort(void *array, size_t elem_size, size_t array_size,
		rdi, r12      rsi, r13          rdx, r14
		int (*cmp)(void *, void *))
		      rcx, r15

{
	for (size_t i = 0; i < array_size - 1; ++i)
	            rbx
		for (size_t j = 0; j < array_size - 1 - i; ++j)
					
			if (cmp((char *)array + j * elem_size, (char *)array + (j + 1) * elem_size) > 0)
				swap((char *)array + j * elem_size, (char *)array + (j + 1) * elem_size, elem_size);
}
*/
	.text
	.global	sort
sort:
	push	%r12
	push	%r13
	push	%r14
	push	%r15
	push	%rbx
	push	%rbp
	
	mov	%rdi, %r12
	mov	%rsi, %r13
	mov	%rdx, %r14
	mov	%rcx, %r15
	
	mov	$0, %rbx
	sub	$1, %r14
for1:	cmp	%rbx, %r14
	jbe	for1_end
	mov	$0, %rbp
for2:
	mov	%r14, %rax
	sub	%rbx, %rax
	cmp	%rbp, %rax
	jbe	for2_end

	mov	%rbp, %rax
	mul	%r13
	lea	(%r12, %rax), %rdi
	lea	(%rdi, %r13), %rsi
	call	*%r15

	cmp	$0, %eax
	jle	if_end

	mov	%rbp, %rax
	mul	%r13
	lea	(%r12, %rax), %rdi
	lea	(%rdi, %r13), %rsi
	mov	%r13, %rdx
	call	swap

if_end:
	inc	%rbp
	jmp	for2

for2_end:
	inc	%rbx
	jmp	for1

for1_end:
	pop	%rbp
	pop	%rbx
	pop	%r15
	pop	%r14
	pop	%r13
	pop	%r12
	ret

	.section	.note.GNU-stack
	
