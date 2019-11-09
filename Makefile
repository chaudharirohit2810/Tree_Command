all:
	make create
	make push
	make clear
create : 
	cc -c tree.c -o 1 -Wall
	cc -c main.c -o 2 -Wall
	cc 1 2 -o myTree
push :
	-cp myTree /usr/bin/myTree
clear:
	rm 1 2
