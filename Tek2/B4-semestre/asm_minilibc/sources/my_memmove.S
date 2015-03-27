[BITS 64]
	global memmove

	section .text

memmove:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	mov rcx, rdx
	sub rcx, 1
	mov r9, -1
	mov r10, -1

	cmp rax, rsi
	jg .memmove_loop
	xor rcx, rcx
	mov r9, 1
	mov r10, rdx
	
.memmove_loop:
	cmp rcx, r10
	je .memmove_end
	mov r8b, [rsi + rcx]
	mov [rax + rcx], r8b
	add rcx, r9
	jne .memmove_loop

.memmove_end:
	mov rsp, rbp
	pop rbp
	ret
