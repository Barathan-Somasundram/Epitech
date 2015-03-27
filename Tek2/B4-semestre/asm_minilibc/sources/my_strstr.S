[BITS 64]
	global strstr

	section .text

strstr:
	push rbp
	mov rbp, rsp
	
.strstr_loop:
	mov al, [rdi]
	cmp al, sil
	je .strstr_end1
	cmp al, 0
	je .strstr_null
	inc rdi
	jne .strstr_loop

.strstr_end1:
	mov rax, rdi
	jmp .strstr_end
.strstr_null:
	xor rax, rax
.strstr_end:
	mov rsp, rbp
	pop rbp
	ret
