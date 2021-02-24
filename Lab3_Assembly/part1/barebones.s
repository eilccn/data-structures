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
	subq	$272, %rsp              # imm = 0x110
	leaq	.L.str, %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	8(%rsi), %rdi
	movq	%rax, %rsi
	callq	fopen
	leaq	.Lmain.words, %rsi
	movabsq	$80, %rdx
	leaq	-176(%rbp), %rdi
	movq	%rax, -24(%rbp)
	callq	memcpy
	movl	$0, -180(%rbp)
	movl	$0, -184(%rbp)
	movl	$0, -188(%rbp)
	movl	$0, -192(%rbp)
	movl	$0, -196(%rbp)
	movl	$0, -200(%rbp)
	movl	$0, -204(%rbp)
	movl	$0, -208(%rbp)
	movl	$0, -212(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	leaq	.L.str10, %rsi
	leaq	-96(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movb	$0, %al
	callq	__isoc99_fscanf
	cmpl	$-1, %eax
	je	.LBB0_29
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str1, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_4
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-180(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -180(%rbp)
	jmp	.LBB0_28
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str2, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_6
# BB#5:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-184(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -184(%rbp)
	jmp	.LBB0_27
.LBB0_6:                                #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str3, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_8
# BB#7:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-188(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -188(%rbp)
	jmp	.LBB0_26
.LBB0_8:                                #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str4, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_10
# BB#9:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-192(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -192(%rbp)
	jmp	.LBB0_25
.LBB0_10:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str5, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_12
# BB#11:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-196(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -196(%rbp)
	jmp	.LBB0_24
.LBB0_12:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str6, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_14
# BB#13:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-200(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -200(%rbp)
	jmp	.LBB0_23
.LBB0_14:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str7, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_16
# BB#15:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-204(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -204(%rbp)
	jmp	.LBB0_22
.LBB0_16:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str8, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_18
# BB#17:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-208(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -208(%rbp)
	jmp	.LBB0_21
.LBB0_18:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str9, %rsi
	leaq	-96(%rbp), %rdi
	callq	strstr
	cmpq	$0, %rax
	je	.LBB0_20
# BB#19:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-212(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -212(%rbp)
.LBB0_20:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_21
.LBB0_21:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_22
.LBB0_22:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_23
.LBB0_23:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_24
.LBB0_24:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_25
.LBB0_25:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_26
.LBB0_26:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_27
.LBB0_27:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_28
.LBB0_28:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_1
.LBB0_29:
	movq	-24(%rbp), %rdi
	callq	fclose
	leaq	.L.str11, %rdi
	movl	-180(%rbp), %esi
	movl	%eax, -224(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str12, %rdi
	movl	-184(%rbp), %esi
	movl	%eax, -228(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str13, %rdi
	movl	-188(%rbp), %esi
	movl	%eax, -232(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str14, %rdi
	movl	-192(%rbp), %esi
	movl	%eax, -236(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str15, %rdi
	movl	-196(%rbp), %esi
	movl	%eax, -240(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str16, %rdi
	movl	-200(%rbp), %esi
	movl	%eax, -244(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str17, %rdi
	movl	-204(%rbp), %esi
	movl	%eax, -248(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str18, %rdi
	movl	-208(%rbp), %esi
	movl	%eax, -252(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str19, %rdi
	movl	-212(%rbp), %esi
	movl	%eax, -256(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str20, %rdi
	movl	-180(%rbp), %esi
	addl	-184(%rbp), %esi
	addl	-188(%rbp), %esi
	addl	-192(%rbp), %esi
	addl	-196(%rbp), %esi
	addl	-200(%rbp), %esi
	addl	-204(%rbp), %esi
	addl	-208(%rbp), %esi
	addl	-212(%rbp), %esi
	movl	%esi, -216(%rbp)
	movl	-216(%rbp), %esi
	movl	%eax, -260(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str21, %rdi
	movl	-180(%rbp), %esi
	shll	$0, %esi
	movl	-184(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	-188(%rbp), %ecx
	shll	$1, %ecx
	addl	%ecx, %esi
	movl	-192(%rbp), %ecx
	shll	$2, %ecx
	addl	%ecx, %esi
	movl	-196(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	-200(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	-204(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	-208(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	-212(%rbp), %ecx
	shll	$0, %ecx
	addl	%ecx, %esi
	movl	%esi, -220(%rbp)
	movl	-220(%rbp), %esi
	movl	%eax, -264(%rbp)        # 4-byte Spill
	movb	$0, %al
	callq	printf
	movl	$0, %ecx
	movl	%eax, -268(%rbp)        # 4-byte Spill
	movl	%ecx, %eax
	addq	$272, %rsp              # imm = 0x110
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
	.asciz	"add"
	.size	.L.str1, 4

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"sub"
	.size	.L.str2, 4

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"mul"
	.size	.L.str3, 4

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	"div"
	.size	.L.str4, 4

	.type	.L.str5,@object         # @.str5
.L.str5:
	.asciz	"mov"
	.size	.L.str5, 4

	.type	.L.str6,@object         # @.str6
.L.str6:
	.asciz	"lea"
	.size	.L.str6, 4

	.type	.L.str7,@object         # @.str7
.L.str7:
	.asciz	"push"
	.size	.L.str7, 5

	.type	.L.str8,@object         # @.str8
.L.str8:
	.asciz	"pop"
	.size	.L.str8, 4

	.type	.L.str9,@object         # @.str9
.L.str9:
	.asciz	"ret"
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
	.asciz	"ADD %d\n"
	.size	.L.str11, 8

	.type	.L.str12,@object        # @.str12
.L.str12:
	.asciz	"SUB %d\n"
	.size	.L.str12, 8

	.type	.L.str13,@object        # @.str13
.L.str13:
	.asciz	"MUL %d\n"
	.size	.L.str13, 8

	.type	.L.str14,@object        # @.str14
.L.str14:
	.asciz	"DIV %d\n"
	.size	.L.str14, 8

	.type	.L.str15,@object        # @.str15
.L.str15:
	.asciz	"MOV %d\n"
	.size	.L.str15, 8

	.type	.L.str16,@object        # @.str16
.L.str16:
	.asciz	"LEA %d\n"
	.size	.L.str16, 8

	.type	.L.str17,@object        # @.str17
.L.str17:
	.asciz	"PUSH %d\n"
	.size	.L.str17, 9

	.type	.L.str18,@object        # @.str18
.L.str18:
	.asciz	"POP %d\n"
	.size	.L.str18, 8

	.type	.L.str19,@object        # @.str19
.L.str19:
	.asciz	"RET %d\n"
	.size	.L.str19, 8

	.type	.L.str20,@object        # @.str20
.L.str20:
	.asciz	"Total Instructions %d"
	.size	.L.str20, 22

	.type	.L.str21,@object        # @.str21
.L.str21:
	.asciz	"Total Cycles %d"
	.size	.L.str21, 16


	.ident	"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"
	.section	".note.GNU-stack","",@progbits
