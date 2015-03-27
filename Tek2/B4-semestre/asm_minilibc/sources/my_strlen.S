[BITS 64]
	global strlen

	section .text

strlen:
	push rbp
	mov rbp, rsp

	xor rax, rax

.strlen_loop:
	mov r8b, [rdi + rax]
	cmp r8b, 0
	je .strlen_end
	inc rax
	jne .strlen_loop

.strlen_end:
	mov rsp, rbp
	pop rbp
	ret
	
