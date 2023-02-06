HelloWorld: main.o
	gcc -std=c11 -g -Wall main.o -o HelloWorld

main.o: main.c
	gcc -std=c11 -g -Wall -c main.c

clean:
	rm *.o HelloWorld
