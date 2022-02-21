global	_ft_read
extern	___error

section	.text

_ft_read:	xor	rax, rax
			mov	rax, 0x02000003
			syscall
			jc	.err
			ret

.err:		mov	r8, rax
			push	-1
			call	___error
			mov	qword [rax], r8
			pop	rax
			ret
