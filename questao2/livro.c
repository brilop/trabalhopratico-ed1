#include "livro.h"

Livro *cria(int isbn, char *titulo, char *autor, int estoque){
    Livro *novo = (Livro*)calloc(1, sizeof(Livro*));
    if(!novo) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    novo->isbn = isbn;
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->estoque = estoque;

    return novo;
} 