nnc: main.o network.o transform.o
	g++ -o nnc main.o network.o transform.o -lm

main.o: main.cpp
	g++ -c main.cpp

transform.o: transform.cpp
	g++ -c transform.cpp

clean:
	rm *.o nnc