global	_ft_strlen

section .text

_ft_strlen: xor rcx, rcx

.cycle: 	cmp [rdi + rcx], byte  0
			jz .end
			inc rcx
			jmp .cycle

.end:		mov rax, rcx
			ret
