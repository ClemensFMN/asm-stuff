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

There are two functions: `sum_int_asm` and `sum_float_asm`. The function
`sum_int_asm` takes two arrays of integers, adds them element-wise and returns
the sum in the first parameter, whereas `sum_float_asm` works on float arrays.

In the assembler function, the `movdqa` instruction is used to move the memory
values into the XMM0 and XMM1 register, respectively. The instruction seems to
move 128 Bits regardless of the datatype so it used both assembler functions.

Adding integers and floats is a different operation, therefore the
corresponding instructions are different: `sum_int_asm` uses 

> paddb xmm0, xmm1

whereas 

`sum_float_asm` uses

> addps xmm0, xmm1

Moving the result from XMM0 into memory is again done via the `movdqa`
instruction for both integer and floats.

