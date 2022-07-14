#ifndef __LIVRO_H__
#define __LIVRO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro{
    int isbn;
    char titulo[100];
    char autor[100];
    int estoque;
    struct livro *prox;
    struct livro *ant;
} Livro;

Livro *cria(int isbn, char *titulo, char *autor, int estoque);

#endif 