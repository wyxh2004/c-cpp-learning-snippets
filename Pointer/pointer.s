	.file	"pointer.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 0 "F:/Algorithm/Pointer" "pointer.c"
	.globl	blah
	.def	blah;	.scl	2;	.type	32;	.endef
	.seh_proc	blah
blah:
.LFB0:
	.file 1 "pointer.c"
	.loc 1 25 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	.loc 1 30 8
	leaq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 32 12
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	.loc 1 32 7
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	.loc 1 33 7
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	.loc 1 34 9
	movq	-8(%rbp), %rax
	.loc 1 34 7
	movl	%eax, -12(%rbp)
	.loc 1 35 1
	nop
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.seh_endproc
.Letext0:
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0x156
	.word	0x5
	.byte	0x1
	.byte	0x8
	.secrel32	.Ldebug_abbrev0
	.uleb128 0x6
	.ascii "GNU C17 13.2.0 -mtune=generic -march=x86-64 -g\0"
	.byte	0x1d
	.secrel32	.LASF0
	.secrel32	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.ascii "a\0"
	.byte	0x4
	.byte	0x1
	.long	0x6e
	.uleb128 0x1
	.ascii "f1\0"
	.byte	0x3
	.byte	0x9
	.long	0x6e
	.byte	0
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x2
	.ascii "b\0"
	.byte	0x8
	.byte	0x6
	.long	0x96
	.uleb128 0x1
	.ascii "_aa\0"
	.byte	0x8
	.byte	0xe
	.long	0x59
	.byte	0
	.uleb128 0x1
	.ascii "f2\0"
	.byte	0x9
	.byte	0x9
	.long	0x6e
	.byte	0x4
	.byte	0
	.uleb128 0x2
	.ascii "c\0"
	.byte	0x10
	.byte	0xc
	.long	0xb7
	.uleb128 0x1
	.ascii "_bb\0"
	.byte	0xe
	.byte	0xe
	.long	0x75
	.byte	0
	.uleb128 0x1
	.ascii "f3\0"
	.byte	0xf
	.byte	0xa
	.long	0xb7
	.byte	0x8
	.byte	0
	.uleb128 0x7
	.long	0xe1
	.long	0xc7
	.uleb128 0x8
	.long	0xc7
	.byte	0x7
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x2
	.ascii "d\0"
	.byte	0x18
	.byte	0x12
	.long	0x10a
	.uleb128 0x1
	.ascii "_cc\0"
	.byte	0x14
	.byte	0xe
	.long	0x96
	.byte	0
	.uleb128 0x1
	.ascii "f4\0"
	.byte	0x15
	.byte	0xa
	.long	0x10a
	.byte	0x10
	.byte	0
	.uleb128 0x5
	.long	0x6e
	.uleb128 0x9
	.ascii "blah\0"
	.byte	0x1
	.byte	0x18
	.byte	0x6
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x154
	.uleb128 0x4
	.ascii "v\0"
	.byte	0x1a
	.byte	0xe
	.long	0xe9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x4
	.ascii "pv\0"
	.byte	0x1b
	.byte	0xf
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x4
	.ascii "j\0"
	.byte	0x1c
	.byte	0x9
	.long	0x6e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x5
	.long	0xe9
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x2c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
	.section	.debug_line_str,"dr"
.LASF1:
	.ascii "F:\\Algorithm\\Pointer\0"
.LASF0:
	.ascii "pointer.c\0"
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 13.2.0"
