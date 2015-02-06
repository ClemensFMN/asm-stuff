---
layout: post
title: "SSE2 Instructions"
date: 2015-02-09
comments: true
categories:
---

This is a short introduction of how SSE2 instructions can be used to perform
arithmetic operations in parallel; i.e. add several integer variables or float
variables within **one** instruction.

There is a small [example program](https://github.com/ClemensFMN/asm-stuff/tree/master/sse2_exchange) 
showing the main idea.

There are three functions: `sum_int_asm`, `sum_int_asm_2`, and
`sum_float_asm`. The integer functions take two arrays of integers (with
different bit-widths), add them element-wise and return the sum in the first
parameter, whereas `sum_float_asm` works on float arrays.

In the assembler function, the `movdqa` instruction is used to move the memory
values into the XMM0 and XMM1 register, respectively. The instruction seems to
move 128 Bits regardless of the datatype so it used in both assembler functions.

The arithmetic functions, however, need to consider the data type and must
therefore "match" the datatype. In case of `sum_int_asm` the instruction

> paddb xmm0, xmm1

is used for adding the 8 Bit values; in case of `sum_int_asm_2` 

> paddw xmm0, xmm1

is used for adding the 16 Bit values, and in case of `sum_float_asm` the
instruction

> addps xmm0, xmm1

for float addition is used. Moving the result from XMM0 into memory is again
done via the `movdqa` instruction for both integer and floats.
