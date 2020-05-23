#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../address/HouseInfo.c"
#include "../../utils/colors.c"

#define DIRECTORY "house.bin" 

struct house{
    int reg_imov; // gerado automaticamente
    struct houseAdress address;
    float area;
    int quartos;
    float valor;
    union data status;
};
int countHouses(){
    long int cont = 0;
    FILE *fptr = NULL;
    if((fptr = fopen(DIRECTORY, "rb")) == NULL){
        return cont;
    }
    else{
        fseek(fptr, 0 , 2);
        cont = ftell(fptr) / sizeof(struct house);
        fclose(fptr);
        return cont;
    }
}
