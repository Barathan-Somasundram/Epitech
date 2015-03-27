[BITS 64]
	global memset

	section .text

memset:
	push rbp
	mov rbp, rsp

	xor rcx, rcx
	mov rax, rdi
	
.memset_loop:
	cmp rcx, rdx
	je .memset_end
	mov [rax + rcx], sil
	inc rcx
	jne .memset_loop

.memset_end:
	mov rsp, rbp
	pop rbp
	ret
