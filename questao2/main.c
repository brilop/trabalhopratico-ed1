#include "livro.h"

int main(){
    Livro *L = NULL;

    insere(&L, 1, "titulo", "autor", 3);

    printf("%d\n%s\n%s\n%d\n", L->isbn, L->titulo, L->autor, L->estoque);

    return 0;
}