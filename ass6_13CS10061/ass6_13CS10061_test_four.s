	.section	.rodata
.LC0:
	.string	"Enter the size of Array :"
.LC1:
	.string	"Enter elements of the array one per line :\n"
.LC2:
	.string	"Enter the number that you want to search :\n"
.LC3:
	.string	"Found at index "
.LC4:
	.string	"\n"
.LC5:
	.string	"Element Not Found\n"
	.text
	.comm	error,4
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$552, %rsp
	movl	$100, %eax
	movl	%eax, -4(%rbp)
	movl	$1, %eax
	movl	%eax, -424(%rbp)
	movl	-424(%rbp), %eax
	negl	%eax
	movl	%eax, -428(%rbp)
	movl	-428(%rbp), %eax
	movl	%eax, -420(%rbp)
	subq	$4, %rsp
	movl	$.LC0, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC0, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -432(%rbp)
	leaq	error(%rip), %rax
	movq	%rax, -440(%rbp)
	subq	$8, %rsp
	movq	-440(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-440(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -444(%rbp)
	movl	-444(%rbp), %eax
	movl	%eax, -408(%rbp)
	subq	$4, %rsp
	movl	$.LC1, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC1, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -448(%rbp)
	movl	$0, %eax
	movl	%eax, -452(%rbp)
	movl	-452(%rbp), %eax
	movl	%eax, -412(%rbp)
.L2:
	movl	-412(%rbp), %eax
	cmpl	-408(%rbp), %eax
	jl	.L0
	jmp	.L1
	jmp	.L1
.L3:
	movl	-412(%rbp), %eax
	movl	%eax, -456(%rbp)
	movl	$1, %eax
	movl	%eax, -460(%rbp)
	movl	-412(%rbp), %eax
	movl	-460(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -412(%rbp)
	jmp	.L2
.L0:
	movl	$4, %eax
	movl	%eax, -468(%rbp)
	movl	-412(%rbp), %eax
	imull	-468(%rbp), %eax
	movl	%eax, -464(%rbp)
	movl	-464(%rbp), %eax
	leaq	-404(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -472(%rbp)
	leaq	error(%rip), %rax
	movq	%rax, -480(%rbp)
	subq	$8, %rsp
	movq	-480(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-480(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -484(%rbp)
	movl	-464(%rbp), %eax
	leaq	-404(%rbp), %rdx
	addq	%rdx, %rax
	movl	-484(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L3
.L1:
	subq	$4, %rsp
	movl	$.LC2, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC2, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -488(%rbp)
	leaq	error(%rip), %rax
	movq	%rax, -496(%rbp)
	subq	$8, %rsp
	movq	-496(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-496(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -500(%rbp)
	movl	-500(%rbp), %eax
	movl	%eax, -416(%rbp)
	movl	$0, %eax
	movl	%eax, -504(%rbp)
	movl	-504(%rbp), %eax
	movl	%eax, -412(%rbp)
.L6:
	movl	-412(%rbp), %eax
	cmpl	-408(%rbp), %eax
	jl	.L4
	jmp	.L5
	jmp	.L5
.L8:
	movl	-412(%rbp), %eax
	movl	%eax, -508(%rbp)
	movl	$1, %eax
	movl	%eax, -512(%rbp)
	movl	-412(%rbp), %eax
	movl	-512(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -412(%rbp)
	jmp	.L6
.L4:
	movl	$4, %eax
	movl	%eax, -520(%rbp)
	movl	-412(%rbp), %eax
	imull	-520(%rbp), %eax
	movl	%eax, -516(%rbp)
	movl	-516(%rbp), %eax
	leaq	-404(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -524(%rbp)
	movl	-524(%rbp), %eax
	cmpl	-416(%rbp), %eax
	je	.L7
	jmp	.L8
	jmp	.L9
.L7:
	movl	-412(%rbp), %eax
	movl	%eax, -420(%rbp)
	jmp	.L8
.L9:
	jmp	.L8
.L5:
	movl	$1, %eax
	movl	%eax, -528(%rbp)
	movl	-528(%rbp), %eax
	negl	%eax
	movl	%eax, -532(%rbp)
	movl	-420(%rbp), %eax
	cmpl	-532(%rbp), %eax
	jne	.L10
	jmp	.L11
	jmp	.L12
.L10:
	subq	$4, %rsp
	movl	$.LC3, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC3, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -536(%rbp)
	subq	$4, %rsp
	movl	-420(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-420(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -540(%rbp)
	subq	$4, %rsp
	movl	$.LC4, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC4, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -544(%rbp)
	jmp	.L12
.L11:
	subq	$4, %rsp
	movl	$.LC5, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC5, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -548(%rbp)
.L12:
	movl	$0, %eax
	movl	%eax, -552(%rbp)
	movl	-552(%rbp), %eax
	leave
	ret
	.size	main, .-main
