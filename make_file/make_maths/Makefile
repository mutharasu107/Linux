(CC)=gcc
 
.PHONY:test 
 
run:test 
	@./test

test:hello.o hello1.o hello2.o hello3.o
	gcc hello.o hello1.o hello2.o hello3.o -o test
 
hello.o:hello.c
	gcc -c hello.c -o hello.o

hello1.o:hello1.c
	gcc -c hello1.c -o hello1.o

hello2.o:hello2.c
	gcc -c hello2.c -o hello2.o

hello3.o:hello3.c
	gcc -c hello3.c -o hello3.o
.PHONY:clean
clean:
	@rm -fr hello.c hello.o o_hello
	@rm -fr hello1.c hello1.o o_hello1
	@rm -fr hello2.c hello2.o o_hello2
	@rm -fr hello3.c hello3.o o_hello3

