section .data      
	msg db "",10,0
	msg1 dd 1,2,3,3,-1

section .bss
	b resd 1
	c resb 10
section .text
	global main

main:
	mov eax,dword[eax]
	jmp end


	cmp eax,dword[b]
	push msg
	mov eax,4
	mov dword[b],eax
        add eax,ebx
	sub ax,bx
	sub eax,eax
	inc eax

loop      :
	mov eax,eax


end:

