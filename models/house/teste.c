#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../owner/OwnerHouse.c"

#define DIRECTORY "house.bin" 

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

void readHouses(char op) {
    int i;
    struct house _house;
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        if(op == 'L'){    
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'L')  
                    stdReadH(_house);
            }
        }
        else{
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'O')  
                    stdReadH(_house);
            }
        }
    fclose(file);
    }
    system("pause");
    
}

/*void stdReadH(struct house _house) {
    printf("Logradouro da casa: %s\n", _house.);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
    printf("\nSigla da casa: %s", _data.sigla);
    stdReadHouseAddress(_data.loc);
    printf("\n----------House----------\n");
    stdReadHouse(_house.address);
    stdReadHouseData(_house.status);
    printf("Quartos: %d\n", _house.quartos);
    printf("Area(m²): %f\n", _house.area);
    printf("Registro da casa: %d\n", _house.reg_imov);
    printf("Valor: %f\n",_house.valor);
   
}*/

/*void stdReadHouseData(union data _data){
    printf("\nSigla da casa: %s", _data.sigla);
    stdReadHouseAddress(_data.loc);
}*/

/*void stdReadHouse(struct houseAddress _house) {
    printf("Logradouro da casa: %s\n", _house.logradouro);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
}*/