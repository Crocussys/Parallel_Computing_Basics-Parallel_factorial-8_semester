all: main.o
	g++ main.o -o Parallel_factorial

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o
