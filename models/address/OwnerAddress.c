#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct address{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
    char estado[20];
    char fone[15];
    char cel[15];
    char email[30];
};

struct address stdWriteAddress() {
    struct address _address;
    printf("informe o logradouro: "); 
    gets(_address.logradouro);
    printf("inform o bairro: ");
    gets(_address.bairro);
    printf("informe o CEP: ");
    gets(_address.CEP);
    printf("informe a cidade: ");
    gets(_address.cidade);
    printf("informe o estado: ");
    gets(_address.estado);
    printf("informe o fone: ");
    gets(_address.fone);
    printf("informe o cel: ");
    gets(_address.cel);
    printf("informe o email: ");
    gets(_address.email);
    return _address;
}

void stdReadAddress(struct address _address) {
    printf("----------Endereco do owner----------\n");
    printf("Logradouro: %s\n", _address.logradouro);
    printf("Bairro: %s\n", _address.bairro);
    printf("CEP: %s\n", _address.CEP);
    printf("Cidade: %s\n", _address.cidade);
    printf("Estado: %s\n", _address.estado);
    printf("Fone: %s\n", _address.fone);
    printf("Cel: %s\n", _address.cel);
    printf("Email: %s\n", _address.email);
}
