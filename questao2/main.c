#include "livro.h"

int main(){
    Livro *L = cria(1212, "Harry Potter", "JKRowling", 1);

    printf("%d\n%s\n%s\n%d\n", L->isbn,L->titulo, L->autor, L->estoque);

    return 0;
}