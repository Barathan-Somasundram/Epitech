[BITS 64]
	global strchr

	section .text

strchr:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	
.strchr_loop:
	mov r8b, [rax]
	cmp r8b, sil
	je .strchr_end
	cmp r8b, 0
	je .strchr_end
	inc rax
	jne .strchr_loop
	
.strchr_end:
	mov rsp, rbp
	pop rbp
	ret
