[BITS 64]
	global strpbrk

	section .text

strpbrk:
	push rbp
	mov rbp, rsp

.strpbrk_loopa:
	mov al, [rdi]
	cmp al, 0
	je .strpbrk_null
	mov r8, rsi

.strpbrk_loopb:
	mov cl, [r8]
	cmp cl, al
	jne .strpbrk_strend
	mov rax, rdi
	je .strpbrk_end

.strpbrk_strend:
	cmp cl, 0
	je .strpbrk_loop_end
	inc r8
	jne .strpbrk_loopb

.strpbrk_loop_end:
	inc rdi
	jmp .strpbrk_loopa
	
.strpbrk_null:
	xor rax, rax
.strpbrk_end:
	mov rsp, rbp
	pop rbp
	ret
