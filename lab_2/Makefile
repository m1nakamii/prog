all: app

app: main IntVector
	gcc -Wall -o app IntVector main
main: src/main.c
	gcc -Wall -c -o main src/main.c
IntVector: src/IntVector.c
	gcc -Wall -c -o IntVector src/IntVector.c