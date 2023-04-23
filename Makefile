nnc: main.o network.o transform.o
	gcc -o nnc main.o network.o transform.o -lm

main.o: main.c
	gcc -c main.c

transform.o: transform.c
	gcc -c transform.c

clean:
	rm *.o nnc