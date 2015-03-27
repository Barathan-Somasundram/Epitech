[BITS 64]
	global strcmp

	section .text

strcmp:
	push rbp
	mov rbp, rsp

	xor rax, rax
	xor r8, r8
	
.strcmp_loop:
	mov al, [rdi]
	mov r8b, [rsi]
	cmp al, r8b
	jne .strcmp_end
	cmp al, 0
	je .strcmp_end
	cmp r8b, 0
	je .strcmp_end
	inc rdi
	inc rsi
	jne .strcmp_loop

.strcmp_end:
	sub al, r8b
	movsx rax, al
	
	mov rsp, rbp
	pop rbp
	ret
