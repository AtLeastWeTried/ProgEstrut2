#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct informacao_casa {
    int num_casa;
    char status_casa;
};

struct informacao_casa stdReadHouse() {
    struct informacao_casa casa;
    printf("Informe o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("Informe o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;
}
void stdWriteHouseAddress(struct informacao_casa _address) {
    printf("----------Endereco da casa:----------");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
    printf("----------Fim do endereco da casa----------");
}