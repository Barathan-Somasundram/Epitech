[BITS 64]
	global strcspn

	section .text

strcspn:
	push rbp
	mov rbp, rsp

	xor rax, rax

.strcspn_loopa:
	mov al, [rdi + rax]
	cmp al, 0
	je .strcspn_end
	mov r8, rsi
.strcspn_loopb:
	mov cl, [r8]
	cmp cl, al
	jne .strcspn_strend
	jmp .strcspn_end

.strcspn_strend:
	cmp cl, 0
	je .strcspn_loop_end
	inc r8
	jmp .strcspn_loopb

.strcspn_loop_end:
	inc rax
	jmp .strcspn_loopa

.strcspn_end:
	mov rsp, rbp
	pop rbp
	ret
