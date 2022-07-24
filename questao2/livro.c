#include "livro.h"

Livro *cria(int isbn, char titulo[], char autor[], int estoque){
    Livro *novo = (Livro*)malloc(sizeof(Livro));
    if(!novo) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    novo->isbn = isbn;
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->estoque = estoque;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
} 

Livro *busca(Livro *L, int isbn){
    Livro *aux = L;
    while (aux != NULL && isbn > aux->isbn){
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

void insere(Livro **L, int isbn, char titulo[], char autor[], int estoque){
    Livro *novo = cria(isbn, titulo, autor, estoque);
    Livro *aux = busca((*L), isbn);

    if((*L) == NULL){
        (*L) = novo;
    } 
    else if(aux->isbn == isbn){
        printf("\nCodigo ISBN já existe!\n");
        imprimeLivro(aux);
    }
    else{
        if(aux->isbn > isbn){
            novo->prox = aux;
            aux->ant = novo;
            (*L) = novo;
        }
        else if(aux->isbn < isbn){
            aux->prox = novo;
            novo->ant = aux;
        } else{
            novo->prox = aux;
            novo->ant = aux->ant;
            if (aux->ant == NULL) (*L) = novo;
            else{
                aux->ant->prox = novo;
            }
            aux->ant = novo;
        }
    }
}

void excluir(Livro **L, int isbn){
    Livro *aux = busca((*L), isbn);
    if(aux == NULL){
        printf("Livro nao existe no estoque\n");
    }
    else if(aux->isbn == isbn){
        if(aux->estoque > 0){
            aux->estoque--;
        }
        if(aux->estoque == 0){
            Livro *temp = aux;
            if(temp->ant == NULL && temp->prox == NULL) (*L) = NULL;
            else if(temp->ant == NULL){
                (*L) = temp->prox;
                temp->ant = NULL;
            } else if(temp->prox == NULL) temp->ant->prox = NULL;
            else{
                temp->ant->prox = temp->prox; // o anterior vai apontar pro proximo
                temp->prox->ant = temp->ant; // o proximo vai apontar pro anterior
            }
            free(temp);
        }
        printf("Livro excluido\n");
    } else{
        printf("Livro nao existe\n");
    }
}

void imprimeLivro(Livro *L){
    printf("ISBN: %d | ", L->isbn);
    printf("Titulo: %s | ", L->titulo);
    printf("Autor: %s | ", L->autor);
    printf("Estoque: %d\n", L->estoque);
}

void imprimeIsbn(Livro *L){
    printf("ISBN: %d\n", L->isbn);
}

void imprimeLista(Livro *L, int imprime){
    Livro *aux = L;

    if(aux == NULL){
        printf("Acervo está vazio!\n");
    }

    while(aux != NULL){
        if(imprime == 0) imprimeLivro(aux);
        if(imprime == 1) imprimeIsbn(aux);
        aux = aux->prox;
    }

    printf("\n");
}