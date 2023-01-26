(CC)=gcc

.PHONY:test

test:hello
	echo "test"

run:hello
	@./o_hello

hello:hello.o
	@$(CC) hello.o -o o_hello

hello.o:hello.c
	@$(CC) -c hello.c -o hello.o

hello.c:
	@echo "#include <stdio.h>\nint main()\n{\nprintf("\""Hello World from SL"\"");\n}" > hello.c

.PHONY:clean

clea:
	@rm -fr hello.c hello.o o_hello
