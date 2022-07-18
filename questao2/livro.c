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

void insere(Livro **L, int isbn, char *titulo, char *autor, int estoque){
    Livro *novo = cria(isbn, titulo, autor, estoque);
    if((*L) == NULL){
        (*L) = novo;
    } else{
        novo->prox = (*L);
        (*L)->ant = novo;
        (*L) = novo;
    }
}