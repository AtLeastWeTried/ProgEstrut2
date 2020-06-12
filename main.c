#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

// constantes de arquivos
#define IMOVEL_FILE       			"imovel.bin"        // Arquivo contendo os dados da struct House
#define PROPRIETARIO_FILE       "proprietario.bin"  // Arquivo contendo os dados da struct Owner
#define LOCATARIO_FILE 					"locatario.bin"     // Arquivo contendo os dados da struct locatario

// constantes semanticas
#define SAIR 									0
#define CRIAR_PROPRIETARIO 		1
#define CRIAR_IMOVEL 					2
#define LISTAR_PROPRIETARIO 	3
#define LISTAR_IMOVEIS 				4
#define ALUGAR_IMOVEL					5
#define LISTAR_LOCATARIOS			6
#define TERMINAR_CONTRATO			7
#define REALIZAR_ALTERACAO		8
#define GERAR_RELATORIO				9

struct addressOwner {
	char logradouro[80];
	char bairro[20];
	char CEP[10];
	char cidade[20];
	char estado[20];
	char fone[15];
	char cel[15];
	char email[30];
};

struct informacao_casa {
	int num_casa;
	char status_casa;
};

struct owner {
	int reg_prop;
	char nome[80];
	char CPF[15];
	int qntd_de_casas;
	struct addressOwner sAddress;
	struct informacao_casa sCasa;
};

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

struct date {
	int day;
	int month;
	int year;
};

struct locatario {
	int reg_loc; // gerado automaticamente
	char nome[80];
	char CPF[15];
	struct addressOwner end_loc;
	int reg_imov; // registro imóvel – buscar no arq. Imóvel
	int dia_venc;
	struct date inicio;
	struct date termino;
};

// Funcoes de Proprietario
int countOwners();                                              // Retorna a quantidade de proprietarios no arquivo
struct owner stdWriteOwner();                                   // Cadastro da struct geral owner
void writeOwner(struct owner _owner);                           // Escrita dos dados Owner para o arquivo
void stdReadOwner(struct owner _owner);                         // Mostra dos dados salvos referente ao Owner
void readOwners();                                              // Leitura dos dados contidos no arquivo referente ao owner
void searchByCPF(char cpf[15]);                                 // Função para busca com filtro referente ao CPF
int searchCPF_owner(char cpf[15]);
void altera_sigla_owner(int pos);

// Funcoes de imoveis
void stdReadHouseAddress(struct houseAddress _house); // Mostra dos dados referente a struct houseAddress
void stdReadHouse(struct house _house);               // Mostra dos dados referente a struct House
void readHouses(char op);                             // Função da leitura dos dados adquiridos dentro do arquivo
int countHouses();                                    // Contador de quantos dados existem dentro do arquivo
struct house stdWriteHouse();                         // Cadastro dos dados referente a struct House
struct house searchHouseByRegister(int _register);
void writeHouse(struct house _house);                 // Escrita dos dados house no arquivo
void readHouseBairro(char bairro[20]);
void readHouseRoom(int quartos);
void readHouseArea(float area);
int searchByRegister(int _register);
struct date inputDate();
struct locatario stdReadLocatario();
void stdWriteLocatario(struct locatario _locatario);
void writeLocatario(struct locatario _locatario);
void readLocatarios();
void alterStatusHouse(int reg);
void endContract(struct locatario _locatario);
struct locatario searchLocatariobyCPF(char cpf[15]);
int cmpDate(struct date _date1, struct date _date2);
void altera_sigla_house(int pos);

// Funcoes do locatario
int altera_locatario(int pos);
int altera_house(int pos);
int altera_owner(int pos);
int searchREG_house(int reg);
int searchCPF_locatario(char cpf[15]);
int countLocatario();
struct locatario search_locatario(char cpf[15]);
int deleta_locatario(struct locatario _locatario);
int compare_date(struct date _date1, struct date _date2);
struct owner searchOwnerByRegister(int _register);
void makeReport(struct date _date);

int getOptions();
void criar_proprietario();

int main() {
	int option;
	while((option = getOptions()) != 0) {
		switch (option) {
		case SAIR:
			printf("\nFim do programa.");
			getch();
			exit(1);
			break;
		case CRIAR_PROPRIETARIO:
			criar_proprietario();
			getch();
			break;
		case CRIAR_IMOVEL:
			printf("\nCRIAR_IMOVEL.");
			getch();
			break;
		case LISTAR_PROPRIETARIO:
			printf("\nLISTAR_PROPRIETARIO.");
			getch();
			break;
		case LISTAR_IMOVEIS:
			printf("\nLISTAR_IMOVEIS.");
			getch();
			break;
		case ALUGAR_IMOVEL:
			printf("\nALUGAR_IMOVEL.");
			getch();
			break;
		case LISTAR_LOCATARIOS:
			printf("\nLISTAR_LOCATARIOS.");
			getch();
			break;
		case TERMINAR_CONTRATO:
			printf("\nTERMINAR_CONTRATO.");
			getch();
			break;
		case REALIZAR_ALTERACAO:
			printf("\nREALIZAR_ALTERACAO.");
			getch();
			break;
		case GERAR_RELATORIO:
			printf("\nGERAR_RELATORIO.");
			getch();
			break;
		default:
			break;
		}
	}
}

int getOptions() {
	int option;
	system("CLS");
	printf("[0] Sair\n");
	printf("[1] Cadastro de proprietario\n");
	printf("[2] Cadastrar casa\n");
	printf("[3] Consultar proprietarios\n");
	printf("[4] Consultar imoveis\n");
	printf("[5] Aluguel imovel\n");
	printf("[6] Consultar locatarios\n");
	printf("[7] Termino do contrato\n");
	printf("[8] Alteracao de cadastros\n");
	printf("[9] Relatorio\n");
	printf("Opcao: ");
	scanf("%d", &option);
	if (option >= 0 && option <= 9) {
		return option;
	}
	else {
		printf("\nOpcao errada!\n");
		getch();
		return getOptions();
	}
}

// case CRIAR_PROPRIETARIO
void criar_proprietario() {
	struct owner _owner = stdWriteOwner();
	stdReadOwner(_owner);
}

// case CRIAR_IMOVEL
void criar_imovel() {

}

// case LISTAR_PROPRIETARIO
void listar_proprietarios() {
	
}

// case LISTAR_IMOVEIS
void listar_imoveis() {

}

// case ALUGAR_IMOVEL
void alugar_imovel() {

}


// case LISTAR_LOCATARIOS
void listar_locatarios() {

}

// case TERMINAR_CONTRATO
void terminar_contrato() {

}

// case REALIZAR_ALTERACAO
void realizar_alteracao() {

}

// case GERAR_RELATORIO
void gerar_relatorio() {

}

int countOwners() { 
	long int cont = 0;
	FILE *fptr = NULL;
	if ((fptr = fopen(PROPRIETARIO_FILE, "rb")) == NULL)
	{
		return cont; //Retornaria 0 pois o arquivo ainda não existe.
	}
	else
	{
		fseek(fptr, 0, 2);
		cont = ftell(fptr) / sizeof(struct owner);
		fclose(fptr);
		return cont; //Retorna quantos dados dessa struct existem no arquivo owner.bin
	}
}

void altera_sigla_owner(int pos) {
	FILE *fptr = NULL;
	struct owner _owner;
	if ((fptr = fopen("owner.bin", "rb+")) == NULL)
	{
		system("cls");
		printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
	}
	else
	{
		fseek(fptr, pos * sizeof(struct owner), 1);
		if(_owner.sCasa.status_casa == 'L'){
			_owner.sCasa.status_casa  = 'A';
		}
		else{
			_owner.sCasa.status_casa  = 'L';
		}
		fwrite(&_owner, sizeof(struct owner), 1, fptr);
	}
}

void altera_sigla_house(int pos) {
	FILE *fptr = NULL;
	struct house _house;
	if ((fptr = fopen("house.bin", "rb+")) == NULL)
	{
		system("cls");
		printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
	}
	else
	{
		fseek(fptr, pos * sizeof(struct house), 1);
		if(_house.status.sigla == 'L'){
				_house.status.sigla  = 'A';
		}
		else{
				_house.status.sigla  = 'L';
		}
		fwrite(&_house, sizeof(struct house), 1, fptr);
	}
}



int altera_owner(int pos) {
	int valida = 0;
	struct owner _owner;
	FILE *fptr = NULL;

	printf("\nRegistro inexistente\n\n");

	printf("Inicio da altarecao");

	printf("\nEm seguida digite os novos dados a serem alterados");
	_owner = stdWriteOwner();

	if ((fptr = fopen("owner.bin", "rb+")) == NULL) {
		system("cls");
		printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
		valida = 0;
		return valida;
	}
	else {
		fseek(fptr, pos * sizeof(struct owner), 1);
		fwrite(&_owner, sizeof(struct owner), 1, fptr);
		valida = 1;
	}
	fclose(fptr);

	printf("\nRegistro alterado com sucesso\n\n");
	return valida;
} //altera

int altera_house(int pos) {
	int valida = 0;
	struct house _house;
	FILE *fptr = NULL;

	printf("\nRegistro inexistente\n\n");

	printf("Inicio da altarecao");

	printf("\nEm seguida digite os novos dados a serem alterados");
	_house = stdWriteHouse();

	if ((fptr = fopen("house.bin", "rb+")) == NULL) {
			system("cls");
			printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
			valida = 0;
			return valida;
	}
	else {
			fseek(fptr, pos * sizeof(struct house), 1);
			fwrite(&_house, sizeof(struct house), 1, fptr);
			valida = 1;
	}
	fclose(fptr);

	printf("\nRegistro alterado com sucesso\n\n");
	return valida;
} //altera

int altera_locatario(int pos) {
	int valida = 0;
	struct locatario _locatario;
	FILE *fptr = NULL;

	printf("\nRegistro inexistente\n\n");

	printf("Inicio da altarecao");

	printf("\nEm seguida digite os novos dados a serem alterados");
	_locatario = stdReadLocatario();

	if ((fptr = fopen("locatario.bin", "rb+")) == NULL) {
		system("cls");
		printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
		valida = 0;
		return valida;
	}
	else {
		fseek(fptr, pos * sizeof(struct locatario), 1);
		fwrite(&_locatario, sizeof(struct locatario), 1, fptr);
		valida = 1;
	}
	fclose(fptr);

	printf("\nRegistro alterado com sucesso\n\n");
	return valida;
} //altera

int deleta_locatario(struct locatario _locatario) {
	int valida = 0;
	FILE *fptr = NULL;

	printf("\nRegistro inexistente\n\n");

	printf("Inicio da altarecao");
	_locatario.CPF[0] = '@';
	if ((fptr = fopen("locatario.bin", "rb+")) == NULL)	{
		system("cls");
		printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
		valida = 0;
		return valida;
	}
	else {
		fseek(fptr, _locatario.reg_loc * sizeof(struct locatario), 1);
		fwrite(&_locatario, sizeof(struct locatario), 1, fptr);
		valida = 1;
	}
	fclose(fptr);

	printf("\nRegistro Deletado com sucesso com sucesso\n\n");
	return valida;
} //altera

struct owner stdWriteOwner() { 
	struct owner _owner;
	_owner.qntd_de_casas = 0;
	_owner.reg_prop = 1 + countOwners();      //retorna quantos dados existem dentro do arquivo + 1 para o registro do proprietario começar em 1.
	printf("Informe o nome: ");
	fflush(stdin);
	gets(_owner.nome);
	printf("Informe o CPF: ");
	fflush(stdin);
	gets(_owner.CPF);
	printf("informe o logradouro: ");
	gets(_owner.sAddress.logradouro);
	printf("inform o bairro: ");
	gets(_owner.sAddress.bairro);
	printf("informe o CEP: ");
	gets(_owner.sAddress.CEP);
	printf("informe a cidade: ");
	gets(_owner.sAddress.cidade);
	printf("informe o estado: ");
	gets(_owner.sAddress.estado);
	printf("informe o fone: ");
	gets(_owner.sAddress.fone);
	printf("informe o cel: ");
	gets(_owner.sAddress.cel);
	printf("informe o email: ");
	gets(_owner.sAddress.email);
	printf("\nInforme o numero da casa: ");
	fflush(stdin);
	scanf("%d", &_owner.sCasa.num_casa);
	printf("\nInforme o status da casa: ");
	fflush(stdin);
	scanf("%c", &_owner.sCasa.status_casa);
	return _owner;                            //Retorna a struct Owner toda preenchida.
}

void writeOwner(struct owner _owner) { 
	FILE *file = fopen(PROPRIETARIO_FILE, "ab");
	if (file == NULL)	
		printf("Erro ao abrir o arquivo!\n");
	else 
		fwrite(&_owner, sizeof(struct owner), 1, file);

	fclose(file); //Fechamento do arquivo
}

void stdReadOwner(struct owner _owner) { 
	printf("\n----------Proprietario----------\n");
	printf("Nome: %s\n", _owner.nome);
	printf("CPF: %s\n", _owner.CPF);
	printf("Registro de proprietario: %d\n", _owner.reg_prop);
	printf("----------Endereco do proprietario----------\n");
	printf("Logradouro: %s\n", _owner.sAddress.logradouro);
	printf("Bairro: %s\n", _owner.sAddress.bairro);
	printf("CEP: %s\n", _owner.sAddress.CEP);
	printf("Cidade: %s\n", _owner.sAddress.cidade);
	printf("Estado: %s\n", _owner.sAddress.estado);
	printf("Fone: %s\n", _owner.sAddress.fone);
	printf("Cel: %s\n", _owner.sAddress.cel);
	printf("Email: %s\n", _owner.sAddress.email);
	printf("----------Endereco da casa----------\n");
	printf("Numero da casa: %d\n", _owner.sCasa.num_casa);
	printf("Status da casa: %c\n", _owner.sCasa.status_casa);
}

void readOwners() { 
	int i;
	struct owner _owner;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para a leitura
	if (file == NULL) {
		printf("Nenhum proprietario registrado.\n");
	}
	else {
		for (i = 0; i < countOwners(); i++) {
			fseek(file, i * sizeof(struct owner), SEEK_SET);
			fread(&_owner, sizeof(struct owner), 1, file);
			if(_owner.CPF != "@")
			stdReadOwner(_owner); //Função de leitura da struct adquirida.
		}
		fclose(file); //Fechamento do arquivo
	}
	system("pause");
}

void searchByCPF(char cpf[15]) { 
	int i, j, cmp;
	struct owner _owner;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countOwners(); i++)
		{
			fseek(file, i * sizeof(struct owner), SEEK_SET);
			fread(&_owner, sizeof(struct owner), 1, file);
			cmp = strcmp(_owner.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
			if (cmp == 0) { 
				fclose(file);
				stdReadOwner(_owner); //Leitura da struct achada
				return;
			}
		}
		fclose(file);
	}
	printf("\nNenhum proprietario encontrado com este cpf\n");
}

int searchCPF_owner(char cpf[15]) { //Função para busca dos dados que se encontram com o CPF requerido
	int i, j, cmp;
	struct owner _owner;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countOwners(); i++)
		{
			fseek(file, i * sizeof(struct owner), SEEK_SET);
			fread(&_owner, sizeof(struct owner), 1, file);
			cmp = strcmp(_owner.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
			if (cmp == 0) { //Parametro que limita a leitura dos dados.
				fclose(file);
				stdReadOwner(_owner); //Leitura da struct achada
				return i;
			}
		}
		fclose(file);
	}
	return -1;
	printf("\nNenhum proprietario encontrado com este cpf\n");
}

int searchREG_house(int reg) { //Função para busca dos dados que se encontram com o reg requerido
	int i, j;
	struct house _house;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countOwners(); i++) {
			fseek(file, i * sizeof(struct house), SEEK_SET);
			fread(&_house, sizeof(struct house), 1, file);
			//Comparação com o reg passado com o atual dado pelo read
			if (_house.reg_imov == reg) { 
				fclose(file);
				stdReadHouse(_house); //Leitura da struct achada
				return i;
			}
		}
		fclose(file);
	}
	return -1;
	printf("\nNenhum proprietario encontrado com este registro\n");
}

int searchCPF_locatario(char cpf[15]) {
	int i, j, cmp;
	struct locatario _locatario;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
			printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countOwners(); i++)	{
			fseek(file, i * sizeof(struct locatario), SEEK_SET);
			fread(&_locatario, sizeof(struct locatario), 1, file);
			cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
			if (cmp == 0)	{ 
				fclose(file);
				stdWriteLocatario(_locatario); //Leitura da struct achada
				return i;
			}
		}
		fclose(file);
	}
	return -1;
	printf("\nNenhum proprietario encontrado com este cpf\n");
}

struct locatario searchLocatariobyCPF(char cpf[15])
{
	int i, j, cmp;
	struct locatario _locatario;
	FILE *file = fopen(LOCATARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countLocatario(); i++) {
			fseek(file, i * sizeof(struct locatario), SEEK_SET);
			fread(&_locatario, sizeof(struct locatario), 1, file);
			cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
			if (cmp == 0) { //Parametro que limita a leitura dos dados.
				fclose(file);
				return _locatario;
			}
		}
		fclose(file);
	}
	printf("\nNenhum proprietario encontrado com este cpf\n");
}


void stdReadHouseAddress(struct houseAddress _house) {
	printf("Logradouro da casa: %s\n", _house.logradouro);
	printf("Bairro da casa: %s\n", _house.bairro);
	printf("CEP da casa: %s\n", _house.CEP);
	printf("Cidade da casa: %s\n", _house.cidade);
}

void stdReadHouse(struct house _house) { 
	printf("\n----------Casa----------\n");
	printf("Registro: %d\n", _house.reg_imov);
	printf("Quartos: %d\n", _house.quartos);
	printf("Area(m2): %.2f\n", _house.area);
	printf("Registro da casa: %d\n", _house.reg_imov);
	printf("Valor: %.2f\n", _house.valor);
	printf("\nStatus da casa: %c\n", _house.status.sigla);
	stdReadHouseAddress(_house.address); //Função que fará a leitura da struct interna de House.
}

void readHouses(char op) {
	int i;
	struct house _house;
	FILE *file = fopen(IMOVEL_FILE, "rb"); //Abertura do Arquivo
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		if (op == 'L') { 
			for (i = 0; i < countHouses(); i++) {
				fseek(file, i * sizeof(struct house), SEEK_SET);
				fread(&_house, sizeof(struct house), 1, file);
				if (_house.status.sigla == 'L') 
				stdReadHouse(_house);
			}
		}
		else { 
			for (i = 0; i < countHouses(); i++)
			{
				fseek(file, i * sizeof(struct house), SEEK_SET);
				fread(&_house, sizeof(struct house), 1, file);
				if (_house.status.sigla == 'A') //Parâmetro para exibição de dados contendo sigla == A
					stdReadHouse(_house);
			}
		}
		fclose(file); //Fechamento do arquivo
	}
	system("pause");
}

void readHouseBairro(char bairro[20])
{
	int i, j, cont = 0;
	struct house _house;
	char bairroCasa[20];
	
	for (j = 0; j < strlen(bairro); j++)
		bairro[j] = tolower(bairro[j]);

	FILE *file = fopen(IMOVEL_FILE, "rb"); //Abertura do Arquivo
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
			for (i = 0; i < countHouses(); i++) {
				fseek(file, i * sizeof(struct house), SEEK_SET);
				fread(&_house, sizeof(struct house), 1, file);
				strcpy(bairroCasa, _house.address.bairro);
				for (j = 0; j < strlen(bairroCasa); j++) {
					bairroCasa[j] = tolower(bairroCasa[j]);
				}
				if ((strcmp(bairroCasa, bairro)) == 0) {
					stdReadHouse(_house);
					cont++;
				}
			}
	}
	fclose(file); //Fechamento do arquivo
	if (cont == 0)
		printf("\nNao ha nenhuma casa no bairro %s\n", bairro);
	system("pause");
	return;
}
void readHouseRoom(int quartos)
{
	int i, j, cont = 0;
	struct house _house;
	FILE *file = fopen(IMOVEL_FILE, "rb"); //Abertura do Arquivo
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countHouses(); i++) {
			fseek(file, i * sizeof(struct house), SEEK_SET);
			fread(&_house, sizeof(struct house), 1, file);
			if (quartos == _house.quartos){
				stdReadHouse(_house);
				cont++;
			}
		}
	}
	fclose(file); //Fechamento do arquivo
	if (cont == 0) {
		printf("\nNao ha nenhuma casa com %d quartos\n", quartos);
	}
	system("pause");
	return;
}
void readHouseArea(float area)
{
	int i, j, cont = 0;
	struct house _house;
	FILE *file = fopen(IMOVEL_FILE, "rb"); //Abertura do Arquivo
	if (file == NULL) {
			printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countHouses(); i++) {
			fseek(file, i * sizeof(struct house), SEEK_SET);
			fread(&_house, sizeof(struct house), 1, file);
			if (area == _house.area) {
				stdReadHouse(_house);
				cont++;
			}
		}
	}
	fclose(file); //Fechamento do arquivo
	if (cont == 0) {
		printf("\nNao ha nenhuma casa com %.2fm2\n", area);
	}
	system("pause");
	return;
}
// WRITE FUNCTIONS
int countHouses() { 
	long int cont = 0;
	FILE *fptr = NULL;
	if ((fptr = fopen(IMOVEL_FILE, "rb")) == NULL) {                //Abertura do Arquivo
		return cont; //Caso ele não ache, o retorno será 0 pois o arquivo não existe ainda;
	}
	else {
		fseek(fptr, 0, 2);
		cont = ftell(fptr) / sizeof(struct house); //Retorno da quantidade dos dados
		fclose(fptr);                              //Fechamento do arquivo
		return cont;                               //Retorna a quantidade calculada de dados existentes.
	}
}

struct house stdWriteHouse() { //Função de cadastro básico da struct house
	struct house _house;
	printf("\n----------Dados da casa----------\n");
	printf("\nArea em metros quadrados da casa: ");
	scanf("%f", &_house.area);
	printf("\nQuantos quartos a casa tem: ");
	scanf("%d", &_house.quartos);
	printf("\nValor da casa: ");
	scanf("%f", &_house.valor);
	_house.reg_imov = 1 + countHouses();
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
	do
	{
		printf("\nStatus A para alugado, L para livre: ");
		fflush(stdin);
		scanf("%c", &_house.status.sigla);
		_house.status.sigla = toupper(_house.status.sigla);
	} while (_house.status.sigla != 'L' && _house.status.sigla != 'A');
	return _house; //Retorna a nova struct
}

void writeHouse(struct house _house) { //Escrita dos dados armazenados na ROM para o arquivo house.bin
	FILE *file = fopen(IMOVEL_FILE, "ab");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo!");
	}
	else {
		fwrite(&_house, sizeof(struct house), 1, file);
	}
	fclose(file);
}

int searchByRegister(int _register)
{
	struct house _house;
	FILE *file = fopen(IMOVEL_FILE, "rb");
	int i;
	if (file == NULL) {
		printf("\nNenhuma casa registrada.");
		fclose(file);
		return -1;
	}
	for (i = 0; i < countHouses(); i++) {
		fseek(file, i * sizeof(struct house), SEEK_SET);
		fread(&_house, sizeof(struct house), 1, file);
		if (_house.reg_imov == _register && _house.status.sigla == 'L')
		{
			printf("\nCasa Alugada.");
			fclose(file);
			return i;
		}
	}
	fclose(file);
	return -1;
}

struct house searchHouseByRegister(int _register)
{
	struct house _house;
	FILE *file = fopen(IMOVEL_FILE, "rb");
	int i;
	if (file == NULL) {
		printf("\nNenhuma casa registrada.");
		fclose(file);
	}
	else {
		for (i = 0; i < countHouses(); i++) {
			fseek(file, i * sizeof(struct house), SEEK_SET);
			fread(&_house, sizeof(struct house), 1, file);
			if (_house.reg_imov == _register)
			{
				fclose(file);
				return _house;
			}
		}
	}
	fclose(file);
}

struct owner searchOwnerByRegister(int _register)
{
	struct owner _owner;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb");
	int i;
	if (file == NULL) {
		printf("\nNenhuma casa registrada.");
		fclose(file);
	}
	else {
			for (i = 0; i < countHouses(); i++) {
				fseek(file, i * sizeof(struct house), SEEK_SET);
				fread(&_owner, sizeof(struct house), 1, file);
				if (_owner.reg_prop == _register) {
					fclose(file);
					return _owner;
				}
			}
	}
	fclose(file);
}

struct date inputDate() {
	struct date _date;
	int day, month, year, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, flag = 0;
	do {
		flag = 0;
		printf("no formato DD/MM/YYYY: ");
		scanf("%d/%d/%d", &day, &month, &year);
		if (year < 1980 || year > 3000)
		{
			printf("\nAno incorreto.\nInforme a data ");
			flag = 1;
		}
		else {
			if (month < 1 || month > 12) {
				printf("\nMes incorreto.\nInforme a data ");
				flag = 1;
			}
			else {
				months[1] = (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) ? 29 : 28;
				if (day < 1 || day > months[month - 1]) {
					printf("\nDia incorreto.\nInforme a data ");
					flag = 1;
				}
			}
		}
	} while (flag == 1);
	_date.day = day;
	_date.month = month;
	_date.year = year;
	return _date;
}

int countLocatario() {
	long int count = 0;
	FILE *fptr = NULL;
	if ((fptr = fopen(LOCATARIO_FILE, "rb")) == NULL) {                 //Abertura do Arquivo
		return count; //Caso ele não ache, o retorno será 0 pois o arquivo não existe ainda;
	}
	else {
		fseek(fptr, 0, 2);
		count = ftell(fptr) / sizeof(struct locatario); //Retorno da quantidade dos dados
		fclose(fptr);                                   //Fechamento do arquivo
		return count;                                   //Retorna a quantidade calculada de dados existentes.
	}
}

struct locatario stdReadLocatario() {
	struct locatario _locatario;
	printf("\n----------Dados Locatario----------\n");
	printf("\nNome: ");
	fflush(stdin);
	gets(_locatario.nome);
	printf("\nCPF: ");
	fflush(stdin);
	gets(_locatario.CPF);
	printf("\n----------Endereco Locatario----------\n");
	printf("\nEstado: ");
	fflush(stdin);
	gets(_locatario.end_loc.estado);
	printf("\nCidade: ");
	fflush(stdin);
	gets(_locatario.end_loc.cidade);
	printf("\nBairro: ");
	fflush(stdin);
	gets(_locatario.end_loc.bairro);
	printf("\nLogradouro: ");
	fflush(stdin);
	gets(_locatario.end_loc.logradouro);
	printf("\nCEP: ");
	fflush(stdin);
	gets(_locatario.end_loc.CEP);
	printf("\nTelefone: ");
	fflush(stdin);
	gets(_locatario.end_loc.fone);
	printf("\nCelular: ");
	fflush(stdin);
	gets(_locatario.end_loc.cel);
	printf("\nData inicial do contrato ");
	_locatario.inicio = inputDate();
	printf("\nData final do contrato ");
	_locatario.termino = inputDate();
	return _locatario;
}

void stdWriteLocatario(struct locatario _locatario) {
	printf("\n----------Dados Locatario----------\n");
	printf("\nRegistro de Locatario: %d", _locatario.reg_loc);
	printf("\nNome: %s", _locatario.nome);
	printf("\nCPF: %s", _locatario.CPF);
	printf("\nRegistro de Imovel: %d", _locatario.reg_imov);
	printf("\nData inicial do contrato: %d/%d/%d", _locatario.inicio.day, _locatario.inicio.month, _locatario.inicio.year);
	printf("\nData final do contrato: %d/%d/%d\n", _locatario.termino.day, _locatario.termino.month, _locatario.termino.year);
}

void writeLocatario(struct locatario _locatario) { //Escrita dos dados armazenados na ROM para o arquivo locatario.bin
	_locatario.reg_loc = countLocatario();
	FILE *file = fopen(LOCATARIO_FILE, "ab");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo!");
	}
	else {
		fwrite(&_locatario, sizeof(struct locatario), 1, file);
	}
	fclose(file);
}

void readLocatarios()
{ //Função geral de Leitura dos dados
	int i;
	struct locatario _locatario;
	FILE *file = fopen(LOCATARIO_FILE, "rb"); //Abertura do arquivo para a leitura
	if (file == NULL) {
		printf("Nenhum locatario registrado.\n");
	}
	else {
		printf("\nCountLocatario: %d\n", countLocatario());
		for (i = 0; i < countLocatario(); i++) {
			fseek(file, i * sizeof(struct locatario), SEEK_SET);
			fread(&_locatario, sizeof(struct locatario), 1, file);
			if(_locatario.CPF != "@")
			stdWriteLocatario(_locatario);
		}
		fclose(file); //Fechamento do arquivo
	}
	system("pause");
}

void alterStatusHouse(int reg) {
	struct house _house;
	char aux;
	_house = searchHouseByRegister(reg);
	printf("\nStatus atual: %c", _house.status.sigla);
	printf("\nStatus novo: ");
	fflush(stdin);
	scanf("%c", &aux);
	_house.status.sigla = aux;
	writeHouse(_house);
}

int cmpDate(struct date _date1, struct date _date2)
{
	if (_date2.year > _date1.year){
		return 0;
	}
	else if (_date2.month > _date1.month){
		return 0;
	}
	else if (_date2.day > _date1.day){
		return 0;
	}
	return 1;
}

void endContract(struct locatario _locatario) {
	struct date _date;
	stdReadLocatario(_locatario);
	printf("\nInforme a data atual: ");
	_date = inputDate();
	if (cmpDate(_date, _locatario.termino))	{
		printf("\nMulta: Valor do aluguel");
	}
	//_locatario.CPF = "@";
}

int searchCPF_house(int reg) { //Função para busca dos dados que se encontram com o reg requerido
	int i, j;
	struct house _house;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countOwners(); i++) {
			fseek(file, i * sizeof(struct house), SEEK_SET);
			fread(&_house, sizeof(struct house), 1, file);
			//Comparação com o reg passado com o atual dado pelo read
			if (_house.reg_imov == reg) { //Parametro que limita a leitura dos dados.
				fclose(file);
				stdReadHouse(_house); //Leitura da struct achada
				return i;
			}
		}
		fclose(file);
	}
	return -1;
	printf("\nNenhum proprietario encontrado com este registro\n");
}

struct locatario search_locatario(char cpf[15]) {
	int i, cmp;
	struct locatario _locatario;
	FILE *file = fopen(PROPRIETARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else {
		for (i = 0; i < countLocatario(); i++) {
			fseek(file, i * sizeof(struct locatario), SEEK_SET);
			fread(&_locatario, sizeof(struct locatario), 1, file);
			cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
			if (cmp == 0) { //Parametro que limita a leitura dos dados.
				fclose(file);
				stdWriteLocatario(_locatario); //Leitura da struct achada
				return _locatario;
			}
		}
		fclose(file);
	}
}

void makeReport(struct date _date) {
	int i, cmp;
	struct locatario _locatario;
	FILE *file = fopen(LOCATARIO_FILE, "rb"); //Abertura do arquivo para leitura
	if (file == NULL) {
		printf("Erro ao abrir o arquivo!\n");
	}
	else
	{
		for (i = 0; i < countLocatario(); i++) {
			fseek(file, i * sizeof(struct locatario), SEEK_SET);
			fread(&_locatario, sizeof(struct locatario), 1, file);
			if (compare_date(_date, _locatario.termino) == 0) {
				struct house _house = searchHouseByRegister(_locatario.reg_imov);
				printf("\nValor: %.2f", _house.valor);
				printf("\nRegistro da casa: %d", _house.reg_imov);
				printf("\nNome do locatario: %s", _locatario.nome);
			}
		}
		fclose(file);
	}
}

int compare_date(struct date _date1, struct date _date2) {
	if (_date1.day == _date2.day && _date1.month == _date2.month && _date1.year == _date2.year){
		return 0;
	}
	else {
		return 1;
	}
}
