[BITS 64]
	global rindex

	section .text

rindex:
	push rbp
	mov rbp, rsp

	xor rcx, rcx
	xor rax, rax
	
.rindex_loopa:
	mov r8b, [rdi + rcx]
	cmp r8b, sil
	je .rindex_occur

.rindex_loopb:
	cmp r8b, 0
	je .rindex_end
	inc rcx
	jne .rindex_loopa

.rindex_occur:
	mov rdx, rdi
	add rdx, rcx
	mov rax, rdx
	jmp .rindex_loopb
	
.rindex_end:
	mov rsp, rbp
	pop rbp
	ret
