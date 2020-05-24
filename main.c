#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./models/owner/owner.c"
#include "./models/house/house.c"

int main() {
    int op;
    char cpf[15], parametro, opc;
    do {
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Consulta Owners\n");
        printf("[3] Consulta total Houses\n[4] Sair\nOpcao: ");
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
                    scanf("%c", &parametro);
                } while(parametro == 'L' && parametro == 'O' || parametro == 'l' && parametro == 'o');
                fflush(stdin);
                //readHouses(parametro); 
                break;
            case 4: printf("Fim do programa"); break;
            default: printf("Opcao nao existente"); break;
        }
    } while (op != 4);
}