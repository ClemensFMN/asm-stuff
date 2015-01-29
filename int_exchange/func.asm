global  maxofthree
global sumoftwo_asm
global sumofints_asm
section .text



maxofthree:
        mov     rax, rdi                ; result (rax) initially holds x
        cmp     rax, rsi                ; is x less than y?
        cmovl   rax, rsi                ; if so, set result to y
        cmp     rax, rdx                ; is max(x,y) less than z?
        cmovl   rax, rdx                ; if so, set result to z
        ret                             ; the max will be in rax


sumoftwo_asm:
	mov rax, rdi
	mov rbx, rsi
	add rax, rbx
	ret

sumofints_asm:
        xor rax, rax
        cmp rsi, 0
        je done
next:
        add rax, [rdi]
        add rdi, 8
        dec rsi
        jnz next
done:
        ret