	.file	"sort_q.c"
	.text
	.p2align 4
	.globl	compare_ints
	.type	compare_ints, @function
compare_ints:
.LFB11:
	.cfi_startproc
	movl	(%rsi), %eax
	cmpl	%eax, (%rdi)
	movl	$-1, %edx
	setg	%al
	movzbl	%al, %eax
	cmovl	%edx, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	compare_ints, .-compare_ints
	.p2align 4
	.globl	sort_q
	.type	sort_q, @function
sort_q:
.LFB12:
	.cfi_startproc
	movslq	%esi, %rsi
	leaq	compare_ints(%rip), %rcx
	movl	$4, %edx
	jmp	qsort@PLT
	.cfi_endproc
.LFE12:
	.size	sort_q, .-sort_q
	.p2align 4
	.globl	matching
	.type	matching, @function
matching:
.LFB13:
	.cfi_startproc
	movq	%rsi, %r8
	testl	%edx, %edx
	jle	.L10
	movslq	%edx, %rsi
	xorl	%ecx, %ecx
	xorl	%r9d, %r9d
	salq	$2, %rsi
	.p2align 5
	.p2align 4
	.p2align 3
.L9:
	movl	(%r8,%rcx), %eax
	cmpl	%eax, (%rdi,%rcx)
	jne	.L8
	addl	$1, %r9d
.L8:
	addq	$4, %rcx
	cmpq	%rcx, %rsi
	jne	.L9
	movl	%edx, %eax
	subl	%r9d, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE13:
	.size	matching, .-matching
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
