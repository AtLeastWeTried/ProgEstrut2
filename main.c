#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "models/owner/owner.c"

int main() {
    int op;
    char cpf[15];
    do {
        system("cls");
        printf("[1] Cadastro de proprietario\n[2] Consulta total\n[3] Consulta parcial\n[4] Sair\nOpcao: ");
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
            case 4: printf("Fim do programa"); break;
            default: printf("Opcao nao existente"); break;
        }
    } while (op != 4);
}