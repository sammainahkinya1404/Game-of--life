CC=gcc
CFLAGS=-c -Wall

Life: main.o life.o
	$(CC) main.o life.o -o Life

main.o: main.c life.h
	$(CC) $(CFLAGS) main.c

life.o: life.c life.h
	$(CC) $(CFLAGS) life.c

clean:
	rm -rf *.o Life
