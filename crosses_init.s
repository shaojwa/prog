	.file	"crosses_init.cc"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"Dog"
	.section	.text._ZN3DogC2Ev,"axG",@progbits,_ZN3DogC5Ev,comdat
	.align 2
	.weak	_ZN3DogC2Ev
	.type	_ZN3DogC2Ev, @function
_ZN3DogC2Ev:
.LFB1730:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1730:
	.size	_ZN3DogC2Ev, .-_ZN3DogC2Ev
	.weak	_ZN3DogC1Ev
	.set	_ZN3DogC1Ev,_ZN3DogC2Ev
	.section	.rodata
.LC1:
	.string	"~Dog"
	.section	.text._ZN3DogD2Ev,"axG",@progbits,_ZN3DogD5Ev,comdat
	.align 2
	.weak	_ZN3DogD2Ev
	.type	_ZN3DogD2Ev, @function
_ZN3DogD2Ev:
.LFB1733:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1733
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1733:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN3DogD2Ev,"aG",@progbits,_ZN3DogD5Ev,comdat
.LLSDA1733:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1733-.LLSDACSB1733
.LLSDACSB1733:
.LLSDACSE1733:
	.section	.text._ZN3DogD2Ev,"axG",@progbits,_ZN3DogD5Ev,comdat
	.size	_ZN3DogD2Ev, .-_ZN3DogD2Ev
	.weak	_ZN3DogD1Ev
	.set	_ZN3DogD1Ev,_ZN3DogD2Ev
	.section	.rodata
.LC2:
	.string	"play"
	.section	.text._ZN3Dog4playEv,"axG",@progbits,_ZN3Dog4playEv,comdat
	.align 2
	.weak	_ZN3Dog4playEv
	.type	_ZN3Dog4playEv, @function
_ZN3Dog4playEv:
.LFB1735:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1735:
	.size	_ZN3Dog4playEv, .-_ZN3Dog4playEv
	.text
	.globl	_Z12crosses_initbb
	.type	_Z12crosses_initbb, @function
_Z12crosses_initbb:
.LFB1736:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1736
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, %edx
	movl	%esi, %eax
	movb	%dl, -36(%rbp)
	movb	%al, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpb	$0, -36(%rbp)
	jne	.L14
	cmpb	$0, -40(%rbp)
	je	.L15
	movl	$-1, %ebx
	jmp	.L9
.L14:
	nop
	jmp	.L6
.L15:
	nop
.L6:
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZN3DogC1Ev
.LEHE0:
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZN3Dog4playEv
.LEHE1:
	nop
.L8:
	movl	$0, %ebx
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3DogD1Ev
.L9:
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	jmp	.L13
.L12:
	movq	%rax, %rbx
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3DogD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L13:
	call	__stack_chk_fail@PLT
.L11:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1736:
	.section	.gcc_except_table,"a",@progbits
.LLSDA1736:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1736-.LLSDACSB1736
.LLSDACSB1736:
	.uleb128 .LEHB0-.LFB1736
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1736
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L12-.LFB1736
	.uleb128 0
	.uleb128 .LEHB2-.LFB1736
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1736:
	.text
	.size	_Z12crosses_initbb, .-_Z12crosses_initbb
	.globl	main
	.type	main, @function
main:
.LFB1737:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, %esi
	movl	$1, %edi
	call	_Z12crosses_initbb
	movl	$0, %esi
	movl	$0, %edi
	call	_Z12crosses_initbb
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1737:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2240:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L20
	cmpl	$65535, -8(%rbp)
	jne	.L20
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2240:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z12crosses_initbb, @function
_GLOBAL__sub_I__Z12crosses_initbb:
.LFB2241:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2241:
	.size	_GLOBAL__sub_I__Z12crosses_initbb, .-_GLOBAL__sub_I__Z12crosses_initbb
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z12crosses_initbb
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
