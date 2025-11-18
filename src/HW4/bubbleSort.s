	.file	"bubbleSort.c"
	.text
	.p2align 4
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB11:
	.cfi_startproc
	movq	%rdi, %r9
	cmpl	$1, %esi
	jle	.L1
	leal	-2(%rsi), %r8d
	leaq	4(%rdi), %r10
	.p2align 4
	.p2align 3
.L6:
	movl	%r8d, %edx
	movq	%r9, %rax
	xorl	%edi, %edi
	leaq	(%r10,%rdx,4), %rsi
	.p2align 6
	.p2align 4
	.p2align 3
.L4:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %edx
	movd	%xmm1, %ecx
	cmpl	%edx, %ecx
	jge	.L3
	pshufd	$225, %xmm0, %xmm0
	movl	$1, %edi
	movq	%xmm0, (%rax)
.L3:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L4
	testb	%dil, %dil
	je	.L1
	subl	$1, %r8d
	jnb	.L6
.L1:
	ret
	.cfi_endproc
.LFE11:
	.size	bubbleSort, .-bubbleSort
	.p2align 4
	.globl	matching
	.type	matching, @function
matching:
.LFB12:
	.cfi_startproc
	movq	%rsi, %r8
	testl	%edx, %edx
	jle	.L17
	movslq	%edx, %rsi
	xorl	%ecx, %ecx
	xorl	%r9d, %r9d
	salq	$2, %rsi
	.p2align 5
	.p2align 4
	.p2align 3
.L16:
	movl	(%r8,%rcx), %eax
	cmpl	%eax, (%rdi,%rcx)
	jne	.L15
	addl	$1, %r9d
.L15:
	addq	$4, %rcx
	cmpq	%rcx, %rsi
	jne	.L16
	movl	%edx, %eax
	subl	%r9d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE12:
	.size	matching, .-matching
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
