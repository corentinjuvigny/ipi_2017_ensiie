	.file	"exo1.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"Not connected"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-64(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	movl	$0, -48(%rbp)
	jmp	.L2
.L5:
	movl	-64(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rax, (%rdx)
	movl	$0, -44(%rbp)
	jmp	.L3
.L4:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -44(%rbp)
.L3:
	movl	-64(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jl	.L4
	addl	$1, -48(%rbp)
.L2:
	movl	-64(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jl	.L5
	leaq	-60(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	-56(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-60(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -60(%rbp)
	movl	-56(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -56(%rbp)
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %edx
	movl	-64(%rbp), %esi
	leaq	-52(%rbp), %r8
	leaq	-40(%rbp), %rdi
	movq	-32(%rbp), %rax
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	creation_Vliste_1
	movl	-64(%rbp), %edi
	movl	-56(%rbp), %ecx
	movl	-52(%rbp), %edx
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	parcours_en_largeur_1
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L6
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	jmp	.L7
.L6:
	movl	-52(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	.L8
.L9:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	stdout(%rip), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	subl	$1, -48(%rbp)
.L8:
	cmpl	$0, -48(%rbp)
	jns	.L9
.L7:
	movl	$0, -48(%rbp)
	jmp	.L10
.L11:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	addl	$1, -48(%rbp)
.L10:
	movl	-64(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jl	.L11
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.globl	isInprec_1
	.type	isInprec_1, @function
isInprec_1:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L15
.L18:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-32(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	isInl@PLT
	cmpl	$1, %eax
	jne	.L16
	movl	$1, %eax
	jmp	.L17
.L16:
	addl	$1, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L18
	movl	$0, %eax
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	isInprec_1, .-isInprec_1
	.globl	creation_Vliste_1
	.type	creation_Vliste_1, @function
creation_Vliste_1:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movl	%edx, -80(%rbp)
	movl	%ecx, -84(%rbp)
	movq	%r8, -96(%rbp)
	movq	%r9, -104(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	-80(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	$1, -48(%rbp)
	movl	-76(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	movl	$0, %eax
	call	initl@PLT
	movq	%rax, -40(%rbp)
	movl	-80(%rbp), %edx
	leaq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	push@PLT
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L20
.L28:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$0, %eax
	call	initl@PLT
	movq	%rax, (%rbx)
	movl	-48(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	testq	%rax, %rax
	jne	.L23
	movl	-76(%rbp), %eax
	leal	1(%rax), %edx
	movq	-104(%rbp), %rax
	movl	%edx, (%rax)
	movq	-96(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L19
.L27:
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -44(%rbp)
	movl	$0, -52(%rbp)
	jmp	.L24
.L26:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	$1, %eax
	jne	.L25
	movl	-52(%rbp), %edx
	movl	-48(%rbp), %ecx
	movq	-32(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	isInprec_1
	testl	%eax, %eax
	jne	.L25
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	push@PLT
.L25:
	addl	$1, -52(%rbp)
.L24:
	movl	-52(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L26
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
.L23:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	isEmptyl@PLT
	testl	%eax, %eax
	je	.L27
	addl	$1, -48(%rbp)
.L20:
	movl	-48(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-84(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	isInl@PLT
	testl	%eax, %eax
	je	.L28
	movl	-48(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jg	.L28
	movq	-96(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-104(%rbp), %rax
	movl	-48(%rbp), %edx
	movl	%edx, (%rax)
.L19:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	creation_Vliste_1, .-creation_Vliste_1
	.globl	parcours_en_largeur_1
	.type	parcours_en_largeur_1, @function
parcours_en_largeur_1:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	%edx, -52(%rbp)
	movl	%ecx, -56(%rbp)
	movl	%r8d, -60(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	-52(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jle	.L31
	movl	$0, %eax
	jmp	.L37
.L31:
	movl	-52(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	-56(%rbp), %edx
	movl	%edx, (%rax)
	movl	-52(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	.L33
.L36:
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	copyl@PLT
	movq	%rax, -24(%rbp)
	jmp	.L34
.L35:
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	pull@PLT
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-52(%rbp), %eax
	subl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rcx
	movq	-16(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	$1, %eax
	jne	.L34
	movl	-52(%rbp), %eax
	subl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movl	-28(%rbp), %eax
	movl	%eax, (%rdx)
.L34:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	isEmptyl@PLT
	testl	%eax, %eax
	je	.L35
	subl	$1, -32(%rbp)
.L33:
	cmpl	$0, -32(%rbp)
	jg	.L36
	movq	-16(%rbp), %rax
.L37:
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L38
	call	__stack_chk_fail@PLT
.L38:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	parcours_en_largeur_1, .-parcours_en_largeur_1
	.ident	"GCC: (GNU) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
