#include <stdio.h>
#include <stdlib.h>
#include "../../utils/colors.c"
#include "../address/OwnerAddress.c"
#include "../address/HouseInfo.c"

#define DIRECTORY "owner.bin" 

struct owner {
    int reg_prop;
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct address sAddress;
    struct informacao_casa sCasa;
};

void alocaOwner(struct owner **_owner ,int tam) {
    if((*_owner = (struct owner*)realloc(*_owner,tam*sizeof(struct owner)))==NULL)
      exit(1);
}

int countOwners(){
    long int cont = 0;
    FILE *fptr = NULL;
    if((fptr = fopen(DIRECTORY, "rb")) == NULL){
        return cont;
    }
    else{
        fseek(fptr, 0 , 2);
        cont = ftell(fptr) / sizeof(struct owner);
        fclose(fptr);
        return cont;
    }
}

struct owner stdWriteOwner() {
    struct owner _owner;
    printf("Informe o nome: ");
    fflush(stdin);
    gets(_owner.nome);
    printf("Informe o CPF: ");
    fflush(stdin);
    gets(_owner.CPF);
    _owner.qntd_de_casas = 0;
    _owner.reg_prop = countOwners();
    _owner.sAddress = stdWriteAddress();
    _owner.sCasa = stdWriteHouse();
    return _owner;
}

void stdReadOwner(struct owner _owner) {
    printf("----------Owner----------\n");
    printf("Nome: %s\n", _owner.nome);
    printf("CPF: %s\n", _owner.CPF);
    printf("Registro de proprietario: %d\n", _owner.reg_prop);
    stdReadAddress(_owner.sAddress);
    stdReadHouseAddress(_owner.sCasa);
}

void writeOwner(struct owner _owner) {
    FILE *file = fopen(DIRECTORY, "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        fwrite(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file);
}

struct owner readOwner(int n) {
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        fread(&_owner, sizeof(struct owner), n, file);
    }
    fclose(file);
    return _owner;
}