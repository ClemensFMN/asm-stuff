---
layout: post
title: "Calling Assembler Functions from C (II)"
date: 2015-02-06
comments: true
categories:
---

This is a continuation of the previous post about calling assembler functions
from C. We will concentrate on the passing of floating point numbers (float
and double).

Furthermore we use the nasm assembler - mostly because I find the syntax to be
simpler and closer to the Intel documentation.

I have created some small example projects for passing [float parameters](https://github.com/ClemensFMN/asm-stuff/tree/master/float_exchange) and for passing [double parameters](https://github.com/ClemensFMN/asm-stuff/tree/master/double_exchange).

### Passing Float Parameters ###

The assembler function `sumoftwo_asm` takes two float parameters and returns
their sum. The other function takes an array of floats and a length (integer)
parameter and returns the array sum.

According to the calling conventions, the floating point parameters are passed
in the XMM registers; therefore `sumoftwo_asm` adds the two registers and
returns the result in XMM0 (according to the calling convention) - That's about
it!

The other function `running_sum_asm` receives the pointer to the float array
in the ESI register, and the (integer) length parameter in EDI. First step is
to set register XMM0 to zero (by xor-ing it with itself), and check whether
the length equals zero - in this case, we can return from the function right
away.
Otherwise, a loop adds the array values from memory 

> addss xmm0, [rdi]

increases the pointer value

> add rdi, 8

(one float value requires 8 Bytes -> therefore the pointer address is
(increases in steps of 8), and decreases the length variable

> dec rsi

If ESI is zero, we have summed up all values, and the function returns (with
the result being contained in XMM0).

### Passing Double Parameters ###

The programs work in a similar spirit; only difference is to instruct the CPU
to use assembler instructions for doubles; i.e. we use the `addsd` instruction
for adding instead of `addss` (and `xorsd` instead of `xorss`).

