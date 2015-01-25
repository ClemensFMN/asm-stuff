---
layout: post
title: "Floating Point Representations"
date: 2015-01-25
comments: true
categories:
---

# Under Construction #

In a computer a real number is (approximately) represented by a *floating
point number*. This representation consists of a sign, a significand, and an
exponent. The value of the floating point number \\( f \\) is then defined as

$$
f = (-1)^{sign} \times significand \times 2^{exponent}
$$

Different types of floating point number representations exist; we will
consider floats and doubles.

### C Datatype float ###

This datatype has a total of 32 Bits; the first bit (MSB) is used for the
sign, the next 8 bits are used for the exponent and the last 23 bits are used
for the significand; see [Wikipedia](http://en.wikipedia.org/wiki/Single-precision_floating-point_format).

For testing I use the 
[following program](<https://github.com/ClemensFMN/asm-stuff/tree/master/floatingpoint_repr/main.c>) and compile it with

> make all

For the time being we are interested in the variable ftest; therefore we debug
the program with gdb:

> gdb main

> p ftest


> $1 = 4.67799997

To see the value in hex we need a little trick (I don't know why p/x ftest
does not work but anyway); we display the memory location (in hex format) at
which ftest is stored:

> x/x &ftest

this yields

> 4095b22d


I have written a small 
[python utility program](https://github.com/ClemensFMN/asm-stuff/blob/master/floatingpoint_repr/util.py)
which helps in decoding the output.

The binary representation of the hex value is 

> 0  10000001  00101011011001000101101

From this we can see that the sign bit is 0; therefore the number has a
positive sign: (-1)^0 = 1. The exponent is 10000001 which translates to 129.
Finally, the fraction is 0.16949999332427979.

Putting everything together, the representation of ftest equals

$$ 
(-1)^0 \times (1 + 0.16949999332427979) \times 2^{129-127} = 4.6779999733
$$

It can be seen that the hex value is only an approximation to the real value
of 4.678.

### C Datatype double ###

The principle is pretty much the same, except that a double uses more bits: in total
a double variable occupies 64 bits, with 1 bit for sign, 11 bits for the
exponent, and (the remaining) 52 bits for the significand ; see
[Wikipedia](http://en.wikipedia.org/wiki/Double-precision_floating-point_format).

We can use the same trick as above to obtain the hex representation of dtest;
we only need to take care to display two 32 bits.

> x/2x &dtest

does the trick and we can examine the hex value to be

> 0xa1cac083      0x4012b645

These are two 32 bit hex values; however, we need to "convert" them into one
64 bit variable. Simple concatenation does the trick and we arrive at the (64
bit) hex value 0xa1cac0834012b645. Throwing this into the python script, we
obtain 4.678. Seems as if the approximation were better in this case...
