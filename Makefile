all:
	cc -c tree.c -o 1 -Wall
	cc -c main.c -o 2 -Wall
	cc 1 2 -o tree
