run:test
	./test

test:main.o add.o sub.o mul.o
	gcc main.o add.o sub.o mul.o -o test

main.o:main.c
	gcc -c main.c -o main.o

add.o:add.c
	gcc -c add.c -o add.o

sub.o:sub.c
	gcc -c sub.c -o sub.o

mul.o:mul.c
	gcc -c mul.c -o mul.o
