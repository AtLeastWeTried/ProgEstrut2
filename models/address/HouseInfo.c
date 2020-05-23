#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct informacao_casa {
    int num_casa;
    char status_casa;
};

struct houseAdress{
char logradouro[80];
char bairro[20];
char CEP[10];
char cidade[20];
};

struct informacao_casa stdWriteHouse() {
    struct informacao_casa casa;
    printf("Informe o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("Informe o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;
}
void stdReadHouseAddress(struct informacao_casa _address) {
    printf("----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}