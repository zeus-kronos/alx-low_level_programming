section .data
	msg: db "Hello, main", 0x0a
	msglen equ $-msg

section .text
	global main

main:
	; write Hellomain to screen
	mov eax, 1 ; syscall for write
	mov edi, 1
	mov rsi, msg
	mov edx, msglen
	syscall
	mov eax, 60 ; 60 is exit
	xor edi, edi ; exit (0)
	syscall
