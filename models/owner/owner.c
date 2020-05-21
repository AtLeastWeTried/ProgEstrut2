#include <stdlib.h>
#include <string.h>
#include "../address/address.c"

struct owner {
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct address saddress;
};

void readOwner(struct owner _owener) {
    printf("informe o nome: ");
    gets(_owener.nome);
}