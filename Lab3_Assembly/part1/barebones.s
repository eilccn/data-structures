	.file	"tool.c"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$4160, %rsp             # imm = 0x1040
	leaq	.L.str, %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	8(%rsi), %rdi
	movq	%rax, %rsi
	callq	fopen
	movl	$0, %esi
	movabsq	$4000, %rdx             # imm = 0xFA0
	leaq	-4112(%rbp), %rdi
	leaq	.Lmain.words, %rcx
	movabsq	$80, %r8
	leaq	-112(%rbp), %r9
	movq	%rax, -24(%rbp)
	movq	%rdi, -4136(%rbp)       # 8-byte Spill
	movq	%r9, %rdi
	movl	%esi, -4140(%rbp)       # 4-byte Spill
	movq	%rcx, %rsi
	movq	%rdx, -4152(%rbp)       # 8-byte Spill
	movq	%r8, %rdx
	callq	memcpy
	movq	-4136(%rbp), %rax       # 8-byte Reload
	movq	%rax, %rdi
	movl	-4140(%rbp), %esi       # 4-byte Reload
	movq	-4152(%rbp), %rdx       # 8-byte Reload
	callq	memset
	movl	$0, -4116(%rbp)
.LBB0_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
                                        #     Child Loop BB0_11 Depth 2
	leaq	.L.str10, %rsi
	leaq	-28(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movb	$0, %al
	callq	__isoc99_fscanf
	cmpl	$-1, %eax
	je	.LBB0_15
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	$0, -4120(%rbp)
.LBB0_3:                                #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	-4120(%rbp), %rax
	cmpq	$0, -112(%rbp,%rax,8)
	je	.LBB0_8
# BB#4:                                 #   in Loop: Header=BB0_3 Depth=2
	leaq	-28(%rbp), %rsi
	movslq	-4120(%rbp), %rax
	movq	-112(%rbp,%rax,8), %rdi
	callq	strcmp
	cmpl	$0, %eax
	jne	.LBB0_6
# BB#5:                                 #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_8
.LBB0_6:                                #   in Loop: Header=BB0_3 Depth=2
	jmp	.LBB0_7
.LBB0_7:                                #   in Loop: Header=BB0_3 Depth=2
	movl	-4120(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4120(%rbp)
	jmp	.LBB0_3
.LBB0_8:                                #   in Loop: Header=BB0_1 Depth=1
	movslq	-4120(%rbp), %rax
	cmpq	$0, -112(%rbp,%rax,8)
	je	.LBB0_10
# BB#9:                                 #   in Loop: Header=BB0_1 Depth=1
	movslq	-4120(%rbp), %rax
	movl	-4112(%rbp,%rax,4), %ecx
	addl	$1, %ecx
	movl	%ecx, -4112(%rbp,%rax,4)
	jmp	.LBB0_1
.LBB0_10:                               #   in Loop: Header=BB0_1 Depth=1
	movl	$0, -4124(%rbp)
.LBB0_11:                               #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movslq	-4124(%rbp), %rax
	cmpq	$0, -112(%rbp,%rax,8)
	je	.LBB0_14
# BB#12:                                #   in Loop: Header=BB0_11 Depth=2
	leaq	.L.str11, %rdi
	movslq	-4124(%rbp), %rax
	movq	-112(%rbp,%rax,8), %rsi
	movslq	-4124(%rbp), %rax
	movl	-4112(%rbp,%rax,4), %edx
	movb	$0, %al
	callq	printf
	movslq	-4124(%rbp), %rsi
	movq	-112(%rbp,%rsi,8), %rdi
	movl	%eax, -4156(%rbp)       # 4-byte Spill
	callq	free
# BB#13:                                #   in Loop: Header=BB0_11 Depth=2
	movl	-4124(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4124(%rbp)
	jmp	.LBB0_11
.LBB0_14:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_1
.LBB0_15:
	movq	-24(%rbp), %rdi
	callq	fclose
	movl	$0, %ecx
	movl	%eax, -4160(%rbp)       # 4-byte Spill
	movl	%ecx, %eax
	addq	$4160, %rsp             # imm = 0x1040
	popq	%rbp
	ret
.Ltmp5:
	.size	main, .Ltmp5-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"r"
	.size	.L.str, 2

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"ADD"
	.size	.L.str1, 4

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"SUB"
	.size	.L.str2, 4

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"MUL"
	.size	.L.str3, 4

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	"DIV"
	.size	.L.str4, 4

	.type	.L.str5,@object         # @.str5
.L.str5:
	.asciz	"MOV"
	.size	.L.str5, 4

	.type	.L.str6,@object         # @.str6
.L.str6:
	.asciz	"LEA"
	.size	.L.str6, 4

	.type	.L.str7,@object         # @.str7
.L.str7:
	.asciz	"PUS"
	.size	.L.str7, 4

	.type	.L.str8,@object         # @.str8
.L.str8:
	.asciz	"POP"
	.size	.L.str8, 4

	.type	.L.str9,@object         # @.str9
.L.str9:
	.asciz	"RET"
	.size	.L.str9, 4

	.type	.Lmain.words,@object    # @main.words
	.section	.rodata,"a",@progbits
	.align	16
.Lmain.words:
	.quad	.L.str1
	.quad	.L.str2
	.quad	.L.str3
	.quad	.L.str4
	.quad	.L.str5
	.quad	.L.str6
	.quad	.L.str7
	.quad	.L.str8
	.quad	.L.str9
	.quad	0
	.size	.Lmain.words, 80

	.type	.L.str10,@object        # @.str10
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str10:
	.asciz	"%s"
	.size	.L.str10, 3

	.type	.L.str11,@object        # @.str11
.L.str11:
	.asciz	"%s = %d\n"
	.size	.L.str11, 9


	.ident	"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"
	.section	".note.GNU-stack","",@progbits
