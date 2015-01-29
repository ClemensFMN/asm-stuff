

func.o: func.asm
	nasm -f elf64 func.asm

all: main.c func.o
	gcc -std=c99 -os -g -o main main.c func.o
	objdump -g -M intel -D main > main.lst
