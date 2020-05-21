#include <stdlib.h>
#include <string.h>

struct owner {
    char nome[30];
};

void readOwner(struct owner _owener) {
    printf("informe o nome: ");
    gets(_owener.nome);
}