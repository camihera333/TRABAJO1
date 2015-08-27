CC = gcc
CFLAGS = -O3 -c -Wall

all:	object
	$(CC) -o main.exe *.o
	rm *.o

object:	
	$(CC) $(CFLAGS) *.c

clean:
	rm main.exe
