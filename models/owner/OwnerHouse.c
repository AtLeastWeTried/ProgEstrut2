#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct informacao_casa {
    int num_casa;
    char status_casa;
};

struct informacao_casa stdWriteHouseOwner() {
    struct informacao_casa casa;
    printf("\nInforme o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("\nInforme o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;
}

void stdReadOwnerHouseAddress(struct informacao_casa _address) {
    printf("\n\n----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}
