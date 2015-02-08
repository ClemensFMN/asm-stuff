global sumoftwo_asm
global running_sum_asm


section .text

sumoftwo_asm:
	addss xmm0, xmm1
	ret


running_sum_asm:
        xorps   xmm0, xmm0              ; initialize the sum to 0
        cmp     rsi, 0                  ; special case for length = 0
        je      done
next:
        addss   xmm0, [rdi]             ; add in the current array element
        add     rdi, 4                  ; move to next array element
        dec     rsi                     ; count down
        jnz     next                    ; if not done counting, continue
done:
        ret                    
