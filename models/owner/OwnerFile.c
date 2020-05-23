#include <stdio.h>
#include <stdlib.h>
#include "../../utils/colors.c"
#include "../address/OwnerAddress.c"
#include "../address/HouseAddress.c"
#include "./owner.c"

#define DIRECTORY "owner.bin" 

void writeOwner(struct owner _owner) {
    FILE *file = fopen(DIRECTORY, "ab");
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
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf(RED "Erro ao abrir o arquivo!\n" RESET_COLOR);
    }
    else {
        fread(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file);
    return _owner;
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
