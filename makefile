all: teste

teste: arvore.o main.o
	gcc -o teste arvore.o main.o

arvore.o: arvore.c arvore.h
	gcc -c arvore.c -Wall -Werror -Wextra

main.o: main.c arvore.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o teste