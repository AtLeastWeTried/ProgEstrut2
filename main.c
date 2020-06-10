#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

#define FILE_NAME "imovel.bin"

struct test {
	char name[30];
};

void readAllTest();
void writeTest(struct test _test);

int main() {
	int operador;
	struct test _test;
	do {
		printf("[1] Cadastrar\n");
		printf("[2] Consultar\n");
		printf("Operador: ");
		scanf("%d", &operador);
		switch (operador)
		{
			case 1:
				printf("\nInforme um nome: ");
				fflush(stdin);
				gets(_test.name);
				writeTest(_test);
				break;
			case 2:
				readAllTest();
				break;
			default:
				printf("\nOpcao errada!");
				break;
		}
	} while(operador != 0);
}

void writeTest(struct test _test) {
	FILE *file = fopen(FILE_NAME, "ab");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		fwrite(&_test, sizeof(struct test), 1, file);
	}
	fclose(file);
}

void readAllTest() {
	struct test _test;
	FILE *file = fopen(FILE_NAME, "rb");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		do {
			
		} while (feof(file) != 0);
	}
	fclose(file);
}