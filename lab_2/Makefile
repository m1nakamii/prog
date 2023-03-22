all: app

app: main IntVector
	gcc -Wall -o app IntVector main
main: main.c
	gcc -Wall -c -o main main.c
IntVector: IntVector.c
	gcc -Wall -c -o IntVector IntVector.c