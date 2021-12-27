CC=g++
CFLAGS=-I include -o main

build:
	$(CC) $(CFLAGS) main.cpp
run:
	$(CC) $(CFLAGS) main.cpp
	main
