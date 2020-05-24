#include <stdio.h>
#include <stdlib.h>
#include "./OwnerHouse.c"
#include "./OwnerAddress.c"

#define DIRECTORY "owner.bin" 

struct owner {
    int reg_prop;
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct addressOwner sAddress;
    struct informacao_casa sCasa;
};

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
    _owner.sAddress = stdWriteAddressOwner();
    _owner.sCasa = stdWriteHouseOwner();
    return _owner;
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

void stdReadOwner(struct owner _owner) {
    printf("\n----------Owner----------\n");
    printf("Nome: %s\n", _owner.nome);
    printf("CPF: %s\n", _owner.CPF);
    printf("Registro de proprietario: %d\n", _owner.reg_prop);
    stdReadAddressOwner(_owner.sAddress);
    stdReadOwnerHouseAddress(_owner.sCasa);
}

void readOwners() {
    int i;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        for (i = 0; i < countOwners(); i++) {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            stdReadOwner(_owner);
        }
    }
    system("pause");
    fclose(file);
}

void searchByCPF(char cpf[15]) {
    int i, j, cmp;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        for (i = 0; i < countOwners(); i++) {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            for (j = 0; j <= 15; j++) {
                cmp = strcmp(_owner.CPF, cpf);
                if (cmp == 0) {
                    fclose(file);
                    stdReadOwner(_owner);
                    return;
                }
            }
        }
    }
    printf("\nNenhum proprietario encontrado com este cpf\n");
    fclose(file);
}