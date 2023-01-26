HelloWorld: main.o
	g++ -std=c++11 -g -Wall main.o -o HelloWorld

main.o: main.c
	g++ -std=c++11 -g -Wall -c main.c

clean:
	rm *.o HelloWorld
