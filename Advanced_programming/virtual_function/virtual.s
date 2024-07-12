	.file	"virtual.cpp"
	.text
	.section	.text$_ZN4Base15my_virtual_funcEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4Base15my_virtual_funcEv
	.def	_ZN4Base15my_virtual_funcEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4Base15my_virtual_funcEv
_ZN4Base15my_virtual_funcEv:
.LFB2212:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4BaseC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4BaseC1Ev
	.def	_ZN4BaseC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4BaseC1Ev
_ZN4BaseC1Ev:
.LFB2216:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV4Base(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2213:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp
	.seh_setframe	%rbp, 64
	.seh_endprologue
	call	__main
	movl	$8, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movq	$0, (%rbx)
	movq	%rbx, %rcx
	call	_ZN4BaseC1Ev
	movq	%rbx, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	*%rdx
	leaq	16+_ZTV4Base(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN4Base15my_virtual_funcEv
	leaq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	*%rdx
	movl	$0, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV4Base
	.section	.rdata$_ZTV4Base,"dr"
	.linkonce same_size
	.align 8
_ZTV4Base:
	.quad	0
	.quad	_ZTI4Base
	.quad	_ZN4Base15my_virtual_funcEv
	.globl	_ZTI4Base
	.section	.rdata$_ZTI4Base,"dr"
	.linkonce same_size
	.align 8
_ZTI4Base:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS4Base
	.globl	_ZTS4Base
	.section	.rdata$_ZTS4Base,"dr"
	.linkonce same_size
_ZTS4Base:
	.ascii "4Base\0"
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 13.2.0"
	.def	_Znwy;	.scl	2;	.type	32;	.endef
