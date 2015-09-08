CC = gcc
CFLAGS = -O3 -c -Wall

all: objeto
	rm -f test.o
	$(CC) -o main.exe *.o -lpdcurses
	rm -f *.o
	
test: objeto
	rm -f main.o
	$(CC) -o test.exe *.o -lpdcurses
	rm -f *.o
	
objeto:
	$(CC) $(CFLAGS) *.c
	
clean:
	rm -f main.exe
