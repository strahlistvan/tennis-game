CC=g++
CFLAGS=-O3 -c


all: main.o Racket.o Ball.o
	 $(CC) main.o Racket.o Ball.o -o tennis-game -lSDL -lSDL_ttf
	
main: main.cpp
	  $(CC) $(CFLAGS) main.cpp

Racket: Racket.cpp
	 $(CC) $(CFLAGS) Racket.cpp
	 
Ball: Ball.cpp
	$(CC) $(CFLAGS) Ball.cpp
	
clean:
	rm *.o
