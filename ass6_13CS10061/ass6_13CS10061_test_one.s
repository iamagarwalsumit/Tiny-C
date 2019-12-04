	.section	.rodata
.LC0:
	.string	"Enter the first operand : "
.LC1:
	.string	"Enter the second operand : "
.LC2:
	.string	"1 for addition\n"
.LC3:
	.string	"2 for subtraction\n"
.LC4:
	.string	"3 for multiplication\n"
.LC5:
	.string	"4 for division\n"
.LC6:
	.string	"5 for modulus\n"
.LC7:
	.string	"61 for unary plus to first variable\n"
.LC8:
	.string	"62 for unary plus to first variable\n"
.LC9:
	.string	"71 for unary minus to first variable\n"
.LC10:
	.string	"72 for unary minus to first variable\n"
.LC11:
	.string	"-1 for exit\n"
.LC12:
	.string	"Enter your choice\n"
.LC13:
	.string	"Result : "
.LC14:
	.string	"\n"
.LC15:
	.string	"Result : "
.LC16:
	.string	"\n"
.LC17:
	.string	"Result : "
.LC18:
	.string	"\n"
.LC19:
	.string	"Result : "
.LC20:
	.string	"\n"
.LC21:
	.string	"Result : "
.LC22:
	.string	"\n"
.LC23:
	.string	"Result : "
.LC24:
	.string	"\n"
.LC25:
	.string	"Result : "
.LC26:
	.string	"\n"
.LC27:
	.string	"Result : "
.LC28:
	.string	"\n"
.LC29:
	.string	"Result : "
.LC30:
	.string	"\n"
.LC31:
	.string	"Try another option !\n"
	.text
	.comm	a,4
	.comm	b,4
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$296, %rsp
	subq	$4, %rsp
	movl	$.LC0, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC0, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -4(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	subq	$8, %rsp
	movq	-24(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-24(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, a(%rip)
	subq	$4, %rsp
	movl	$.LC1, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC1, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -32(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	subq	$8, %rsp
	movq	-40(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-40(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, b(%rip)
	subq	$4, %rsp
	movl	$.LC2, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC2, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -48(%rbp)
	subq	$4, %rsp
	movl	$.LC3, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC3, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -52(%rbp)
	subq	$4, %rsp
	movl	$.LC4, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC4, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -56(%rbp)
	subq	$4, %rsp
	movl	$.LC5, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC5, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -60(%rbp)
	subq	$4, %rsp
	movl	$.LC6, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC6, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -64(%rbp)
	subq	$4, %rsp
	movl	$.LC7, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC7, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -68(%rbp)
	subq	$4, %rsp
	movl	$.LC8, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC8, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -72(%rbp)
	subq	$4, %rsp
	movl	$.LC9, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC9, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -76(%rbp)
	subq	$4, %rsp
	movl	$.LC10, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC10, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -80(%rbp)
	subq	$4, %rsp
	movl	$.LC11, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC11, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -84(%rbp)
.L19:
	subq	$4, %rsp
	movl	$.LC12, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC12, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -88(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, -96(%rbp)
	subq	$8, %rsp
	movq	-96(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	-96(%rbp), %rdi
	call	readi
	addq	$8, %rsp
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$1, %eax
	movl	%eax, -104(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-104(%rbp), %eax
	je	.L0
	jmp	.L1
	jmp	.L2
.L0:
	movl	a(%rip), %eax
	movl	b(%rip), %edx
	addl	%edx, %eax
	movl	%eax, -108(%rbp)
	movl	-108(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC13, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC13, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -112(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -116(%rbp)
	subq	$4, %rsp
	movl	$.LC14, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC14, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -120(%rbp)
	jmp	.L2
.L1:
	movl	$2, %eax
	movl	%eax, -124(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-124(%rbp), %eax
	je	.L3
	jmp	.L4
	jmp	.L2
.L3:
	movl	a(%rip), %eax
	movl	b(%rip), %edx
	subl	%edx, %eax
	movl	%eax, -128(%rbp)
	movl	-128(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC15, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC15, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -132(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -136(%rbp)
	subq	$4, %rsp
	movl	$.LC16, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC16, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -140(%rbp)
	jmp	.L2
.L4:
	movl	$3, %eax
	movl	%eax, -144(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-144(%rbp), %eax
	je	.L5
	jmp	.L6
	jmp	.L2
.L5:
	movl	a(%rip), %eax
	imull	b(%rip), %eax
	movl	%eax, -148(%rbp)
	movl	-148(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC17, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC17, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -152(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -156(%rbp)
	subq	$4, %rsp
	movl	$.LC18, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC18, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -160(%rbp)
	jmp	.L2
.L6:
	movl	$4, %eax
	movl	%eax, -164(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-164(%rbp), %eax
	je	.L7
	jmp	.L8
	jmp	.L2
.L7:
	movl	a(%rip), %eax
	cltd
	idivl	b(%rip)
	movl	%eax, -168(%rbp)
	movl	-168(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC19, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC19, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -172(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -176(%rbp)
	subq	$4, %rsp
	movl	$.LC20, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC20, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -180(%rbp)
	jmp	.L2
.L8:
	movl	$5, %eax
	movl	%eax, -184(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-184(%rbp), %eax
	je	.L9
	jmp	.L10
	jmp	.L2
.L9:
	movl	a(%rip), %eax
	cltd
	idivl	b(%rip)
	movl	%edx, -188(%rbp)
	movl	-188(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC21, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC21, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -192(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -196(%rbp)
	subq	$4, %rsp
	movl	$.LC22, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC22, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -200(%rbp)
	jmp	.L2
.L10:
	movl	$61, %eax
	movl	%eax, -204(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-204(%rbp), %eax
	je	.L11
	jmp	.L12
	jmp	.L2
.L11:
	movl	a(%rip), %eax
	movl	%eax, -208(%rbp)
	movl	-208(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC23, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC23, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -212(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -216(%rbp)
	subq	$4, %rsp
	movl	$.LC24, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC24, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -220(%rbp)
	jmp	.L2
.L12:
	movl	$62, %eax
	movl	%eax, -224(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-224(%rbp), %eax
	je	.L13
	jmp	.L14
	jmp	.L2
.L13:
	movl	b(%rip), %eax
	movl	%eax, -228(%rbp)
	movl	-228(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC25, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC25, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -232(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -236(%rbp)
	subq	$4, %rsp
	movl	$.LC26, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC26, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -240(%rbp)
	jmp	.L2
.L14:
	movl	$71, %eax
	movl	%eax, -244(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-244(%rbp), %eax
	je	.L15
	jmp	.L16
	jmp	.L2
.L15:
	movl	a(%rip), %eax
	negl	%eax
	movl	%eax, -248(%rbp)
	movl	-248(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC27, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC27, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -252(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -256(%rbp)
	subq	$4, %rsp
	movl	$.LC28, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC28, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -260(%rbp)
	jmp	.L2
.L16:
	movl	$72, %eax
	movl	%eax, -264(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-264(%rbp), %eax
	je	.L17
	jmp	.L18
	jmp	.L2
.L17:
	movl	b(%rip), %eax
	negl	%eax
	movl	%eax, -268(%rbp)
	movl	-268(%rbp), %eax
	movl	%eax, -16(%rbp)
	subq	$4, %rsp
	movl	$.LC29, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC29, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -272(%rbp)
	subq	$4, %rsp
	movl	-16(%rbp), %eax
	movl	%eax, 0(%rsp)
	movl	-16(%rbp), %edi
	call	printi
	addq	$4, %rsp
	movl	%eax, -276(%rbp)
	subq	$4, %rsp
	movl	$.LC30, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC30, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -280(%rbp)
	jmp	.L2
.L18:
	subq	$4, %rsp
	movl	$.LC31, %eax
	movl	%eax, 0(%rsp)
	movl	$.LC31, %edi
	call	prints
	addq	$4, %rsp
	movl	%eax, -284(%rbp)
.L2:
	movl	$1, %eax
	movl	%eax, -288(%rbp)
	movl	-288(%rbp), %eax
	negl	%eax
	movl	%eax, -292(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-292(%rbp), %eax
	jne	.L19
	jmp	.L20
	jmp	.L20
.L20:
	movl	$0, %eax
	movl	%eax, -296(%rbp)
	movl	-296(%rbp), %eax
	leave
	ret
	.size	main, .-main
