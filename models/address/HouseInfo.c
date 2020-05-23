#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct informacao_casa {
    int num_casa;
    char status_casa;
};
union data{
    char sigla;
    struct informacao_casa loc;

};

struct houseAddress{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
};



struct informacao_casa stdWriteHouse() {
    struct informacao_casa casa;
    printf("\nInforme o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("\nInforme o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;
}

void stdReadHouseData(union data _data){
    printf("\nSigla da casa: %s",_data.sigla);
    stdReadHouseAddress(_data.loc);
}

void stdReadHouseAddress(struct informacao_casa _address) {
    printf("\n\n----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}

void stdReadHouse(struct houseAddress _house) {
    printf("Logradouro da casa: %s\n", _house.logradouro);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
}