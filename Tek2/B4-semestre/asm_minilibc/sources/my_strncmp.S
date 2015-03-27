[BITS 64]
	global strncmp

	section .text

strncmp:
	push rbp
	mov rbp, rsp

	xor r8, r8
	xor rax, rax
	xor rcx, rcx
	cmp rdx, 0
	je .strncmp_end
	
.strncmp_loop:
	mov al, [rdi]
	mov r8b, [rsi]
	cmp al, r8b
	jne .strncmp_end
	cmp al, 0
	je .strncmp_end
	cmp r8b, 0
	je .strncmp_end
	inc rsi
	inc rdi
	inc rcx
	cmp rcx, rdx
	je .strncmp_end
	jne .strncmp_loop

.strncmp_end:
	sub al, r8b
	movsx rax, al

	mov rsp, rbp
	pop rbp
	ret
