global	_ft_strdup
extern	_ft_strlen
extern _ft_strcpy
extern	_malloc

section	.text

_ft_strdup:	xor	rax, rax
			push	rdi
			call	_ft_strlen
			mov	rdi, dword	rax
			mov	rcx, dword rax
			call	_malloc
			jz		.err
			pop		rdi
			mov	rsi, rdi
			mov	rdi, rax
			call	_ft_strcpy
			ret

.err:		pop		rdi
			ret
