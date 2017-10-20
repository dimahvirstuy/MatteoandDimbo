all: list.o lib.o main.o
	gcc -o music list.o lib.o main.o
list.o: list.c list.h
	gcc -c list.c
lib.o: lib.c lib.h
	gcc -c lib.c
main.o: main.c lib.h list.h
	gcc -c main.c
run:
	./music
clean:
	rm *.o
	rm music