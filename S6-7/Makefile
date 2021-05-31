CFLAGS=-g -Wall

all: ecosys1 ecosys2

ecosys.o: ecosys.h ecosys.c
	gcc -c $(CFLAGS) ecosys.c

main1.o: ecosys.h main1.c
	gcc -c $(CFLAGS) main1.c

main2.o: ecosys.h main2.c
	gcc -c $(CFLAGS) main2.c

ecosys1: ecosys.o main1.o
	gcc -o ecosys1 $(CFLAGS) ecosys.o main1.o

ecosys2: ecosys.o main2.o
	gcc -o ecosys2 $(CFLAGS) ecosys.o main2.o

clean: 
	rm -f *.o ecosys1 ecosys2