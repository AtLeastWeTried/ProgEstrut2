#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FILE_NAME "house.bin"           //Arquivo contendo os dados da struct House
#define DIRECTORY "owner.bin"           //Arquivo contendo os dados da struct Owner
#define FILE_LOCATAERIO "locatario.bin" //Arquivo contendo os dados da struct locatario

// STRUCTS --- STRUCTS --- STRUCTS --- STRUCTS --- STRUCTS //

// STRUCTS OWNER --- STRUCTS OWNER --- STRUCTS OWNER --- STRUCTS OWNER //

// STRUCTS ENDEREÇO DO OWNER
struct addressOwner
{
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
struct informacao_casa
{
    int num_casa;
    char status_casa;
};
// OWNER
struct owner
{
    int reg_prop;
    char nome[80];
    char CPF[15];
    int qntd_de_casas;
    struct addressOwner sAddress;
    struct informacao_casa sCasa;
};

// HOUSE STRUCTS --- HOUSE STRUCTS --- HOUSE STRUCTS --- HOUSE STRUCTS
struct info_loc
{
    int reg_loc;
};

union data {
    char sigla;
    struct info_loc loc;
};

struct houseAddress
{
    char logradouro[80];
    char bairro[20];
    char CEP[10];
    char cidade[20];
};

struct house
{
    int reg_imov;
    struct houseAddress address;
    float area;
    int quartos;
    float valor;
    union data status;
};

struct date
{
    int day;
    int month;
    int year;
};

struct locatario
{
    int reg_loc; // gerado automaticamente
    char nome[80];
    char CPF[15];
    struct addressOwner end_loc;
    int reg_imov; // registro imóvel – buscar no arq. Imóvel
    int dia_venc;
    struct date inicio;
    struct date termino;
};

// ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES --- ESCOPOS FUNÇÕES
//OWNER
int countOwners();                                              //Contador de dados que existem no arquivo
struct addressOwner stdWriteAddressOwner();                     //Cadastro da struct addressOwner
struct owner stdWriteOwner();                                   //Cadastro da struct geral owner
struct informacao_casa stdWriteHouseOwner();                    //Cadastro da struct informacao_casa
void writeOwner(struct owner _owner);                           //Escrita dos dados Owner para o arquivo
void stdReadOwner(struct owner _owner);                         //Mostra dos dados salvos referente ao Owner
void readOwners();                                              //Leitura dos dados contidos no arquivo referente ao owner
void searchByCPF(char cpf[15]);                                 //Função para busca com filtro referente ao CPF
void stdReadAddressOwner(struct addressOwner _address);         //Mostra dos dados da struct addressOwner
void stdReadOwnerHouseAddress(struct informacao_casa _address); //Mostra dos dados da struct informacao_casa
int searchCPF_owner(char cpf[15]);

//HOUSE
void stdReadHouseAddress(struct houseAddress _house); //Mostra dos dados referente a struct houseAddress
void stdReadHouse(struct house _house);               //Mostra dos dados referente a struct House
void readHouses(char op);                             //Função da leitura dos dados adquiridos dentro do arquivo
int countHouses();                                    //Contador de quantos dados existem dentro do arquivo
struct house stdWriteHouse();                         //Cadastro dos dados referente a struct House
struct house searchHouseByRegister(int _register);
void writeHouse(struct house _house); //Escrita dos dados house no arquivo
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

int altera_locatario(int pos);
int altera_house(int pos);
int altera_owner(int pos);
int searchREG_house(int reg);
int searchCPF_locatario(char cpf[15]);
int countLocatario();
struct locatario search_locatario(char cpf[15]);

int main()
{
    int op, want_rent, reg_num, pos, reg, opcao8, check,dat;
    char cpf[15], parametro, opc, escolha;
    struct house _house;
    struct owner _owner;
    struct locatario _locatario;
    do
    {
        fflush(stdin);
        system("cls");
        printf("[0] Sair\n[1] Cadastro de proprietario\n[2] Cadastrar casa\n[3] Consulta proprietarios\n[4] Consulta casas\n[5] Aluguel\n[6] Consulta locatarios\n[7] Alterar sigla\n[8]Termino do contrato\n[9]Alteracao de cadastros\nOpcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("Fim do programa");
            break;
        case 1:
            system("cls");
            _owner = stdWriteOwner();
            writeOwner(_owner);
            break;
        case 2:
            system("cls");
            if (countOwners() == 0)
            {
                printf("\nNão existem proprietarios registrados.");
            }
            else
            {
                _house = stdWriteHouse();
                writeHouse(_house);
            }
            break;
        case 3:
            system("cls");
            do
            {
                printf("\nDeseja realizar uma consulta [T]total ou [P]parcial: ");
                fflush(stdin);
                scanf("%c", &opc);
                opc = toupper(opc);
            } while (opc != 'T' && opc != 'P');
            if (opc == 'T')
            {
                system("cls");
                readOwners();
            }
            else if (opc == 'P')
            {
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
            do
            {
                printf("\nDeseja fazer uma consula [T]total ou  [P]parcial: ");
                fflush(stdin);
                scanf("%c", &escolha);
                escolha = toupper(escolha);
            } while (escolha != 'T' && escolha != 'P');
            if (escolha == 'T')
            {
                do
                {
                    printf("\nParametro da pesquisa [L]livre ou [A]alugado: ");
                    fflush(stdin);
                    scanf("%c", &parametro);
                    parametro = toupper(parametro);
                } while (parametro != 'L' && parametro != 'A');
                fflush(stdin);
                readHouses(parametro);
            }
            else
            {
                system("cls");
                float area;
                int quartos, opp;
                char bairro[20];
                do
                {
                    system("cls");
                    printf("\nDeseja fazer consulta com:\n[1] Area util\n[2] Quantidade de quartos\n[3] Bairro\nOpcao: ");
                    scanf("%d", &opp);
                } while (opp < 1 || opp > 3);
                system("cls");
                switch (opp)
                {
                case 1:
                    printf("\nArea util: ");
                    scanf("%f", &area);
                    readHouseArea(area);
                    break;
                case 2:
                    printf("\nQuantidade de quartos: ");
                    scanf("%d", &quartos);
                    readHouseRoom(quartos);
                    break;
                case 3:
                    printf("Bairro: ");
                    fflush(stdin);
                    gets(bairro);
                    readHouseBairro(bairro);
                    break;
                default:
                    printf("Easteregg, Achievement Unlocked");
                    break;
                }
            }
            break;
        case 5:
            system("cls");
            printf("\n----------Casas Para Aluguel----------\n");
            readHouses('L');
            printf("\nRegistro do imovel que deseja alugar: ");
            scanf("%d", &reg_num);
            pos = searchByRegister(reg_num);
            printf("\nPos: %d", pos);
            if (pos < 0)
            {
                printf("\nRegistro inexistente.");
                system("pause");
                break;
            }
            _locatario = stdReadLocatario();
            _locatario.reg_imov = pos + 1;
            writeLocatario(_locatario);
            break;
        case 6:
            system("cls");
            readLocatarios();
            break;
        case 7:
            printf("\nRegistro da casa a alterar: ");
            scanf("%d", &reg);
            alterStatusHouse(reg);
            break;
        case 8:

            printf("\nComece digitando o seu cpf");
            scanf("%d", &cpf);
            _locatario = search_locatario(cpf);
            stdWriteLocatario(_locatario);
            printf("\nDigite o ano atual: ");
            scanf("%d", &dat);
            
            
            if (dat > _locatario.termino.year)
            {
                printf("\nDigite agora o mes atual");
                scanf("%d", &dat);
                if (dat >_locatario.termino.month)
                {
                    printf("\nDigite agora o dia atual");
                    scanf("%d", &dat);
                    if (dat == _locatario.termino.day)
                    {
                    }
                }
            }
            break;
        case 9:
            printf("\nRealizar alteracao em:\n[1]Proprietario\t[2]Imovel\t[3]Locatario");
            scanf("%d", &opcao8);
            switch (opcao8)
            {
            case 1:
                printf("Digite o CPF do proprietario");
                fflush(stdin);
                gets(cpf);
                check = searchCPF_owner(cpf);
                check = altera_owner(check);
                if (check == 1)
                {
                    printf("\n\nLeitura dos dados finalizados.");
                    readOwners();
                }
                break;

            case 2:
                printf("Digite numero de registro do imovel");
                fflush(stdin);
                scanf("%d", &reg);
                check = searchREG_house(check);
                check = altera_house(check);
                if (check == 1)
                {
                    printf("\n\nLeitura dos dados finalizados.");
                    // readHouses();
                }
                break;
            case 3:
                printf("Digite numero de CPF do locatario");
                fflush(stdin);
                gets(cpf);
                check = searchCPF_locatario(cpf);
                check = altera_locatario(check);
                if (check == 1)
                {
                    printf("\n\nLeitura dos dados finalizados.");
                    readLocatarios();
                }

                break;
            }
            break;
        default:
            printf("Opcao nao existente");
            break;
        }
    } while (op != 0);
    system("cls");
}

// OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES --- OWNER CODES //

//  OWNER GERAL
int countOwners()
{ // Contagem dos dados contidos no arquivo owner.bin
    long int cont = 0;
    FILE *fptr = NULL;
    if ((fptr = fopen(DIRECTORY, "rb")) == NULL)
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

struct addressOwner stdWriteAddressOwner()
{ //Função de cadastro básico referente a struct AddressOwner dentro da struct central owner.
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
    return _address; //Retorna a nova struct.
}

int altera_owner(int pos)
{
    int valida = 0;
    struct owner _owner;
    FILE *fptr = NULL;

    printf("\nRegistro inexistente\n\n");

    printf("Inicio da altarecao");

    printf("\nEm seguida digite os novos dados a serem alterados");
    _owner = stdWriteOwner();

    if ((fptr = fopen("owner.bin", "rb+")) == NULL)
    {
        system("cls");
        printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
        valida = 0;
        return valida;
    }
    else
    {
        fseek(fptr, pos * sizeof(struct owner), 1);
        fwrite(&_owner, sizeof(struct owner), 1, fptr);
        valida = 1;
    }
    fclose(fptr);

    printf("\nRegistro alterado com sucesso\n\n");
    return valida;

} //altera

int altera_house(int pos)
{
    int valida = 0;
    struct house _house;
    FILE *fptr = NULL;

    printf("\nRegistro inexistente\n\n");

    printf("Inicio da altarecao");

    printf("\nEm seguida digite os novos dados a serem alterados");
    _house = stdWriteHouse();

    if ((fptr = fopen("house.bin", "rb+")) == NULL)
    {
        system("cls");
        printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
        valida = 0;
        return valida;
    }
    else
    {
        fseek(fptr, pos * sizeof(struct house), 1);
        fwrite(&_house, sizeof(struct house), 1, fptr);
        valida = 1;
    }
    fclose(fptr);

    printf("\nRegistro alterado com sucesso\n\n");
    return valida;

} //altera

int altera_locatario(int pos)
{
    int valida = 0;
    struct locatario _locatario;
    FILE *fptr = NULL;

    printf("\nRegistro inexistente\n\n");

    printf("Inicio da altarecao");

    printf("\nEm seguida digite os novos dados a serem alterados");
    _locatario = stdReadLocatario();

    if ((fptr = fopen("locatario.bin", "rb+")) == NULL)
    {
        system("cls");
        printf("\nERRO AO TENTAR ABRIR O ARQUIVO NA ALTERACAO");
        valida = 0;
        return valida;
    }
    else
    {
        fseek(fptr, pos * sizeof(struct locatario), 1);
        fwrite(&_locatario, sizeof(struct locatario), 1, fptr);
        valida = 1;
    }
    fclose(fptr);

    printf("\nRegistro alterado com sucesso\n\n");
    return valida;

} //altera

struct owner stdWriteOwner()
{ //Cadastro da struct Owner
    struct owner _owner;
    printf("Informe o nome: ");
    fflush(stdin);
    gets(_owner.nome);
    printf("Informe o CPF: ");
    fflush(stdin);
    gets(_owner.CPF);
    _owner.qntd_de_casas = 0;
    _owner.reg_prop = 1 + countOwners();      //retorna quantos dados existem dentro do arquivo + 1 para o registro do proprietario começar em 1.
    _owner.sAddress = stdWriteAddressOwner(); //Escrita da struct interna addressOwner e retornando a mesma preenchida.
    _owner.sCasa = stdWriteHouseOwner();      //Escrita da struct interna informacao_casa e retornando a mesma preenchida.
    return _owner;                            //Retorna a struct Owner toda preenchida.
}

struct informacao_casa stdWriteHouseOwner()
{ //Cadastro da struct interna informacao_casa
    struct informacao_casa casa;
    printf("\nInforme o numero da casa: ");
    fflush(stdin);
    scanf("%d", &casa.num_casa);
    printf("\nInforme o status da casa: ");
    fflush(stdin);
    scanf("%c", &casa.status_casa);
    return casa; //Retorna a struct prenchida
}

void writeOwner(struct owner _owner)
{ //Função de escrita dos dados no arquivo.
    FILE *file = fopen(DIRECTORY, "ab");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        fwrite(&_owner, sizeof(struct owner), 1, file);
    }
    fclose(file); //Fechamento do arquivo
}

void stdReadOwner(struct owner _owner)
{ //Função de mostra dos dados referente ao owner.
    printf("\n----------Proprietario----------\n");
    printf("Nome: %s\n", _owner.nome);
    printf("CPF: %s\n", _owner.CPF);
    printf("Registro de proprietario: %d\n", _owner.reg_prop);
    stdReadAddressOwner(_owner.sAddress);   //Função que mostra os dados da struct interna addressOwner
    stdReadOwnerHouseAddress(_owner.sCasa); //Função que mostra os dados da struct interna informacao_casa
}

void readOwners()
{ //Função geral de Leitura dos dados
    int i;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para a leitura
    if (file == NULL)
    {
        printf("Nenhum proprietario registrado.\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            stdReadOwner(_owner); //Função de leitura da struct adquirida.
        }
        fclose(file); //Fechamento do arquivo
    }
    system("pause");
}

void searchByCPF(char cpf[15])
{ //Função para busca dos dados que se encontram com o CPF requerido
    int i, j, cmp;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            cmp = strcmp(_owner.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
            if (cmp == 0)
            { //Parametro que limita a leitura dos dados.
                fclose(file);
                stdReadOwner(_owner); //Leitura da struct achada
                return;
            }
        }
        fclose(file);
    }
    printf("\nNenhum proprietario encontrado com este cpf\n");
}

int searchCPF_owner(char cpf[15])
{ //Função para busca dos dados que se encontram com o CPF requerido
    int i, j, cmp;
    struct owner _owner;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct owner), SEEK_SET);
            fread(&_owner, sizeof(struct owner), 1, file);
            cmp = strcmp(_owner.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
            if (cmp == 0)
            { //Parametro que limita a leitura dos dados.
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

int searchREG_house(int reg)
{ //Função para busca dos dados que se encontram com o reg requerido
    int i, j;
    struct house _house;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct house), SEEK_SET);
            fread(&_house, sizeof(struct house), 1, file);
            //Comparação com o reg passado com o atual dado pelo read
            if (_house.reg_imov == reg)
            { //Parametro que limita a leitura dos dados.
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
int searchCPF_locatario(char cpf[15])
{ //Função para busca dos dados que se encontram com o CPF requerido
    int i, j, cmp;
    struct locatario _locatario;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct locatario), SEEK_SET);
            fread(&_locatario, sizeof(struct locatario), 1, file);
            cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
            if (cmp == 0)
            { //Parametro que limita a leitura dos dados.
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
    FILE *file = fopen(FILE_LOCATAERIO, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countLocatario(); i++)
        {
            fseek(file, i * sizeof(struct locatario), SEEK_SET);
            fread(&_locatario, sizeof(struct locatario), 1, file);
            cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
            if (cmp == 0)
            { //Parametro que limita a leitura dos dados.
                fclose(file);
                return _locatario;
            }
        }
        fclose(file);
    }
    printf("\nNenhum proprietario encontrado com este cpf\n");
}

// ENDERECO DO OWNER
void stdReadAddressOwner(struct addressOwner _address)
{ //Leitura da struct addressOwner vinda da struct owner
    printf("----------Endereco do proprietario----------\n");
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
void stdReadOwnerHouseAddress(struct informacao_casa _address)
{ //Leitura da struct informação_casa vinda da struct owner
    printf("----------Endereco da casa----------\n");
    printf("Numero da casa: %d\n", _address.num_casa);
    printf("Status da casa: %c\n", _address.status_casa);
}

// HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES --- HOUSE CODES //

//READ CODES
void stdReadHouseAddress(struct houseAddress _house)
{ //Leitura dos dados referente a struct houseAddress
    printf("Logradouro da casa: %s\n", _house.logradouro);
    printf("Bairro da casa: %s\n", _house.bairro);
    printf("CEP da casa: %s\n", _house.CEP);
    printf("Cidade da casa: %s\n", _house.cidade);
}

void stdReadHouse(struct house _house)
{ //Leitura dos dados referente a struct geral house
    printf("\n----------Casa----------\n");
    printf("Registro: %d\n", _house.reg_imov);
    printf("Quartos: %d\n", _house.quartos);
    printf("Area(m2): %.2f\n", _house.area);
    printf("Registro da casa: %d\n", _house.reg_imov);
    printf("Valor: %.2f\n", _house.valor);
    printf("\nStatus da casa: %c\n", _house.status.sigla);
    stdReadHouseAddress(_house.address); //Função que fará a leitura da struct interna de House.
}

void readHouseParcial(float area, int quartos, char bairro[20])
{
}
void readHouses(char op)
{ //Função de leitura de Arquivo binário
    int i;
    struct house _house;
    FILE *file = fopen(FILE_NAME, "rb"); //Abertura do Arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        if (op == 'L')
        { //Parâmetro para exibição de dados contendo sigla == L
            for (i = 0; i < countHouses(); i++)
            {
                fseek(file, i * sizeof(struct house), SEEK_SET);
                fread(&_house, sizeof(struct house), 1, file);
                if (_house.status.sigla == 'L') //Parâmetro para exibição de dados contendo sigla == L
                    stdReadHouse(_house);
            }
        }
        else
        { //Parâmetro para exibição de dados contendo sigla == A
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
    {
        bairro[j] = tolower(bairro[j]);
    }
    FILE *file = fopen(FILE_NAME, "rb"); //Abertura do Arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countHouses(); i++)
        {
            fseek(file, i * sizeof(struct house), SEEK_SET);
            fread(&_house, sizeof(struct house), 1, file);
            strcpy(bairroCasa, _house.address.bairro);
            for (j = 0; j < strlen(bairroCasa); j++)
            {
                bairroCasa[j] = tolower(bairroCasa[j]);
            }
            if ((strcmp(bairroCasa, bairro)) == 0)
            {
                stdReadHouse(_house);
                cont++;
            }
        }
    }
    fclose(file); //Fechamento do arquivo
    if (cont == 0)
    {
        printf("\nNao ha nenhuma casa no bairro %s\n", bairro);
    }
    system("pause");
    return;
}
void readHouseRoom(int quartos)
{
    int i, j, cont = 0;
    struct house _house;
    FILE *file = fopen(FILE_NAME, "rb"); //Abertura do Arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countHouses(); i++)
        {
            fseek(file, i * sizeof(struct house), SEEK_SET);
            fread(&_house, sizeof(struct house), 1, file);
            if (quartos == _house.quartos)
            {
                stdReadHouse(_house);
                cont++;
            }
        }
    }
    fclose(file); //Fechamento do arquivo
    if (cont == 0)
    {
        printf("\nNao ha nenhuma casa com %d quartos\n", quartos);
    }
    system("pause");
    return;
}
void readHouseArea(float area)
{
    int i, j, cont = 0;
    struct house _house;
    FILE *file = fopen(FILE_NAME, "rb"); //Abertura do Arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countHouses(); i++)
        {
            fseek(file, i * sizeof(struct house), SEEK_SET);
            fread(&_house, sizeof(struct house), 1, file);
            if (area == _house.area)
            {
                stdReadHouse(_house);
                cont++;
            }
        }
    }
    fclose(file); //Fechamento do arquivo
    if (cont == 0)
    {
        printf("\nNao ha nenhuma casa com %.2fm2\n", area);
    }
    system("pause");
    return;
}
// WRITE FUNCTIONS
int countHouses()
{ //Função para a contagem e retorno da quantidade de dados existente no arquivo referente a Houses
    long int cont = 0;
    FILE *fptr = NULL;
    if ((fptr = fopen(FILE_NAME, "rb")) == NULL)
    {                //Abertura do Arquivo
        return cont; //Caso ele não ache, o retorno será 0 pois o arquivo não existe ainda;
    }
    else
    {
        fseek(fptr, 0, 2);
        cont = ftell(fptr) / sizeof(struct house); //Retorno da quantidade dos dados
        fclose(fptr);                              //Fechamento do arquivo
        return cont;                               //Retorna a quantidade calculada de dados existentes.
    }
}

struct house stdWriteHouse()
{ //Função de cadastro básico da struct house
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

void writeHouse(struct house _house)
{ //Escrita dos dados armazenados na ROM para o arquivo house.bin
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL)
    {
        printf("\nErro ao abrir o arquivo!");
    }
    else
    {
        fwrite(&_house, sizeof(struct house), 1, file);
    }
    fclose(file);
}

int searchByRegister(int _register)
{
    struct house _house;
    FILE *file = fopen(FILE_NAME, "rb");
    int i;
    if (file == NULL)
    {
        printf("\nNenhuma casa registrada.");
        fclose(file);
        return -1;
    }
    for (i = 0; i < countHouses(); i++)
    {
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
    FILE *file = fopen(FILE_NAME, "rb");
    int i;
    if (file == NULL)
    {
        printf("\nNenhuma casa registrada.");
        fclose(file);
    }
    else
    {
        for (i = 0; i < countHouses(); i++)
        {
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

struct date inputDate()
{
    struct date _date;
    int day, month, year, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, flag = 0;
    do
    {
        flag = 0;
        printf("no formato DD/MM/YYYY: ");
        scanf("%d/%d/%d", &day, &month, &year);
        if (year < 1980 || year > 3000)
        {
            printf("\nAno incorreto.\nInforme a data ");
            flag = 1;
        }
        else
        {
            if (month < 1 || month > 12)
            {
                printf("\nMes incorreto.\nInforme a data ");
                flag = 1;
            }
            else
            {
                months[1] = (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) ? 29 : 28;
                if (day < 1 || day > months[month - 1])
                {
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

int countLocatario()
{
    long int count = 0;
    FILE *fptr = NULL;
    if ((fptr = fopen(FILE_LOCATAERIO, "rb")) == NULL)
    {                 //Abertura do Arquivo
        return count; //Caso ele não ache, o retorno será 0 pois o arquivo não existe ainda;
    }
    else
    {
        fseek(fptr, 0, 2);
        count = ftell(fptr) / sizeof(struct locatario); //Retorno da quantidade dos dados
        fclose(fptr);                                   //Fechamento do arquivo
        return count;                                   //Retorna a quantidade calculada de dados existentes.
    }
}

struct locatario stdReadLocatario()
{
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

void stdWriteLocatario(struct locatario _locatario)
{
    printf("\n----------Dados Locatario----------\n");
    printf("\nRegistro de Locatario: %d", _locatario.reg_loc);
    printf("\nNome: %s", _locatario.nome);
    printf("\nCPF: %s", _locatario.CPF);
    printf("\nRegistro de Imovel: %d", _locatario.reg_imov);
    printf("\nData inicial do contrato: %d/%d/%d", _locatario.inicio.day, _locatario.inicio.month, _locatario.inicio.year);
    printf("\nData final do contrato: %d/%d/%d\n", _locatario.termino.day, _locatario.termino.month, _locatario.termino.year);
}

void writeLocatario(struct locatario _locatario)
{ //Escrita dos dados armazenados na ROM para o arquivo locatario.bin
    _locatario.reg_loc = countLocatario();
    FILE *file = fopen(FILE_LOCATAERIO, "ab");
    if (file == NULL)
    {
        printf("\nErro ao abrir o arquivo!");
    }
    else
    {
        fwrite(&_locatario, sizeof(struct locatario), 1, file);
    }
    fclose(file);
}

void readLocatarios()
{ //Função geral de Leitura dos dados
    int i;
    struct locatario _locatario;
    FILE *file = fopen(FILE_LOCATAERIO, "rb"); //Abertura do arquivo para a leitura
    if (file == NULL)
    {
        printf("Nenhum locatario registrado.\n");
    }
    else
    {
        printf("\nCountLocatario: %d\n", countLocatario());
        for (i = 0; i < countLocatario(); i++)
        {
            fseek(file, i * sizeof(struct locatario), SEEK_SET);
            fread(&_locatario, sizeof(struct locatario), 1, file);
            stdWriteLocatario(_locatario);
        }
        fclose(file); //Fechamento do arquivo
    }
    system("pause");
}

void alterStatusHouse(int reg)
{
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
    if (_date2.year > _date1.year)
    {
        return 0;
    }
    else if (_date2.month > _date1.month)
    {
        return 0;
    }
    else if (_date2.day > _date1.day)
    {
        return 0;
    }
    return 1;
}

void endContract(struct locatario _locatario)
{
    struct date _date;
    stdReadLocatario(_locatario);
    printf("\nInforme a data atual: ");
    _date = inputDate();
    if (cmpDate(_date, _locatario.termino))
    {
        printf("\nMulta: Valor do aluguel");
    }
    //_locatario.CPF = "@";
}

int searchCPF_house(int reg)
{ //Função para busca dos dados que se encontram com o reg requerido
    int i, j;
    struct house _house;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countOwners(); i++)
        {
            fseek(file, i * sizeof(struct house), SEEK_SET);
            fread(&_house, sizeof(struct house), 1, file);
            //Comparação com o reg passado com o atual dado pelo read
            if (_house.reg_imov == reg)
            { //Parametro que limita a leitura dos dados.
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

struct locatario search_locatario(char cpf[15])
{
    int i, j, cmp;
    struct locatario _locatario;
    FILE *file = fopen(DIRECTORY, "rb"); //Abertura do arquivo para leitura
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        for (i = 0; i < countLocatario(); i++)
        {
            fseek(file, i * sizeof(struct locatario), SEEK_SET);
            fread(&_locatario, sizeof(struct locatario), 1, file);
            cmp = strcmp(_locatario.CPF, cpf); //Comparação com o cpf passado com o atual dado pelo read
            if (cmp == 0)
            { //Parametro que limita a leitura dos dados.
                fclose(file);
                stdWriteLocatarior(_locatario); //Leitura da struct achada
                return _locatario;
            }
        }
        fclose(file);
    }
    return;
    printf("\nNenhum proprietario encontrado com este cpf\n");
}
