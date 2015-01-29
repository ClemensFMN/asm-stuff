global sumoftwo_asm
global sumofints_asm
section .text


sumoftwo_asm:
	mov rax, rdi   ; move first operand to ax
	mov rbx, rsi   ; second to bx
	add rax, rbx   ; add and store result in ax
	ret

sumofints_asm:          ; di holds a pointer to the first array element
        xor rax, rax    ; zero ax (which we will use as accumulator)
        cmp rsi, 0      ; si holds the number of element to sum over; 
        je done         ; if the number of elements is zero, we are already finished
next:
        add rax, [rdi]  ; add array element
        add rdi, 8      ; increment pointer (64 bit ints -> 8 byte)
        dec rsi         ; decrease the "counter"
        jnz next        ; continue summing, if not zero
done:
        ret