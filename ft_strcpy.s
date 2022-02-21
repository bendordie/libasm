global _ft_strcpy

section .text

_ft_strcpy: xor	rcx, rcx
			xor	rax, rax
			
.cycle:		cmp [rsi + rcx], byte 0
			jz	.end
			mov al, [rsi + rcx]
			mov	[rdi + rcx], al
			inc	rcx
			jmp	.cycle
			
.end:		mov [rdi + rcx], byte 0
			mov	rax, rdi
			ret
