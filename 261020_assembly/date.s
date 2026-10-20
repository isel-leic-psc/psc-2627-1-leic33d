	.file	"date.c"
	.text
	.globl	pack_date
	.type	pack_date, @function
pack_date:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-28(%rbp), %eax
	andl	$31, %eax
	movw	%ax, -2(%rbp)
	movl	-24(%rbp), %eax
	sall	$5, %eax
	andw	$480, %ax
	movl	%eax, %edx
	movzwl	-2(%rbp), %eax
	orl	%edx, %eax
	movw	%ax, -2(%rbp)
	movl	-20(%rbp), %eax
	subl	$2000, %eax
	sall	$9, %eax
	movl	%eax, %edx
	movzwl	-2(%rbp), %eax
	orl	%edx, %eax
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	pack_date, .-pack_date
	.section	.rodata
	.align 8
.LC0:
	.string	"unpack date: %d-%d-%d, pack date: %b\n"
	.align 8
.LC1:
	.string	"\npack date: %b, unpack date: %d-%d-%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$22, -20(%rbp)
	movl	$9, -16(%rbp)
	movl	$2026, -12(%rbp)
	movl	-20(%rbp), %edx
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	pack_date
	movw	%ax, -34(%rbp)
	movzwl	-34(%rbp), %esi
	movl	-20(%rbp), %ecx
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	leaq	.LC0(%rip), %rdi
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$0, %eax
	call	printf@PLT
	movzwl	-34(%rbp), %eax
	leaq	-24(%rbp), %rcx
	leaq	-28(%rbp), %rdx
	leaq	-32(%rbp), %rsi
	movl	%eax, %edi
	call	unpack_date@PLT
	movl	-24(%rbp), %esi
	movl	-28(%rbp), %ecx
	movl	-32(%rbp), %edx
	movzwl	-34(%rbp), %eax
	leaq	.LC1(%rip), %rdi
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
