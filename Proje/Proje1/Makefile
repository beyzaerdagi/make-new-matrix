CC=gcc

CFLAGS=-c	-Wall

all:makeDeneme

makeDeneme:	main.o	matrisoperations.o
	$(CC)	main.o	matrisoperations.o	-o	makeDeneme

main.o:	main.c
	$(CC)	$(CFLAGS)	main.c
matrisoperations.o:	matrisoperations.c	matrisoperations.h
	$(CC)	$(CFLAGS)	matrisoperations.c

clean:
	del	*.o	makeDeneme.exe
