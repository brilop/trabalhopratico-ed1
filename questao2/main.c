#include "livro.h"

void menuInsere(Livro **L); // receber titulo e autor com espaco
void menuBuscar(Livro *L);
void menuExcluir(Livro **L);

int main(){
    Livro *L = NULL;

    int opcao, continua = 0;

    while(continua == 0){
        printf("Selecione uma opcao\n");
        printf("1 - Imprimir acervo\n");
        printf("2 - Inserir livro\n");
        printf("3 - Buscar livro\n");
        printf("4 - Imprimir ISBN's\n");
        printf("5 - Excluir livro\n");
        printf("6 - Sair\n");

        printf("--> ");
        scanf("%d", &opcao);
        printf("\n");


        if(opcao == 1) imprimeLista(L, 0);
        if(opcao == 2) menuInsere(&L);
        if(opcao == 3) menuBuscar(L);
        if(opcao == 4) imprimeLista(L, 1);
        if(opcao == 5) menuExcluir(&L);
        if(opcao == 6) break;
    }

    return 0;
}

void menuInsere(Livro **L){
    int isbn, estoque;
    char titulo[100], autor[100];

    printf("Digite o ISBN: ");
    scanf("%d", &isbn);
    setbuf(stdin, NULL);
    printf("Digite o titulo: ");
    fgets(titulo, 99, stdin);
    setbuf(stdin, NULL);
    printf("Digite o autor: ");
    fgets(autor, 99, stdin);
    setbuf(stdin, NULL);
    printf("Digite o numero de exemplares: ");
    scanf("%d", &estoque);
    setbuf(stdin, NULL);

    insere(L, isbn, titulo, autor, estoque);
    printf("\n");
}

void menuBuscar(Livro *L){
    int isbn;
    printf("Digite o ISBN a ser buscado: ");
    scanf("%d", &isbn);

    Livro *buscado = busca(L, isbn);

    if(buscado == NULL) printf("Acervo esta vazio\n");
    else if(buscado->isbn == isbn) imprimeLivro(buscado);
    else printf("Livro nao encontrado no acervo\n");

    printf("\n");
}

void menuExcluir(Livro **L){
    int isbn;
    printf("Digite o ISBN a ser excluido: ");
    scanf("%d", &isbn);

    excluir(L, isbn);
    printf("\n");
}