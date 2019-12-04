# Author <Sumit Agarwal>
# RollNo <13CS10061>
# Assignment No <1>
# Compilers Laboratory '15 (CS39003)

#################################################################################################################################################################################

##  Note- 
# 1) The macros are work of the prepocessor to replace all instances of MAX here by 20
# 2) The function declrations are also work of the prepocessor to check if the functions defined after main are already declared 
# 3) CFI directives are used for the creation of .eh_frame to unwind stack frames for debugging and exception handling.
# For eg : 
# .cfi_startproc
# .cfi_endproc
# .cfi_def_cfa_offset offset
# .cfi_offset 6, -16
# .cfi_def_cfa_register
# No comments have been attached to such statements 


##  Registers Used : 
# rax       return value from a function
# rbx       callee saved
# rcx       4th argument to a function
# rdx       3rd argument to a function
#           return value from a function
# rsi       2nd argument to a function
# rdi       1st argument to a function
# rbp       callee saved
# rsp       hardware stack pointer

	.file	"ass1_13CS10061.c"                      # file name ass1_13CS10061.c




## Main module 
	.section	.rodata                             # read-only data secition 
.LC0:                                               # label for the f-string- 1st printf
	.string	"Enter the order: "                       
.LC1:                                               # label for the f-string- 1st scanf (for reading the order)
	.string	"%d"                                   
.LC2:                                               # label for the f-string- 2nd printf 
	.string	"Enter matix A in row-major: "
.LC3:                                               # label for the f-string- 3rd printf
	.string	"Enter matix B in row-major: "
.LC4:                                               # label for the f-string- 4th printf 
	.string	"The output matrix is:"
.LC5:                                               # label for the f-string- 2nd scanf (for reading the input of the matrix)
	.string	"%d "
	.text                                           # Code starts
	.globl	main                                    # main is a global name
	.type	main, @function                         # main is a function
main:                                               # main: starts
.LFB0:                                              # label for module
	.cfi_startproc
	pushq	%rbp                                    # save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                              # rbp <-- rsp (set new stack pointer)
	.cfi_def_cfa_register 6
	subq	$4816, %rsp                             # allocate 4816 bytes of memory for three local 20*20 int arrays A,B,C and 3 variables (n,i,j) (3*4*20*20+12) 
	                                                # 4812+4(for allign of 16 in the hardware) -- 4816 should be divisible by 16 
	movl	$.LC0, %edi                             # edi <-- 1st variable of printf (1st printf)
	movl	$0, %eax                                # eax <-- 0
	call	printf                                  # call printf
	leaq	-4812(%rbp), %rax                       # rax <-- (rbp-4812) (&order) 
	movq	%rax, %rsi                              # rsi <-- rax
	movl	$.LC1, %edi                             # edi <-- 1st variable for scanf (1st scanf)
	movl	$0, %eax                                # eax <-- 0
	call	__isoc99_scanf                          # call scanf // moves the value of order in the location (rbp-4812)
	movl	$.LC2, %edi                             # edi <-- 1st variable for printf (2nd printf)
	movl	$0, %eax                                # eax <-- 0
	call	printf                                  # call printf
	movl	-4812(%rbp), %eax                       # eax <-- (rbp-4812) (order 'n' is in eax)
	leaq	-4800(%rbp), %rdx                       # rdx <-- (rbp-4800) //starting of first matrix's memory allocation
	movq	%rdx, %rsi                              # rsi <-- rdx (the matrix 'A' parameter of ReadMatrix)
	movl	%eax, %edi                              # edi <-- eax (the n -'order' parameter of ReadMatrix)
	call	ReadMatrix                              # call ReadMatrix (n,A)
	movl	$.LC3, %edi                             # edi <-- 1st variable for printf (3rd printf)
	movl	$0, %eax								# eax <-- 0
	call	printf                                  # call printf
	movl	-4812(%rbp), %eax                       # eax <-- (rbp-4812) (order 'n' is in eax)
	leaq	-3200(%rbp), %rdx                       # rdx <-- (rbp-3200) // starting of second matrix's memory allocation
	movq	%rdx, %rsi                              # rsi <-- rdx (the matrix 'B' parameter of ReadMatrix)
	movl	%eax, %edi                              # edi <-- eax (the n - 'order' parameter of ReadMatrix)
	call	ReadMatrix                              # call ReadMatrix (n,B)
	movl	-4812(%rbp), %eax                       # eax <-- (rbp-4812) (order 'n' is in eax)                         
	leaq	-1600(%rbp), %rcx                       # rcx <-- (rbp-1600) // starting of final  (C) matrix's memory allocation              
	leaq	-3200(%rbp), %rdx                       # rdx <-- (rbp-3200) // starting of second (B) matrix's memory allocation
	leaq	-4800(%rbp), %rsi                       # rsi <-- (rbp-4800) // starting of first  (A) matrix's memory allocation
	movl	%eax, %edi                              # edi <-- eax (the n- 'order' parameter of MultiplyMatrix)
	call	MultiplyMatrix                          # call MultiplyMatrix
	movl	$.LC4, %edi                             # edi <-- 1st variable of printf (4th printf)
	call	puts                                    # call puts (to print the string)
	movl	$0, -4808(%rbp)                         # (rbp-4808) <-- 0 (i=0)
	jmp	.L2                                         # jump to module .L2 <-- goto line 91
.L5:                                                # execution starts at this module
	movl	$0, -4804(%rbp)                         # (rbp-4804) <-- 0 (j=0)
	jmp	.L3                                         # jump to module .L3
.L4:                                                 
	movl	-4804(%rbp), %eax                       # eax <-- (rbp-4804) (j)
	movslq	%eax, %rcx                              # rcx <--eax (with extended to fit into q (32 bit))
	movl	-4808(%rbp), %eax                       # eax <-- (rbp-4808) (i)
	movslq	%eax, %rdx                              # rdx <--eax (with extended to fit into q (32 bit))
	movq	%rdx, %rax                              # rax <-- rdx 
	salq	$2, %rax                                # rax <-- 4*i (shift by 2 bits)
	addq	%rdx, %rax                              # rax <-- rax + rdx (5*i)
	salq	$2, %rax                                # rax <-- 20*i
	addq	%rcx, %rax                              # rax <-- 20*i + j               
	movl	-1600(%rbp,%rax,4), %eax                # eax <-- data [i][j] // data + 4*rax i.e. (data + 20* 4i + 4j) // MAX is 20 and 2D Matrix is represented in row major form
	movl	%eax, %esi                              # esi <-- eax (2nd parameter of printf)
	movl	$.LC5, %edi                             # edi <-- .LC5 (1st paramter of printf)
	movl	$0, %eax                                # eax <--0
	call	printf                                  # call printf
	addl	$1, -4804(%rbp)                         # j++
.L3:
	movl	-4812(%rbp), %eax                       # eax <-- (rbp-4812) (order 'n')
	cmpl	%eax, -4804(%rbp)                       # compare less (j <-- rbp-4804 ) if (j < n) 
	jl	.L4                                         # jump less to .L4 
	movl	$10, %edi                               # if (j>=n ) edi <-- 10 // out of the inner for loop 
	call	putchar                                 # call putchar where 10 is the code for '\n'
	addl	$1, -4808(%rbp)                         # increment (rbp-4808) i.e. i++ and move to the module .L2
.L2:                                                # execution starts at this module
	movl	-4812(%rbp), %eax                       # eax <-- (rbp-4812) (order 'n')
	cmpl	%eax, -4808(%rbp)                       # compare less (i <-- rbp-4808 ) if (i < n) 
	jl	.L5                                         # jump less to .L5 module
	movl	$0, %eax                                # if (i>=n) eax <-- 0      // out of the outer for loop to return 0
	leave                                           # leave the module main    // remove the stack frame 
	.cfi_def_cfa 7, 8                                
	ret                                             # return from main (return 0)
	.cfi_endproc 




## ReadMatrix module
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"The input matrix is:"                  # label for the f-string 
	.text
	.globl	ReadMatrix                              # ReadMatrix is global
	.type	ReadMatrix, @function                   # ReadMatrix is a function
ReadMatrix:
.LFB1:
	.cfi_startproc
	pushq	%rbp                                    # save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                              # rbp <-- rsp (set new stack pointer)
	.cfi_def_cfa_register 6
	subq	$32, %rsp                               # allocate 32 bytes of memory (two to store the address of the pointer to the matrix and the other for order)
	                                                # two each for i,j
	movl	%edi, -20(%rbp)                         # (rbp-20) <-- edi (n)
	movq	%rsi, -32(%rbp)                         # (rbp-32) <-- rsi (data)
	movl	$0, -8(%rbp)                            # (rbp-8) <-- 0 (i=0)
	jmp	.L8                                         # jump to .L8
.L11:
	movl	$0, -4(%rbp)                            # (rbp-4) <-- 0 (j=0)
	jmp	.L9                                         # jump to .L9
.L10:
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) (i)
	movslq	%eax, %rdx                              # rdx <-- eax 
	movq	%rdx, %rax                              # rax <-- rdx
	salq	$2, %rax                                # rax <-- 4*i
	addq	%rdx, %rax                              # rax <-- 5*i
	salq	$4, %rax                                # rax <-- 16*5*i=80*i (shift 4 implies multiplying by 2^4)
	movq	%rax, %rdx                              # rdx <-- 80i
	movq	-32(%rbp), %rax                         # rax <-- (rbp-32) (data)
	addq	%rax, %rdx                              # rdx <-- data + 80i
	movl	-4(%rbp), %eax                          # eax <-- (rbp-4) (j)
	cltq                                            # rax <-- eax (expand)
	salq	$2, %rax                                # rax <-- 4*j
	addq	%rdx, %rax                              # rax <-- data + 80i +4j // data[i][j]
	movq	%rax, %rsi                              # rsi <-- rsi <-- rax
	movl	$.LC1, %edi                             # edi <-- .LC1 (the first paramter of scanf)
	movl	$0, %eax                                # eax <-- 0
	call	__isoc99_scanf                          # call scanf
	addl	$1, -4(%rbp)                            # (rbp-4) increment i.e. j++
.L9: 
	movl	-4(%rbp), %eax                          # eax <-- (rbp-4)(j)
	cmpl	-20(%rbp), %eax                         # if (j<n)
	jl	.L10                                        # jump less to module .L10
	addl	$1, -8(%rbp)                            # (rbp-8) increment (i++) // out of inner for loop
.L8:
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) (i)
	cmpl	-20(%rbp), %eax                         # if (i<n)
	jl	.L11                                        # jump less to module .L11
	movl	$.LC6, %edi                             # edi <-- .LC6 (1st parameter of printf) // out of outer for loop
	call	puts                                    # call puts
	movl	$0, -8(%rbp)                            # (rbp-8) <-- 0 // i=0
	jmp	.L12                                        # jump to .L12
.L15:
	movl	$0, -4(%rbp)                            # (rbp-4) <-- 0 //
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) // i
	movslq	%eax, %rdx                              # rdx <-- eax + expand 
	movq	%rdx, %rax                              # rax <-- rdx
	salq	$2, %rax                                # rax <-- 4i
	addq	%rdx, %rax                              # rax <-- 5i
	salq	$4, %rax                                # rax <-- 80i
	movq	%rax, %rdx                              # rdx <--- 80i
	movq	-32(%rbp), %rax                         # rax <-- data
	addq	%rax, %rdx                              # rdx <-- data+80i
	movl	-4(%rbp), %eax                          # eax <-- (rbp-4) //j
	cltq                                            # rax <-- eax (expand)
	movl	(%rdx,%rax,4), %eax                     # eax <-- rdx+4*rax (data+80i+4j)
	movl	%eax, %esi                              # esi <-- eax
	movl	$.LC5, %edi                             # edi <-- .LC5 (the first paramter of printf)
	movl	$0, %eax                                # eax <-- 0
	call	printf                                  # call printf 
	addl	$1, -4(%rbp)                            # j++
.L13:
	movl	-4(%rbp), %eax                          # eax <-- j
	cmpl	-20(%rbp), %eax                         # if (j < n)
	jl	.L14                                        # jump less to .L14
	movl	$10, %edi                               # edi <-- 10 ('\n')
	call	putchar                                 # call putchar 
	addl	$1, -8(%rbp)                            # i++
.L12:
	movl	-8(%rbp), %eax                          # eax <-- i
	cmpl	-20(%rbp), %eax                         # if (i<n)
	jl	.L15                                        # jump less to .L15
	leave                                           # remove the stack frame
	.cfi_def_cfa 7, 8
	ret                                             # return from the function
	.cfi_endproc  




## TransposeMatrix Module
.LFE1:
	.size	ReadMatrix, .-ReadMatrix
	.section	.rodata
.LC7:
	.string	"The transposed matrix is:"             # label for the f-string 
	.text
	.globl	TransposeMatrix                         # TransposeMatrix is global
	.type	TransposeMatrix, @function              # TransposeMatrix is a function
TransposeMatrix:
.LFB2:
	.cfi_startproc
	pushq	%rbp                                    # save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                              # rbp <-- rsp (set new stack pointer)
	.cfi_def_cfa_register 6
	subq	$32, %rsp                               # allocate 32 bytes of memory
	movl	%edi, -20(%rbp)                         # (rbp-20) <-- edi (order 'n') 
	movq	%rsi, -32(%rbp)                         # (rbp-32) <-- rsi (data)
	movl	$0, -12(%rbp)                           # (rbp-12) <-- 0 //i=0
	jmp	.L17                                        # jump to module .L17
.L20:
	movl	$0, -8(%rbp)                            # (rbp-8) <-- 0 // j=0
	jmp	.L18                                        # jump to module .L18
.L19:
	movl	-12(%rbp), %eax                         # eax <-- (rbp-12) // i
	movslq	%eax, %rdx                             
	movq	%rdx, %rax              
	salq	$2, %rax
	addq	%rdx, %rax                              # rax <-- 5i
	salq	$4, %rax            
	movq	%rax, %rdx                              # rdx <-- 80i
	movq	-32(%rbp), %rax                         # rax <-- data
	addq	%rax, %rdx                              # rdx <-- data+80i
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) // j
	cltq                 
	movl	(%rdx,%rax,4), %eax                     # eax <-- data[i][j]
	movl	%eax, -4(%rbp)                          # (rbp-4) <-- data[i][j] //temp=data[i][j]
	movl	-12(%rbp), %eax                         # eax <-- (rbp-12) //i
	movslq	%eax, %rdx                              
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax                                # rax <-- 80i
	movq	%rax, %rdx                              # rdx <-- 80i
	movq	-32(%rbp), %rax                         # rax <-- data
	leaq	(%rdx,%rax), %rcx                       # rcx <-- data+80i
	movl	-8(%rbp), %eax                          # eax <-- j
	movslq	%eax, %rdx                              # rdx <-- j
	movq	%rdx, %rax 
	salq	$2, %rax                                # rax <-- 4j 
	addq	%rdx, %rax                              # rax <-- 5j
	salq	$4, %rax                                # rax <-- 80j 
	movq	%rax, %rdx                              # rdx <-- 80j
	movq	-32(%rbp), %rax                         # rax <-- data
	addq	%rax, %rdx                              # rdx <-- data + 80j
	movl	-12(%rbp), %eax                         # eax <-- (rbp-12) // i
	cltq                                            # rdx <-- i
	movl	(%rdx,%rax,4), %edx                     # edx <-- data +80j +4i 
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) //j
	cltq                                            # rax <-- j
	movl	%edx, (%rcx,%rax,4)                     # data+80i+4j = data+80j+4i // data[i][j]=data[j][i]
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) //j
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax                                # rax <-- 80j
	movq	%rax, %rdx                              # rdx <-- 80j
	movq	-32(%rbp), %rax                         # rax <-- data
	leaq	(%rdx,%rax), %rcx                       # rcx <-- data + 80j
	movl	-12(%rbp), %eax                         # eax <-- i
	cltq                                            # rax <-- i
 	movl	-4(%rbp), %edx                          # edx <-- (rbp-4) //temp
	movl	%edx, (%rcx,%rax,4)                     # rcx+ rax*4 <-- edx // data+80j+4i=temp OR data[j][i]=temp
	addl	$1, -8(%rbp)                            # j++
.L18:
	movl	-8(%rbp), %eax                          # eax <-- j
	cmpl	-12(%rbp), %eax                         # if (j<i)
	jl	.L19                                        # jump to .L19
	addl	$1, -12(%rbp)                           # inner loop over i++
.L17:
	movl	-12(%rbp), %eax                         # eax <-- i
	cmpl	-20(%rbp), %eax                         # if (i<n)
	jl	.L20                                        # jump less to module .L20
	movl	$.LC7, %edi                             # edi <-- .LC7 (1st paramter of printf)
	call	puts                                    # call puts
	movl	$0, -12(%rbp)                           # (rbp-12) <-- 0 // i=0
	jmp	.L21                                        # jump to .L21
.L24:
	movl	$0, -8(%rbp)							# (rbp-8) <-- 0 // j=0		
	jmp	.L22									    # jump to .L22
.L23:
	movl	-12(%rbp), %eax      				    # eax <-- (rbp-1 2) // i
	movslq	%eax, %rdx						        # rdx <-- eax + expand 
	movq	%rdx, %rax						        # rax <-- rdx
	salq	$2, %rax						        # rax <-- 4i
	addq	%rdx, %rax						        # rax <-- 5i
	salq	$4, %rax						        # rax <-- 80i
	movq	%rax, %rdx						        # rdx <--- 80i
	movq	-32(%rbp), %rax						    # rax <-- data
	addq	%rax, %rdx						        # rdx <-- data+80i
	movl	-8(%rbp), %eax						    # eax <-- (rbp-8) //j
	cltq						         			# rax <-- eax (expand)
	movl	(%rdx,%rax,4), %eax				        # eax <-- rdx+4*rax (data+80i+4j)
	movl	%eax, %esi						        # esi <-- eax
	movl	$.LC5, %edi						        # edi <-- .LC5 (the first paramter of printf)
	movl	$0, %eax						        # eax <-- 0
	call	printf						         	# call printf 
	addl	$1, -8(%rbp)						    # j++
.L22: 
	movl	-8(%rbp), %eax                          # eax <-- j
	cmpl	-20(%rbp), %eax                         # if (j < n)
	jl	.L23                                        # jump to .L23
	movl	$10, %edi                               # edi <-- 10 // for '\n'
	call	putchar									# putchar ('\n')		
	addl	$1, -12(%rbp)						    # (rbp-12) ++ // i++			
.L21:											
	movl	-12(%rbp), %eax							# eax <-- i				
	cmpl	-20(%rbp), %eax							# if (i<n)				
	jl	.L24										# jump to .L24	
	leave											# remove the stack frame
	.cfi_def_cfa 7, 8											
	ret											    # return from the function
	.cfi_endproc




## VectorMultiply Module
.LFE2:											
	.size	TransposeMatrix, .-TransposeMatrix											
	.globl	VectorMultiply							# VectorMultiply is global
	.type	VectorMultiply, @function				# VectorMultiply is a function							
VectorMultiply:											
.LFB3:											
	.cfi_startproc											
	pushq	%rbp                                    # save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                              # rbp <-- rsp (set new stack pointer) // can work with the leftover memory in the previous stack frame
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)                         # (rbp-20) <-- edi // n           
	movq	%rsi, -32(%rbp)                         # (rbp-32) <-- rsi // address of L
	movq	%rdx, -40(%rbp)                         # (rbp-40) <-- rdx // address of R
	movl	$0, -4(%rbp)                            # (rbp-4) <--0 // result= 0
	movl	$0, -8(%rbp)                            # (rbp-8) <--0 // i=0
	jmp	.L26                                        # jump to .L26
.L27:
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) // i
	cltq                                            # expand to rax
	leaq	0(,%rax,4), %rdx                        # rdx <-- 4*(rax)  // 4i
	movq	-32(%rbp), %rax                         # rax <-- (rbp-32) // L
	addq	%rdx, %rax                              # rax <-- rax + rdx // L +4*i
	movl	(%rax), %edx                            # edx <-- (rax) //L[i]
	movl	-8(%rbp), %eax                          # eax <-- (rbp-8) //i
	cltq                                            # expand
	leaq	0(,%rax,4), %rcx                        # rcx <-- 4*(rax) // 4i
	movq	-40(%rbp), %rax                         # rax <-- (rbp-40) // R
	addq	%rcx, %rax                              # rax <-- rax + rcx // R + 4*i
	movl	(%rax), %eax                            # eax <-- (rax) // R[i]
	imull	%edx, %eax                              # eax <-- eax * edx // L[i] * R[i] (multiplies)
	addl	%eax, -4(%rbp)                          # (rbp-4) <-- (rbp-4) + eax // result += L[i] * R[i]
	addl	$1, -8(%rbp)                            # (rbp-8) ++ // i++
.L26:
	movl	-8(%rbp), %eax                          # eax <-- i
	cmpl	-20(%rbp), %eax                         # if (i<n)
	jl	.L27                                        # jump to .L27
	movl	-4(%rbp), %eax                          # eax <-- (rbp-4) // result stored in eax  (out of the loop)
	popq	%rbp                                    # pop the stack frame
	.cfi_def_cfa 7, 8
	ret                                             # return 
	.cfi_endproc




## MultiplyMatrix MOdule
.LFE3:
	.size	VectorMultiply, .-VectorMultiply
	.globl	MultiplyMatrix                          # MultiplyMatrix is global
	.type	MultiplyMatrix, @function               # MultiplyMatrix is a function
MultiplyMatrix:
.LFB4:
	.cfi_startproc
	pushq	%rbp                                    # save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                              # rbp <-- rsp (set new stack pointer)
	.cfi_def_cfa_register 6
	pushq	%rbx                                    # save rbx
	subq	$56, %rsp                               # rsp<-- rsp-56 (allocate 56 bytes of memory) 
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)                         # (rbp-36) <-- edi // n
	movq	%rsi, -48(%rbp)                         # (rbp-48) <-- rsi // Address of Matrix L for the function
	movq	%rdx, -56(%rbp)                         # (rbp-56) <-- rdx // Address of Matrix R for the function (to be transposed)
 	movq	%rcx, -64(%rbp)                         # (rbp-64) <-- rcx // Address of Matrix M to store the Multiplied Matrix
	movq	-56(%rbp), %rdx                         # rdx <-- (rbp-56) 
	movl	-36(%rbp), %eax                         # eax <-- (rbp-36) 
	movq	%rdx, %rsi                              # rsi <-- rdx // parameter data of TransposeMatrix 
	movl	%eax, %edi                              # edi <-- eax // parameter n of TransposeMatrix
	call	TransposeMatrix                         # call Transpose Matrix
	movl	$0, -24(%rbp)                           # (rbp-24) <-- 0 // i=0
	jmp	.L30                                        # jump to module .L30
.L33:
	movl	$0, -20(%rbp)                           # (rbp-20) <-- 0 // j=0
	jmp	.L31                                        # jump to module .L31
.L32:
	movl	-24(%rbp), %eax                         # eax <-- (rbp-24) //i
	movslq	%eax, %rdx                              # rdx <-- i
	movq	%rdx, %rax
	salq	$2, %rax                                # rax <-- 4i
	addq	%rdx, %rax                              # rax <-- 5i
	salq	$4, %rax                                # rax <-- 16*5i
	movq	%rax, %rdx                              # rdx <-- 80i
	movq	-64(%rbp), %rax                         # rax <-- (rbp-64) // M
	leaq	(%rdx,%rax), %rbx                       # rbx <-- M + 80i
	movl	-20(%rbp), %eax                         # eax <-- (rbp-20) //j
	movslq	%eax, %rdx           
	movq	%rdx, %rax 
	salq	$2, %rax 
	addq	%rdx, %rax
	salq	$4, %rax                                # rax <-- 80*j
	movq	%rax, %rdx                              # rdx <-- 80j
	movq	-56(%rbp), %rax                         # rax <-- (rbp-56) // R
	addq	%rdx, %rax                              # rax <-- R + 80j
	movq	%rax, %rsi                              # rsi <-- rax
	movl	-24(%rbp), %eax                         # eax <-- i
	movslq	%eax, %rdx 
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx                              # rdx <-- 80i
	movq	-48(%rbp), %rax                         # rax <-- (rbp-48) // L
	addq	%rdx, %rax
	movq	%rax, %rcx                              # rcx <-- L+80i
	movl	-36(%rbp), %eax                         # eax <-- (rbp-36) //n
	movq	%rsi, %rdx                              # rdx <-- R+80j // &R[j][0] // parameter R[] of VectorMultiply
	movq	%rcx, %rsi                              # rsi <-- L+80i // &L[i][0] // parameter L[] of VectorMultiply
	movl	%eax, %edi                              # edi <-- n // parameter n of VectorMultiply
	call	VectorMultiply                          # call VectorMultiply (return result in eax)
	movl	-20(%rbp), %edx                         # edx <-- (rbp-20) //j
	movslq	%edx, %rdx                              # rdx <-- edx (expand)              
	movl	%eax, (%rbx,%rdx,4)                     # rbx <-- rbx + 4*rdx (i.e (rbx <-- M + 80i + 4j)<-- eax) // M[i][j] = result of VectorMultiply 
	addl	$1, -20(%rbp)                           # (rbp-20) ++ // j++
.L31:
	movl	-20(%rbp), %eax                        
	cmpl	-36(%rbp), %eax                         # if (j<n)
	jl	.L32                                        # jump to module .L32
	addl	$1, -24(%rbp)                           # i++ (out of the inner loop)
.L30:
	movl	-24(%rbp), %eax  
	cmpl	-36(%rbp), %eax                         # if (i<n)
	jl	.L33                                        # jump to module .L33
	addq	$56, %rsp                               # rsp <-- rsp+56 (unwind the stack fram)
	popq	%rbx                                    # pop the rbx
	popq	%rbp                                    # pop the base pointer 
	.cfi_def_cfa 7, 8
	ret                                             # return from the function (code ends)
	.cfi_endproc
.LFE4:
	.size	MultiplyMatrix, .-MultiplyMatrix
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits        




#################################################################################################################################################################################
