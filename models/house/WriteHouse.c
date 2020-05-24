#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FILE_NAME "house.bin" 

struct info_loc{
    int reg_loc;
};
union data{
    char sigla;
    struct info_loc loc;
};


struct houseAddress{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
};

struct house{
    int reg_imov; 
    struct houseAddress address;
    float area;
    int quartos;
    float valor;
    union data status;
};

int countHouses(){
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