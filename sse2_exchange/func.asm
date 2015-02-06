global sum_float_asm
global sum_int_asm
global sum_int_asm_2

section .text

sum_float_asm:
        movdqa   xmm0, [rdi]            ; all values of x
        movdqa   xmm1, [rsi]            ; all values of y
        addps    xmm0, xmm1             ; do all sums in one shot
        movdqa   [rdi], xmm0
	ret


sum_int_asm:
        movdqa   xmm0, [rdi]            ; all values of x
        movdqa   xmm1, [rsi]            ; all values of y
        paddb    xmm0, xmm1             ; do all sums in one shot
        movdqa   [rdi], xmm0
        ret

sum_int_asm_2:
        movdqa   xmm0, [rdi]            ; all values of x
        movdqa   xmm1, [rsi]            ; all values of y
        paddw    xmm0, xmm1             ; do all sums in one shot
        movdqa   [rdi], xmm0
        ret


