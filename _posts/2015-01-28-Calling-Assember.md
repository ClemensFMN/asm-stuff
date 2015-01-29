---
layout: post
title: "Calling Assembler Functions from C (I)"
date: 2015-01-28
comments: true
categories:
---

# WORK IN PROGRESS #


This post deals with the question of how a C program calls functions (mostly
assembler functions).


In the following we will use a 64 bit (*x86_64*) Linux system; the same
exercise can be done on an 32 bit system as well, but the calling conventions
are different.

Furthermore we use the nasm assembler - mostly because I find the syntax to be
simpler and closer to the Intel documentation.

I have created a small [example project](https://github.com/ClemensFMN/asm-stuff/tree/master/int_exchange) 
which consists of a small C program which
invokes some assembler routines from func.asm.

### Passing Integer Parameters ###

There are two functions taking two 64 bit integer parameters and returning one
(their sum): `sumoftwo_c` is a normal C function; `sumoftwo_asm` is a "hand-
written" assembler function.

> make all

compiles the thing and generates a list file. Somewhere around line #340 (at
least in my case), the main function starts. After some garbage (ok, not
really - stack pointer setup etc), the interesting part starts:


	mov    esi,0x4
	mov    edi,0x3
	call   400506 <sumoftwo_c>

The function parameters are assigned to the processor registers EDI and ESI,
respectively, and then the function is called.

The list file contains the definition of `sumoftwo_c` slightly above main; again
after some stack setup, the file contains:

	mov    QWORD PTR [rbp-0x8],rdi
	mov    QWORD PTR [rbp-0x10],rsi
	mov    rdx,QWORD PTR [rbp-0x8]
	mov    rax,QWORD PTR [rbp-0x10]
	add    rax,rdx

The code seems to be really awkward and complicated; nevertheless, the two
registers EDI and ESI are added and the result is stored in EAX.

After some stack cleanup, the function returns with the result being in EAX.


Looking into the [x86_64 ABI
definition](http://www.x86-64.org/documentation/abi.pdf),  one can see that
gcc is actually behaving correctly :-) Section 3.2.3 defines parameter passing
and yes, the first registers used for integer parameter passing are EDI and
ESI. Integers are returned in EAX - correct!


Basically `sumoftwo_asm` does the same as the C function `sumoftwo_c` except
for the stack handling. We know that `sumoftwo_asm` does not use any local
variables, therefore there is no need to set up a stack pointer (at least I
think so).

Therefore the function becomes really simple

	mov rax, rdi
	mov rbx, rsi
	add rax, rbx
	ret

Move the parameters into EAX and EBX, respectively, sum them up so that the
result is stored in EAX and return - that's it!.


### Passing an Array of Integers ###

The function `sumofints_c` and `sumofints_asm` take an array of (64 bit)
integers and a length parameter, respectively. Both functions calculate the
sum of the array (its length defined by the second parameter) and return the
sum.

The disassembled c function is really a mess; we will concentrate on the
assember function `sumofints_asm` right away.

We can debug it via 

> gdb main

> b sumofints_asm

> r

Upon reaching the breakpoint we can inspect the registers

> p $rsi

yields 5, the number of integers to add. Getting the array to add is a bit
more complicated; we want to see the memory region EDI points to (`x`), we
want to display the data as "giants" (64 bit integers) `g`, and we want to see
5 of them:

> x/5g $rdi

does the trick and yields

> 0x601060 <list_data>:   1       2

> 0x601070 <list_data+16>:        3       4

> 0x601080 <list_data+32>:        5

Clearly the array we want to sum over. Looking into the lst file at address
0x601060 also shows the data.

With the key `n` we can step through the assembler program and see that EAX
has a value of 15 at the very end of the function:

> p $eax

yields 15.

