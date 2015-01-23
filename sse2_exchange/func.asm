global sum_float_asm
global sum_int_asm

section .text

sum_float_asm:
        movdqa   xmm0, [rdi]            ; all four values of x
        movdqa   xmm1, [rsi]            ; all four values of y
        addps    xmm0, xmm1             ; do all four sums in one shot
        movdqa   [rdi], xmm0
	ret


sum_int_asm:
        movdqa   xmm0, [rdi]            ; all four values of x
        movdqa   xmm1, [rsi]            ; all four values of y
        paddb    xmm0, xmm1             ; do all four sums in one shot
        movdqa   [rdi], xmm0
        ret

