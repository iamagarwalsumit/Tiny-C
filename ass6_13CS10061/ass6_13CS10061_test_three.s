	.section	.rodata
.LC0:
	.string	"Enter the size: "
.LC1:
	.string	"Enter the string by entering the characters separated by \\n : "
.LC2:
	.string	"The string "
.LC3:
	.string	" is palindrome.\n"
.LC4:
	.string	" is not palindrome.\n"
	.text
	.globl	palindrome
	.type	palindrome, @function
palindrome:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$72, %rsp
	movl	$0, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$1, %eax
	movl	%eax, -20(%rbp)
	movl	32(%rbp), %eax
	movl	-20(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$1, %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jg	.L0
	jmp	.L1
	jmp	.L1
.L0:
	movl	$4, %eax
	movl	%eax, -36(%rbp)
	movl	-4(%rbp), %eax
	imull	-36(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movq	24(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -40(%rbp)
	movl	$4, %eax
	movl	%eax, -48(%rbp)
	movl	-8(%rbp), %eax
	imull	-48(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movq	24(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -52(%rbp)
	movl	-40(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jne	.L2
	jmp	.L3
	jmp	.L3
.L2:
	movl	$0, %eax
	movl	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L3
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	$1, %eax
	movl	%eax, -64(%rbp)
	movl	-4(%rbp), %eax
	movl	-64(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -68(%rbp)
	movl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	-8(%rbp), %eax
	movl	-72(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -8(%rbp)
	jmp	.L4
.L1:
	movl	-12(%rbp), %eax
	leave
	ret
	.size	palindrome, .-palindrome
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$20180, %rsp
	movl	$1000, %eax
	movl	%eax, -4(%rbp)
	movl	$1000, %eax
	movl	%eax, -16008(%rbp)
	subq	$4, %rsp
	movl	$.LC0, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC0, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -20020(%rbp)
	leaq	-20012(%rbp), %rax
	movq	%rax, -20028(%rbp)
	subq	$8, %rsp
	movq	-20028(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-20028(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -20032(%rbp)
	movl	-20032(%rbp), %eax
	movl	%eax, -20016(%rbp)
	subq	$4, %rsp
	movl	$.LC1, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC1, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -20036(%rbp)
	movl	$0, %eax
	movl	%eax, -20044(%rbp)
	movl	-20044(%rbp), %eax
	movl	%eax, -20040(%rbp)
.L7:
	movl	-20040(%rbp), %eax
	cmpl	-20016(%rbp), %eax
	jl	.L5
	jmp	.L6
	jmp	.L6
.L8:
	movl	-20040(%rbp), %eax
	movl	%eax, -20048(%rbp)
	movl	$1, %eax
	movl	%eax, -20052(%rbp)
	movl	-20040(%rbp), %eax
	movl	-20052(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -20040(%rbp)
	jmp	.L7
.L5:
	movl	$1, %eax
	movl	%eax, -20060(%rbp)
	movl	-20040(%rbp), %eax
	imull	-20060(%rbp), %eax
	movl	%eax, -20056(%rbp)
	movl	-20056(%rbp), %eax
	leaq	-16004(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -20076(%rbp)
	leaq	-20012(%rbp), %rax
	movq	%rax, -20084(%rbp)
	subq	$8, %rsp
	movq	-20084(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-20084(%rbp), %rdi
	call	readc
	addq	$8, %rsp
	movl	%eax, -20100(%rbp)
	movl	-20056(%rbp), %eax
	leaq	-16004(%rbp), %rdx
	addq	%rdx, %rax
	movl	-20100(%rbp), %edx
	movl	%edx, (%rax)
	movl	$4, %eax
	movl	%eax, -20108(%rbp)
	movl	-20040(%rbp), %eax
	imull	-20108(%rbp), %eax
	movl	%eax, -20104(%rbp)
	movl	-20104(%rbp), %eax
	leaq	-20008(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -20112(%rbp)
	movl	-20104(%rbp), %eax
	leaq	-20008(%rbp), %rdx
	addq	%rdx, %rax
	movl	-20012(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L8
.L6:
	subq	$20, %rsp
	movl	-20016(%rbp), %eax
	movl	%eax, 16(%rsp)
	leaq	-20008(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-16004(%rbp), %rax
	movq	%rax, 0(%rsp)
	leaq	-16004(%rbp), %rdi
	call	palindrome
	addq	$20, %rsp
	movl	%eax, -20120(%rbp)
	movl	-20120(%rbp), %eax
	movl	%eax, -20116(%rbp)
	subq	$4, %rsp
	movl	$.LC2, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC2, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -20124(%rbp)
	movl	$0, %eax
	movl	%eax, -20128(%rbp)
	movl	-20128(%rbp), %eax
	movl	%eax, -20040(%rbp)
.L11:
	movl	-20040(%rbp), %eax
	cmpl	-20016(%rbp), %eax
	jl	.L9
	jmp	.L10
	jmp	.L10
.L12:
	movl	-20040(%rbp), %eax
	movl	%eax, -20132(%rbp)
	movl	$1, %eax
	movl	%eax, -20136(%rbp)
	movl	-20040(%rbp), %eax
	movl	-20136(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -20040(%rbp)
	jmp	.L11
.L9:
	movl	$1, %eax
	movl	%eax, -20144(%rbp)
	movl	-20040(%rbp), %eax
	imull	-20144(%rbp), %eax
	movl	%eax, -20140(%rbp)
	movl	-20140(%rbp), %eax
	leaq	-16004(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -20160(%rbp)
	subq	$16, %rsp
	movl	-20160(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-20160(%rbp), %edi
	call	printc
	addq	$16, %rsp
	movl	%eax, -20164(%rbp)
	jmp	.L12
.L10:
	movl	$1, %eax
	movl	%eax, -20168(%rbp)
	movl	-20116(%rbp), %eax
	cmpl	-20168(%rbp), %eax
	je	.L13
	jmp	.L14
	jmp	.L15
.L13:
	subq	$4, %rsp
	movl	$.LC3, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC3, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -20172(%rbp)
	jmp	.L15
.L14:
	subq	$4, %rsp
	movl	$.LC4, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC4, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -20176(%rbp)
.L15:
	movl	$0, %eax
	movl	%eax, -20180(%rbp)
	movl	-20180(%rbp), %eax
	leave
	ret
	.size	main, .-main
