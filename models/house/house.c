#include "WriteHouse.c"

void stdReadHouseData(union data _data){
    printf("\nSigla da casa: %s", _data.sigla);
}

void stdReadHouseAddress(struct houseAddress _house) {
    printf("Logradouro da casa: %s\n", _house.logradouro);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
}

void stdReadHouse(struct house _house) {
    printf("\n----------Casa----------\n");
    printf("Quartos: %d\n", _house.quartos);
    printf("Area(m²): %f\n", _house.area);
    printf("Registro da casa: %d\n", _house.reg_imov);
    printf("Valor: %f\n",_house.valor);
    stdReadHouseData(_house.status);
    stdReadHouseAddress(_house.address);
}

void readHouses(char op) {
    int i;
    struct house _house;
    FILE *file = fopen(DIRECTORY, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        if(op == 'L') {    
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'L')  
                    stdReadHouse(_house);
            }
        }
        else {
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'O')  
                    stdReadHouse(_house);
            }
        }
    fclose(file);
    }
    system("pause");
}