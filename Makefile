
CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o PTree.o
	$(CC) main.o PTree.o -o main $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++11

PTree.o: PTree.cpp PTree.hpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++11

clean:
	rm main *.o