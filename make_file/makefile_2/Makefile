(CC)=gcc

main1: main1.c
	$(CC) -o  o_main1.o main1.c
main2: main2.c
	$(CC) -o  o_main2.o main2.c
main: main1.o main2.o
	$(CC) -c main1.c main2.c 
run: main1 main2
	./o_main1 ./main2
