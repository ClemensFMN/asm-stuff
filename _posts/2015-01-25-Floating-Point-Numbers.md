---
layout: post
title: "Floating Point Representations"
date: 2015-01-25
comments: true
categories:
---

In a computer a real number is (approximately) represented by a *floating point number*. This representation consists of a sign, a significand, and an exponent. The value of the floating point number \\( f \\) is then defined as 

$$
f = (-1)^{sign} \times significand \times 2^{exponent}
$$

Different types of floating point number representations exist; we will consider floats and doubles.

### C Datatype float ###

This datatype has a total of 32 Bits; the first bit (MSB) is used for the sign, the next 8 bits are used for the exponent and the last 23 bits are used for the significand; see [Wikipedia](http://en.wikipedia.org/wiki/Single-precision_floating-point_format).

For testing I use the [following program](<https://github.com/ClemensFMN/asm-stuff/tree/master/floatingpoint_repr/main.c>) and compile it with 

> make all

For the time being we are interested in the variable ftest; therefore we debug the program with gdb:

> gdb main

set a breakpoint in main

> b main

and output the variable ftest in hex

> p/x ftest

which yields

> 4095b22d

I have written a small [python utility program](https://github.com/ClemensFMN/asm-stuff/blob/master/floatingpoint_repr/util.py)  which helps in decoding the output.

The binary representation of the hex value is 

> xxx

From this we can see that the sign bit is 0; therefore the number has a positive sign: (-1)^0 = 1. The exponent is xxx which translates to xxx. Finally, the fraction is xxx .

Putting everything together, we obtain xxx for this floating point value. It can be seen that the hex value is only an approximation to the real value of 4.678.
