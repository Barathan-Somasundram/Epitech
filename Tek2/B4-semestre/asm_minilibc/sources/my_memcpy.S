[BITS 64]
	global memcpy

	section .text

memcpy:
	push rbp
	mov rbp, rsp

	xor rcx, rcx
	mov rax, rdi
	
.memcpy_loop:
	cmp rcx, rdx
	je .memcpy_end
	mov r8b, [rsi + rcx]
	mov [rax + rcx], r8b
	inc rcx
	jne .memcpy_loop

.memcpy_end:
	mov rsp, rbp
	pop rbp
	ret
