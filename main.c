#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FILE_NAME "house.bin" 
#define DIRECTORY "owner.bin" 

// STRUCTS --- STRUCTS --- STRUCTS --- STRUCTS --- STRUCTS //

// STRUCTS OWNER --- STRUCTS OWNER --- STRUCTS OWNER --- STRUCTS OWNER //

// STRUCTS ENDEREÇO DO OWNER
struct addressOwner{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
    char estado[20];
    char fone[15];
    char cel[15];
    char email[30];
};

// CASA DO OWNER
struct informacao_casa {
    int num_casa;
    char status_casa;
};
// OWNER
struct owner {
    int reg_prop;
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct addressOwner sAddress;
    struct informacao_casa sCasa;
};

// HOUSE STRUCTS --- HOUSE STRUCTS --- HOUSE STRUCTS --- HOUSE STRUCTS 
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

// ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES 
//OWNER
int countOwners();
struct addressOwner stdWriteAddressOwner();
struct owner stdWriteOwner();
struct informacao_casa stdWriteHouseOwner();
void writeOwner(struct owner _owner);
void stdReadOwner(struct owner _owner);
void readOwners();
void searchByCPF(char cpf[15]);
void stdReadAddressOwner(struct addressOwner _address);
void stdReadOwnerHouseAddress(struct informacao_casa _address);

//HOUSE
void stdReadHouseData(union data _data);
void stdReadHouseAddress(struct houseAddress _house);
void stdReadHouse(struct house _house);
void readHouses(char op);
int countHouses();
struct house stdWriteHouse();

int main() { 
    int op;
    char cpf[15], parametro, opc;
    do {
        fflush(stdin);
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Consulta Owners\n[3] Consulta Casas\n[4] Sair\nOpcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
                system("cls");
                struct owner _owner = stdWriteOwner();
                writeOwner(_owner);
                break;
            case 2:
                do {
                    printf("\nDeseja realizar uma consulta [T]total ou [P]parcial: ");
                    fflush(stdin);
                    scanf("%c", &opc);
                } while (opc == 'T' && opc == 'P' || opc == 't' && opc == 'p');
                if (opc == 'T' || opc == 't') {
                    system("cls"); 
                    readOwners();  
                }
                else if (opc == 'P' || opc == 'p') {
                    system("cls");
                    printf("Informe o CPF: ");
                    fflush(stdin);
                    gets(cpf);
                    searchByCPF(cpf);
                    system("pause");
                }
                break;
            case 3: 
                system("cls"); 
                printf("\nParametro da pesquisa [L]livre ou [O]ocupado:");
                do {    
                    fflush(stdin);
                    scanf("%c", &parametro);
                } while(parametro == 'L' && parametro == 'O' || parametro == 'l' && parametro == 'o');
                fflush(stdin);
                readHouses(parametro); 
                break;
            case 4: printf("Fim do programa"); break;
            default: printf("Opcao nao existente"); break;
        }
    } while (op != 4);
}

// OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES //

//  OWNER GERAL
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

struct addressOwner stdWriteAddressOwner() {
    struct addressOwner _address;
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

struct informacao_casa stdWriteHouseOwner() {
    struct informacao_casa casa;
    printf("\nInforme o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("\nInforme o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;
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

// ENDERECO DO OWNER
void stdReadAddressOwner(struct addressOwner _address) {
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

// CASA DO OWNER
void stdReadOwnerHouseAddress(struct informacao_casa _address) {
    printf("\n\n----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}

// HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES //

//READ CODES
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

// WRITE FUNCTIONS
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