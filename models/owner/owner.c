#include <stdlib.h>
#include <string.h>
#include "../address/address.c"

struct owner {
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct address saddress;
};

void readOwner(struct owner *_owner) {
    printf("informe o nome: ");
    gets(_owner->nome);
}
void aloca_owner(struct owner **p_owner,int tam){
    if((*p_owner = (struct owner *)realloc(*p_owner, tam*sizeof(struct owner))) == NULL){
        printf("\nNao contem espaço vago.");
    }
}