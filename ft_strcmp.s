global	_ft_strcmp

section	.text

_ft_strcmp:	xor	rcx, rcx
			xor rax, rax
.cycle:		mov	al, byte [rdi + rcx]
			mov	ah, byte [rsi + rcx]
			cmp	ah, byte 0
			je	.above
			inc	rcx
			cmp	ah, al
			je	.cycle

.above:		sub	ah, al
			cmp	ah, byte 0
			jl	.lower
			cmp	ah, byte 0
			je	.equal
			mov	rax, dword -1
			ret

.lower:	mov	rax, dword 1
			ret

.equal:		mov	rax, dword 0
			ret
