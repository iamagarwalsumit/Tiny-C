	.section	.rodata
.LC0:
	.string	"\nEnter the first number : "
.LC1:
	.string	"\nEnter the second number : "
.LC2:
	.string	"\nInline swapping"
.LC3:
	.string	"\na = "
.LC4:
	.string	"\nb = "
.LC5:
	.string	"\n"
.LC6:
	.string	"\nSwapping through call by reference (pointers)"
.LC7:
	.string	"\na = "
.LC8:
	.string	"\nb = "
.LC9:
	.string	"\n"
.LC10:
	.string	"\nSwapping through call by value"
.LC11:
	.string	"\na = "
.LC12:
	.string	"\nb = "
.LC13:
	.string	"\nNumbers are swapped only through call by reference !\n"
.LC14:
	.string	"\nYou entered non numeral characters"
.LC15:
	.string	"\nThe program is exiting"
.LC16:
	.string	"\nYou entered non numeral characters"
.LC17:
	.string	"\nThe program is exiting"
	.text
	.comm	error,4
	.globl	swap
	.type	swap, @function
swap:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$12, %rsp
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movq	16(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	24(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	nop
	leave
	ret
	.size	swap, .-swap
	.globl	attempt_to_swap
	.type	attempt_to_swap, @function
attempt_to_swap:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$4, %rsp
	movl	16(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	20(%rbp), %eax
	movl	%eax, 16(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, 20(%rbp)
	nop
	leave
	ret
	.size	attempt_to_swap, .-attempt_to_swap
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$160, %rsp
	subq	$4, %rsp
	movl	$.LC0, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC0, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -4(%rbp)
	leaq	error(%rip), %rax
	movq	%rax, -24(%rbp)
	subq	$8, %rsp
	movq	-24(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-24(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$0, %eax
	movl	%eax, -32(%rbp)
	movl	error(%rip), %eax
	cmpl	-32(%rbp), %eax
	je	.L0
	jmp	.L1
	jmp	.L2
.L0:
	subq	$4, %rsp
	movl	$.LC1, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC1, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -36(%rbp)
	leaq	error(%rip), %rax
	movq	%rax, -44(%rbp)
	subq	$8, %rsp
	movq	-44(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-44(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$0, %eax
	movl	%eax, -52(%rbp)
	movl	error(%rip), %eax
	cmpl	-52(%rbp), %eax
	je	.L3
	jmp	.L4
	jmp	.L5
.L3:
	subq	$4, %rsp
	movl	$.LC2, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC2, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -56(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	subq	$4, %rsp
	movl	$.LC3, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC3, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -60(%rbp)
	subq	$4, %rsp
	movl	-8(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-8(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -64(%rbp)
	subq	$4, %rsp
	movl	$.LC4, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC4, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -68(%rbp)
	subq	$4, %rsp
	movl	-12(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-12(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -72(%rbp)
	subq	$4, %rsp
	movl	$.LC5, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC5, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -76(%rbp)
	subq	$4, %rsp
	movl	$.LC6, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC6, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -80(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, -88(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, -96(%rbp)
	subq	$16, %rsp
	movq	-96(%rbp), %rax
	movq	%rax, 8(%rsp)
	movq	-88(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-88(%rbp), %rdi
	call	swap
	subq	$4, %rsp
	movl	$.LC7, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC7, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -100(%rbp)
	subq	$4, %rsp
	movl	-8(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-8(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -104(%rbp)
	subq	$4, %rsp
	movl	$.LC8, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC8, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -108(%rbp)
	subq	$4, %rsp
	movl	-12(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-12(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -112(%rbp)
	subq	$4, %rsp
	movl	$.LC9, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC9, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -116(%rbp)
	subq	$4, %rsp
	movl	$.LC10, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC10, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -120(%rbp)
	subq	$8, %rsp
	movl	-12(%rbp), %eax
	movl	%eax, 4(%rsp)
	movl	-8(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-8(%rbp), %edi
	call	attempt_to_swap
	subq	$4, %rsp
	movl	$.LC11, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC11, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -124(%rbp)
	subq	$4, %rsp
	movl	-8(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-8(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -128(%rbp)
	subq	$4, %rsp
	movl	$.LC12, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC12, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -132(%rbp)
	subq	$4, %rsp
	movl	-12(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-12(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -136(%rbp)
	subq	$4, %rsp
	movl	$.LC13, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC13, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -140(%rbp)
	jmp	.L2
.L4:
	subq	$4, %rsp
	movl	$.LC14, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC14, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -144(%rbp)
	subq	$4, %rsp
	movl	$.LC15, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC15, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -148(%rbp)
.L5:
	jmp	.L2
.L1:
	subq	$4, %rsp
	movl	$.LC16, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC16, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -152(%rbp)
	subq	$4, %rsp
	movl	$.LC17, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC17, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -156(%rbp)
.L2:
	movl	$0, %eax
	movl	%eax, -160(%rbp)
	movl	-160(%rbp), %eax
	leave
	ret
	.size	main, .-main
