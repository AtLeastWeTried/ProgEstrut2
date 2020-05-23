#include <stdio.h>
#include <stdlib.h>
#include "../../utils/colors.c"
#include "../address/OwnerAddress.c"
#include "../address/HouseAddress.c"

#define DIRETORY "owner.bin" 

struct owner {
    int reg_prop;
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct address sAddress;
    struct informacao_casa sCasa;
};

struct owner stdReadOwner() {
    struct owner _owner;
    printf("Informe o nome: ");
    fflush(stdin);
    gets(_owner.nome);
    printf("Informe o CPF: ");
    fflush(stdin);
    gets(_owner.CPF);
    _owner.qntd_de_casas = 0;
    _owner.reg_prop = 0;
    _owner.sAddress = stdReadAddress();
    _owner.sCasa = stdReadHouse();
    return _owner;
}

void stdWriteOwner(struct owner _owner) {
    printf("----------Owner:----------");
    printf("Nome: %s\n", _owner.nome);
    printf("CPF: %s\n", _owner.CPF);
    printf("----------Fim do owner----------");
    stdWriteAddress(_owner.sAddress);
    stdWriteHouseAddress(_owner.sCasa);
}

void writeOwner(struct owner _owner) {
    FILE *file = fopen(DIRETORY, "ab");
    if (file == NULL) {
        printf(RED "Erro ao abrir o arquivo!\n" RESET_COLOR);
    }
    else {
        fwrite(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file);
}

struct owner readOwner() {
    struct owner _owner;
    FILE *file = fopen(DIRETORY, "rb");
    if (file == NULL) {
        printf(RED "Erro ao abrir o arquivo!\n" RESET_COLOR);
    }
    else {
        fread(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file);
    return _owner;
}