#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "models/owner/owner.c"
#include "models/house/house.c"
#include "models/house/WriteHouse.c"

int main() {
    //struct house _house;
    //stdWriteHouse(_house);
    //stdReadHouse(_house);
    
    
    
    
    
    /*int op;
    char cpf[15], parametro, opc;
    do {
        fflush(stdin);
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Consulta Owners\n");
        printf("[3] Consulta Casas\n[4] Sair\nOpcao: ");
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
    } while (op != 4);*/
}