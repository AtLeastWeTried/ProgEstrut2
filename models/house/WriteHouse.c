#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FILE_NAME "house.bin" 

struct info_loc {
    int reg_loc;
};

union data {
    char sigla;
    struct info_loc loc;
};

struct houseAddress {
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
};

struct house {
    int reg_imov; 
    struct houseAddress address;
    float area;
    int quartos;
    float valor;
    union data status;
};

int countHouses() {
    long int cont = 0;
    FILE *fptr = NULL;
    if((fptr = fopen(FILE_NAME, "rb")) == NULL){
        return cont;
    }
    else{
        fseek(fptr, 0 , 2);
        cont = ftell(fptr) / sizeof(struct house);
        fclose(fptr);
        return cont;
    }
}

struct house stdWriteHouse() {
    struct house _house;
    printf("\n----------Dados da casa----------\n");
    printf("\nArea em metros quadrados da casa: ");
    scanf("%f", &_house.area);
    printf("\nQuantos quartos a casa tem: ");
    scanf("%d", &_house.quartos);
    printf("\nValor da casa: ");
    scanf("%f", &_house.valor);
    printf("\nRegiao do imovel: ");
    scanf("%d", &_house.reg_imov);
    printf("\n----------Endereco da casa----------\n");
    printf("\nLogradouro: ");
    fflush(stdin);
    gets(_house.address.logradouro);
    printf("\nBairro: ");
    fflush(stdin);
    gets(_house.address.bairro);
    printf("\nCEP: ");
    fflush(stdin);
    gets(_house.address.CEP);
    printf("\nCidade: ");
    fflush(stdin);
    gets(_house.address.cidade);
    do {
        printf("\nSigla A para alugado, L para livre");
        fflush(stdin);
        scanf("%c", &_house.status.sigla);
        toupper(_house.status.sigla);
    } while(_house.status.sigla == 'L' || _house.status.sigla == 'A');
    return _house;
}