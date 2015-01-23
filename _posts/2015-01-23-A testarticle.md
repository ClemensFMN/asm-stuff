---
layout: post
title: "A first article"
date: 2015-01-23
comments: true
categories:
---

This is a basic test article providing different markdown examples

### Heading ###



Some text goes here


```C
#include <stdio.h>
#include <inttypes.h>

int64_t maxofthree(int64_t, int64_t, int64_t);


void main() {
  printf("Hello World!\n");
  printf("%ld\n", maxofthree(2, -6, 1));
}
```

And here the code block is over and another one starts (Assembly should have worked?)

```

section .data
    msg_smaller db      "A<B"
    msg_greater db      "A>B"
    
section .text
    global _start
_start:

	mov rax, 1
	mov rbx, 2
	cmp rax, rbx
	jg .greater
	jmp .smaller
```

Some gdb example session

> gdb main

some output...

> b main

set breakpoint

> r

run program (till breakpoint)

> p f1

print variable f1

