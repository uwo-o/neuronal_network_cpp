nnc: main.o network.o menu.o
	g++ -o nnc main.o network.o transform.o menu.o -lm

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm *.o nnc
