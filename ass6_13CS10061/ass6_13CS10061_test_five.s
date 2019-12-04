	.section	.rodata
.LC0:
	.string	"Enter the size of the array : "
.LC1:
	.string	"Enter the elements by pressing enter one by one : \n"
.LC2:
	.string	"The elements of the array after sorting : \n"
.LC3:
	.string	" "
.LC4:
	.string	"\n"
	.text
	.globl	merge
	.type	merge, @function
merge:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$440, %rsp
	movl	$50, %eax
	movl	%eax, -20(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$1, %eax
	movl	%eax, -224(%rbp)
	movl	28(%rbp), %eax
	movl	-224(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -228(%rbp)
	movl	-228(%rbp), %eax
	movl	%eax, -8(%rbp)
.L6:
	movl	-16(%rbp), %eax
	cmpl	28(%rbp), %eax
	jle	.L0
	jmp	.L1
.L0:
	movl	-8(%rbp), %eax
	cmpl	32(%rbp), %eax
	jle	.L2
	jmp	.L1
	jmp	.L1
.L2:
	movl	$4, %eax
	movl	%eax, -236(%rbp)
	movl	-16(%rbp), %eax
	imull	-236(%rbp), %eax
	movl	%eax, -232(%rbp)
	movl	-232(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -240(%rbp)
	movl	$4, %eax
	movl	%eax, -248(%rbp)
	movl	-8(%rbp), %eax
	imull	-248(%rbp), %eax
	movl	%eax, -244(%rbp)
	movl	-244(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -252(%rbp)
	movl	-240(%rbp), %eax
	cmpl	-252(%rbp), %eax
	jle	.L3
	jmp	.L4
	jmp	.L5
.L3:
	movl	$4, %eax
	movl	%eax, -260(%rbp)
	movl	-4(%rbp), %eax
	imull	-260(%rbp), %eax
	movl	%eax, -256(%rbp)
	movl	-256(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -264(%rbp)
	movl	$4, %eax
	movl	%eax, -272(%rbp)
	movl	-16(%rbp), %eax
	imull	-272(%rbp), %eax
	movl	%eax, -268(%rbp)
	movl	-268(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -276(%rbp)
	movl	-256(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	-276(%rbp), %edx
	movl	%edx, (%rax)
	movl	-16(%rbp), %eax
	movl	%eax, -280(%rbp)
	movl	$1, %eax
	movl	%eax, -284(%rbp)
	movl	-16(%rbp), %eax
	movl	-284(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	jmp	.L5
.L4:
	movl	$4, %eax
	movl	%eax, -292(%rbp)
	movl	-4(%rbp), %eax
	imull	-292(%rbp), %eax
	movl	%eax, -288(%rbp)
	movl	-288(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -296(%rbp)
	movl	$4, %eax
	movl	%eax, -304(%rbp)
	movl	-8(%rbp), %eax
	imull	-304(%rbp), %eax
	movl	%eax, -300(%rbp)
	movl	-300(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -308(%rbp)
	movl	-288(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	-308(%rbp), %edx
	movl	%edx, (%rax)
	movl	-8(%rbp), %eax
	movl	%eax, -312(%rbp)
	movl	$1, %eax
	movl	%eax, -316(%rbp)
	movl	-8(%rbp), %eax
	movl	-316(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
.L5:
	movl	-4(%rbp), %eax
	movl	%eax, -320(%rbp)
	movl	$1, %eax
	movl	%eax, -324(%rbp)
	movl	-4(%rbp), %eax
	movl	-324(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	jmp	.L6
.L1:
	movl	-16(%rbp), %eax
	cmpl	28(%rbp), %eax
	jg	.L7
	jmp	.L8
	jmp	.L9
.L7:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
.L12:
	movl	-12(%rbp), %eax
	cmpl	32(%rbp), %eax
	jle	.L10
	jmp	.L9
	jmp	.L11
.L13:
	movl	-12(%rbp), %eax
	movl	%eax, -328(%rbp)
	movl	$1, %eax
	movl	%eax, -332(%rbp)
	movl	-12(%rbp), %eax
	movl	-332(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	jmp	.L12
.L10:
	movl	$4, %eax
	movl	%eax, -340(%rbp)
	movl	-4(%rbp), %eax
	imull	-340(%rbp), %eax
	movl	%eax, -336(%rbp)
	movl	-336(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -344(%rbp)
	movl	$4, %eax
	movl	%eax, -352(%rbp)
	movl	-12(%rbp), %eax
	imull	-352(%rbp), %eax
	movl	%eax, -348(%rbp)
	movl	-348(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -356(%rbp)
	movl	-336(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	-356(%rbp), %edx
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	movl	%eax, -360(%rbp)
	movl	$1, %eax
	movl	%eax, -364(%rbp)
	movl	-4(%rbp), %eax
	movl	-364(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	jmp	.L13
.L11:
	jmp	.L9
.L8:
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
.L15:
	movl	-12(%rbp), %eax
	cmpl	28(%rbp), %eax
	jle	.L14
	jmp	.L9
	jmp	.L9
.L16:
	movl	-12(%rbp), %eax
	movl	%eax, -368(%rbp)
	movl	$1, %eax
	movl	%eax, -372(%rbp)
	movl	-12(%rbp), %eax
	movl	-372(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	jmp	.L15
.L14:
	movl	$4, %eax
	movl	%eax, -380(%rbp)
	movl	-4(%rbp), %eax
	imull	-380(%rbp), %eax
	movl	%eax, -376(%rbp)
	movl	-376(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -384(%rbp)
	movl	$4, %eax
	movl	%eax, -392(%rbp)
	movl	-12(%rbp), %eax
	imull	-392(%rbp), %eax
	movl	%eax, -388(%rbp)
	movl	-388(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -396(%rbp)
	movl	-376(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	-396(%rbp), %edx
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	movl	%eax, -400(%rbp)
	movl	$1, %eax
	movl	%eax, -404(%rbp)
	movl	-4(%rbp), %eax
	movl	-404(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	jmp	.L16
.L9:
	movl	24(%rbp), %eax
	movl	%eax, -12(%rbp)
.L19:
	movl	-12(%rbp), %eax
	cmpl	32(%rbp), %eax
	jle	.L17
	jmp	.L18
	jmp	.L18
.L20:
	movl	-12(%rbp), %eax
	movl	%eax, -408(%rbp)
	movl	$1, %eax
	movl	%eax, -412(%rbp)
	movl	-12(%rbp), %eax
	movl	-412(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	jmp	.L19
.L17:
	movl	$4, %eax
	movl	%eax, -420(%rbp)
	movl	-12(%rbp), %eax
	imull	-420(%rbp), %eax
	movl	%eax, -416(%rbp)
	movl	-416(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -424(%rbp)
	movl	$4, %eax
	movl	%eax, -432(%rbp)
	movl	-12(%rbp), %eax
	imull	-432(%rbp), %eax
	movl	%eax, -428(%rbp)
	movl	-428(%rbp), %eax
	leaq	-220(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -436(%rbp)
	movl	-416(%rbp), %eax
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movl	-436(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L20
.L18:
	movl	$0, %eax
	movl	%eax, -440(%rbp)
	movl	-440(%rbp), %eax
	leave
	ret
	.size	merge, .-merge
	.globl	mergeSort
	.type	mergeSort, @function
mergeSort:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	24(%rbp), %eax
	cmpl	28(%rbp), %eax
	jl	.L21
	jmp	.L22
	jmp	.L22
.L21:
	movl	24(%rbp), %eax
	movl	28(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$2, %eax
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %eax
	cltd
	idivl	-20(%rbp)
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	$1, %eax
	movl	%eax, -28(%rbp)
	movl	-4(%rbp), %eax
	movl	-28(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -12(%rbp)
	subq	$16, %rsp
	movl	-4(%rbp), %eax
	movl	%eax, 12(%rsp)
	movl	24(%rbp), %eax
	movl	%eax, 8(%rsp)
	movq	16(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	16(%rbp), %rdi
	call	mergeSort
	addq	$16, %rsp
	movl	%eax, -36(%rbp)
	subq	$16, %rsp
	movl	28(%rbp), %eax
	movl	%eax, 12(%rsp)
	movl	-12(%rbp), %eax
	movl	%eax, 8(%rsp)
	movq	16(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	16(%rbp), %rdi
	call	mergeSort
	addq	$16, %rsp
	movl	%eax, -40(%rbp)
	subq	$20, %rsp
	movl	28(%rbp), %eax
	movl	%eax, 16(%rsp)
	movl	-4(%rbp), %eax
	movl	%eax, 12(%rsp)
	movl	24(%rbp), %eax
	movl	%eax, 8(%rsp)
	movq	16(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	16(%rbp), %rdi
	call	merge
	addq	$20, %rsp
	movl	%eax, -44(%rbp)
	jmp	.L22
.L22:
	movl	$0, %eax
	movl	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	leave
	ret
	.size	mergeSort, .-mergeSort
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$336, %rsp
	movl	$50, %eax
	movl	%eax, -4(%rbp)
	subq	$4, %rsp
	movl	$.LC0, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC0, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -220(%rbp)
	leaq	-216(%rbp), %rax
	movq	%rax, -228(%rbp)
	subq	$8, %rsp
	movq	-228(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-228(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -232(%rbp)
	movl	-232(%rbp), %eax
	movl	%eax, -212(%rbp)
	subq	$4, %rsp
	movl	$.LC1, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC1, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -236(%rbp)
	movl	$0, %eax
	movl	%eax, -240(%rbp)
	movl	-240(%rbp), %eax
	movl	%eax, -208(%rbp)
.L25:
	movl	-208(%rbp), %eax
	cmpl	-212(%rbp), %eax
	jl	.L23
	jmp	.L24
	jmp	.L24
.L26:
	movl	-208(%rbp), %eax
	movl	%eax, -244(%rbp)
	movl	$1, %eax
	movl	%eax, -248(%rbp)
	movl	-208(%rbp), %eax
	movl	-248(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -208(%rbp)
	jmp	.L25
.L23:
	movl	$4, %eax
	movl	%eax, -256(%rbp)
	movl	-208(%rbp), %eax
	imull	-256(%rbp), %eax
	movl	%eax, -252(%rbp)
	movl	-252(%rbp), %eax
	leaq	-204(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -260(%rbp)
	leaq	-216(%rbp), %rax
	movq	%rax, -268(%rbp)
	subq	$8, %rsp
	movq	-268(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-268(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -272(%rbp)
	movl	-252(%rbp), %eax
	leaq	-204(%rbp), %rdx
	addq	%rdx, %rax
	movl	-272(%rbp), %edx
	movl	%edx, (%rax)
	jmp	.L26
.L24:
	movl	$1, %eax
	movl	%eax, -280(%rbp)
	movl	-212(%rbp), %eax
	movl	-280(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -284(%rbp)
	movl	-284(%rbp), %eax
	movl	%eax, -276(%rbp)
	movl	$0, %eax
	movl	%eax, -288(%rbp)
	subq	$16, %rsp
	movl	-276(%rbp), %eax
	movl	%eax, 12(%rsp)
	movl	-288(%rbp), %eax
	movl	%eax, 8(%rsp)
	leaq	-204(%rbp), %rax
	movq	%rax, 0(%rsp)
	leaq	-204(%rbp), %rdi
	call	mergeSort
	addq	$16, %rsp
	movl	%eax, -292(%rbp)
	subq	$4, %rsp
	movl	$.LC2, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC2, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -296(%rbp)
	movl	$0, %eax
	movl	%eax, -300(%rbp)
	movl	-300(%rbp), %eax
	movl	%eax, -208(%rbp)
.L29:
	movl	-208(%rbp), %eax
	cmpl	-212(%rbp), %eax
	jl	.L27
	jmp	.L28
	jmp	.L28
.L30:
	movl	-208(%rbp), %eax
	movl	%eax, -304(%rbp)
	movl	$1, %eax
	movl	%eax, -308(%rbp)
	movl	-208(%rbp), %eax
	movl	-308(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -208(%rbp)
	jmp	.L29
.L27:
	movl	$4, %eax
	movl	%eax, -316(%rbp)
	movl	-208(%rbp), %eax
	imull	-316(%rbp), %eax
	movl	%eax, -312(%rbp)
	movl	-312(%rbp), %eax
	leaq	-204(%rbp), %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -320(%rbp)
	subq	$4, %rsp
	movl	-320(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-320(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -324(%rbp)
	subq	$4, %rsp
	movl	$.LC3, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC3, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -328(%rbp)
	jmp	.L30
.L28:
	subq	$4, %rsp
	movl	$.LC4, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC4, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -332(%rbp)
	movl	$0, %eax
	movl	%eax, -336(%rbp)
	movl	-336(%rbp), %eax
	leave
	ret
	.size	main, .-main
