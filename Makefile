all: main.o Racket.o Ball.o
	 g++ main.o Racket.o Ball.o -o tennis-game -lSDL -lSDL_ttf
	
main: main.cpp
	 g++ -O3 -c main.cpp

Racket: Racket.cpp
	 g++ -O3 -c Racket.cpp
	 
Ball: Ball.cpp
	g++ -O3 -c Ball.cpp
	
clean:
	rm *.o
