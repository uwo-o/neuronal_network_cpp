nnc: main.o activation_functions.o neuron.o network.o  menu.o
	g++ -o nnc main.o neuron.o network.o menu.o -lm

main.o: main.cpp
	g++ -c main.cpp

activation_functions.o: activation_functions.cpp activation_functions.hpp
	g++ -c activation_functions.cpp activation_functions.hpp

menu.o: menu.cpp
	g++ -c menu.cpp

network.o: network.cpp network.hpp
	g++ -c network.cpp network.hpp

neuron.o: neuron.cpp neuron.hpp
	g++ -c neuron.cpp neuron.hpp

clean:
	rm *.o *.gch nnc
