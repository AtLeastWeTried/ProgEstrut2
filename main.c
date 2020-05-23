#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "models/owner/owner.c"
#include "models/house/house.c"

int main() {
    int op;
    char cpf[15], parametro;
    do {
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Consulta total Owners\n[3] Consulta parcial Owners\n");
        printf("[4] Consulta total Houses\n[5] Consulta parcial Houses\n [6]Sair\nOpcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
                system("cls");
                struct owner _owner = stdWriteOwner();
                writeOwner(_owner);
                break;
            case 2: 
                system("cls"); 
                readOwners(); 
                break;
            case 3: 
                system("cls");
                printf("Informe o CPF: ");
                fflush(stdin);
                gets(cpf);
                searchByCPF(cpf);
                system("pause");
                break;
            case 4: 
                system("cls"); 
                printf("\nParametro da pesquisa [L]livre ou [O]ocupado:");
                do{    
                    scanf("%c", &parametro);
                }while(parametro != 'L' && parametro != 'O');
                fflush(stdin);
                readHouses(parametro); 
                break;
            case 5: 
                system("cls");

                break;
            case 6: printf("Fim do programa"); break;
            default: printf("Opcao nao existente"); break;
        }
    } while (op != 6);
}