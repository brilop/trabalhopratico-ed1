all: questao2

questao2: livro.o main.o
	gcc -o questao2 livro.o main.o

livro.o: livro.c livro.h
	gcc -c livro.c -Wall -Werror -Wextra

main.o: main.c livro.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o questao2