#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FILE_NAME "house.bin"   //Arquivo contendo os dados da struct House
#define DIRECTORY "owner.bin"    //Arquivo contendo os dados da struct Owner

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
int countOwners();  //Contador de dados que existem no arquivo
struct addressOwner stdWriteAddressOwner(); //Cadastro da struct addressOwner
struct owner stdWriteOwner();   //Cadastro da struct geral owner
struct informacao_casa stdWriteHouseOwner();    //Cadastro da struct informacao_casa
void writeOwner(struct owner _owner);   //Escrita dos dados Owner para o arquivo
void stdReadOwner(struct owner _owner); //Mostra dos dados salvos referente ao Owner
void readOwners();  //Leitura dos dados contidos no arquivo referente ao owner
void searchByCPF(char cpf[15]); //Função para busca com filtro referente ao CPF
void stdReadAddressOwner(struct addressOwner _address); //Mostra dos dados da struct addressOwner
void stdReadOwnerHouseAddress(struct informacao_casa _address); //Mostra dos dados da struct informacao_casa

//HOUSE
void stdReadHouseAddress(struct houseAddress _house);   //Mostra dos dados referente a struct houseAddress
void stdReadHouse(struct house _house);     //Mostra dos dados referente a struct House
void readHouses(char op);   //Função da leitura dos dados adquiridos dentro do arquivo
int countHouses();  //Contador de quantos dados existem dentro do arquivo
struct house stdWriteHouse();   //Cadastro dos dados referente a struct House   
void writeHouse (struct house _house);  //Escrita dos dados house no arquivo

int main() { 
    int op;
    char cpf[15], parametro, opc;
    struct house _house;
    struct owner  _owner;
    do {
        fflush(stdin);
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Cadastrar casa\n[3] Consulta owners\n[4] Consulta casas\n[5] Sair\nOpcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
                system("cls");
                _owner = stdWriteOwner();
                writeOwner(_owner);
                break;
            case 2:
                system("cls");
                _house = stdWriteHouse();
                writeHouse(_house);
            break;
            case 3:
            system("cls");
                do {
                    printf("\nDeseja realizar uma consulta [T]total ou [P]parcial: ");
                    fflush(stdin);
                    scanf("%c", &opc);
                    opc = toupper(opc);
                } while (opc != 'T' && opc != 'P');
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
            
            case 4: 
                system("cls"); 
                do {    
                    printf("\nParametro da pesquisa [L]livre ou [A]alugado:");
                    fflush(stdin);
                    scanf("%c", &parametro);
                    parametro = toupper(parametro);
                } while(parametro != 'L' && parametro != 'A');
                fflush(stdin);
                readHouses(parametro); 
                break;
            case 5: printf("Fim do programa"); break;
            default: printf("Opcao nao existente"); break;
        }
    } while (op != 5);
}

// OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES //

//  OWNER GERAL
int countOwners(){  // Contagem dos dados contidos no arquivo owner.bin
    long int cont = 0;
    FILE *fptr = NULL;
    if((fptr = fopen(DIRECTORY, "rb")) == NULL){
        return cont;    //Retornaria 0 pois o arquivo ainda não existe.
    }
    else{
        fseek(fptr, 0 , 2);
        cont = ftell(fptr) / sizeof(struct owner);
        fclose(fptr);
        return cont;    //Retorna quantos dados dessa struct existem no arquivo owner.bin
    }
}

struct addressOwner stdWriteAddressOwner() {    //Função de cadastro básico referente a struct AddressOwner dentro da struct central owner.
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
    return _address;    //Retorna a nova struct.
}

struct owner stdWriteOwner() {  //Cadastro da struct Owner
    struct owner _owner;
    printf("Informe o nome: ");
    fflush(stdin);
    gets(_owner.nome);
    printf("Informe o CPF: ");
    fflush(stdin);
    gets(_owner.CPF);
    _owner.qntd_de_casas = 0; 
    _owner.reg_prop = 1 + countOwners();   //retorna quantos dados existem dentro do arquivo + 1 pois é um novo dado.
    _owner.sAddress = stdWriteAddressOwner();   //Escrita da struct interna addressOwner e retornando a mesma preenchida.
    _owner.sCasa = stdWriteHouseOwner();    //Escrita da struct interna informacao_casa e retornando a mesma preenchida.
    return _owner;  //Retorna a struct Owner toda preenchida.
}

struct informacao_casa stdWriteHouseOwner() {   //Cadastro da struct interna informacao_casa
    struct informacao_casa casa;
    printf("\nInforme o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("\nInforme o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa;    //Retorna a struct prenchida
}

void writeOwner(struct owner _owner) {  //Função de escrita dos dados no arquivo.
    FILE *file = fopen(DIRECTORY, "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        fwrite(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file);   //Fechamento do arquivo
}

void stdReadOwner(struct owner _owner) {    //Função de mostra dos dados referente ao owner.
    printf("\n----------Owner----------\n");
    printf("Nome: %s\n", _owner.nome);
    printf("CPF: %s\n", _owner.CPF);
    printf("Registro de proprietario: %d\n", _owner.reg_prop);
    stdReadAddressOwner(_owner.sAddress);   //Função que mostra os dados da struct interna addressOwner
    stdReadOwnerHouseAddress(_owner.sCasa); //Função que mostra os dados da struct interna informacao_casa
}

void readOwners() { //Função geral de Leitura dos dados
    int i;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb");    //Abertura do arquivo para a leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        for (i = 0; i < countOwners(); i++) {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            stdReadOwner(_owner);   //Função de leitura da struct adquirida.
        }
    fclose(file);   //Fechamento do arquivo
    }
    system("pause");
}

void searchByCPF(char cpf[15]) {    //Função para busca dos dados que se encontram com o CPF requerido
    int i, j, cmp;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb");    //Abertura do arquivo para leitura
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        for (i = 0; i < countOwners(); i++) {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            for (j = 0; j <= 15; j++) {
                cmp = strcmp(_owner.CPF, cpf);  //Comparação com o cpf passado com o atual dado pelo read
                if (cmp == 0) {    //Parametro que limita a leitura dos dados. 
                    fclose(file);
                    stdReadOwner(_owner);//Leitura da struct achada
                    return;
                }
            }
        }
        fclose(file);
    }
    printf("\nNenhum proprietario encontrado com este cpf\n");
}

// ENDERECO DO OWNER
void stdReadAddressOwner(struct addressOwner _address) {    //Leitura da struct addressOwner vinda da struct owner
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
void stdReadOwnerHouseAddress(struct informacao_casa _address) {    //Leitura da struct informação_casa vinda da struct owner
    printf("\n\n----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}

// HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES //

//READ CODES
void stdReadHouseAddress(struct houseAddress _house) { //Leitura dos dados referente a struct houseAddress
    printf("Logradouro da casa: %s\n", _house.logradouro);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
}

void stdReadHouse(struct house _house) {    //Leitura dos dados referente a struct geral house
    printf("\n----------Casa----------\n");
    printf("Quartos: %d\n", _house.quartos);
    printf("Area(m2): %.2f\n", _house.area);
    printf("Registro da casa: %d\n", _house.reg_imov);
    printf("Valor: %.2f\n",_house.valor);
    printf("\nStatus da casa: %c\n", _house.status.sigla);
    stdReadHouseAddress(_house.address);   //Função que fará a leitura da struct interna de House.
}

void readHouses(char op) {  //Função de leitura de Arquivo binário  
    int i;
    struct house _house;
    FILE *file = fopen(FILE_NAME, "rb");    //Abertura do Arquivo
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
    else {
        if(op == 'L'){  //Parâmetro para exibição de dados contendo sigla == L    
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'L')  //Parâmetro para exibição de dados contendo sigla == L
                    stdReadHouse(_house);
            }
        }
        else {      //Parâmetro para exibição de dados contendo sigla == A
            for (i = 0; i < countHouses(); i++) {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if(_house.status.sigla == 'A')  //Parâmetro para exibição de dados contendo sigla == A
                    stdReadHouse(_house);
            }
        }
    fclose(file);   //Fechamento do arquivo
    }
    system("pause");
}

// WRITE FUNCTIONS
int countHouses(){  //Função para a contagem e retorno da quantidade de dados existente no arquivo referente a Houses
    long int cont = 0;
    FILE *fptr = NULL;
    if((fptr = fopen(FILE_NAME, "rb")) == NULL){//Abertura do Arquivo
        return cont;    //Caso ele não ache, o retorno será 0 pois o arquivo não existe ainda;
    }
    else{
        fseek(fptr, 0 , 2);
        cont = ftell(fptr) / sizeof(struct house);      //Retorno da quantidade dos dados
        fclose(fptr);    //Fechamento do arquivo
        return cont;    //Retorna a quantidade calculada de dados existentes.
    }
}

struct house stdWriteHouse() {     //Função de cadastro básico da struct house
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
        printf("\nStatus A para alugado, L para livre: ");
        fflush(stdin);
        scanf("%c", &_house.status.sigla);
        _house.status.sigla = toupper(_house.status.sigla);
    } while(_house.status.sigla != 'L' && _house.status.sigla != 'A');
    return _house;  //Retorna a nova struct
}

void writeHouse (struct house _house) {  //Escrita dos dados armazenados na Ram para o arquivo house.bin
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("\nErro ao abrir o arquivo!");
    }
    else {
        fwrite(&_house, sizeof(struct house), 1, file);
    }
    fclose(file);
}