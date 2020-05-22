#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../address/OwnerAddress.c"
#include "../address/HouseAddress.c"

struct owner {
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct address sAddress;
    struct informacao_casa sCasa;
};

void stdReadOwner(struct owner *_owner) {
    printf("Informe o nome: ");
    fflush(stdin);
    gets(_owner->nome);
    printf("Informe o CPF: ");
    gets(_owner->CPF);
    printf("Informe a quantidade de casas: ");
    fflush(stdin);
    scanf("%d", _owner->qntd_de_casas);
}

void aloca_owner(struct owner **p_owner, int tam){
    if((*p_owner = (struct owner*)realloc(*p_owner, tam*sizeof(struct owner))) == NULL){
        printf("\nNao contem espaco vago.");
        exit(1);
    }
}