run: nnc
	./nnc

nnc: main.o neuron.o network.o  menu.o
	g++ -o nnc main.o neuron.o network.o menu.o -lm

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

network.o: network.cpp network.hpp
	g++ -c network.cpp network.hpp

neuron.o: neuron.cpp neuron.hpp
	g++ -c neuron.cpp neuron.hpp

clean:
	rm *.o *.gch nnc
