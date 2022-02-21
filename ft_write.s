global	_ft_write
extern	___error

section	.text

_ft_write:	xor	rax, rax
			mov	rax, 0x02000004
			syscall
			jc	.err
			ret

.err:		mov	r8, rax
			push	-1
			call	___error
			mov	qword [rax], r8
			pop	rax
			ret
