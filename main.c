#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#define FILE_NAME "imovel.bin"

struct test {
	char name[30];
};

void test();
int countTest();
void readAllTest();
void writeTest(struct test _test);
void alterTest(char newName[30], int pos);

int main() {
	char newName[30];
	int operador, pos;
	struct test _test;
	do {
		getch();
		system("CLS");
		printf("[1] Cadastrar\n");
		printf("[2] Consultar\n");
		printf("[3] Alterar\n");
		printf("Operador: ");
		scanf("%d", &operador);
		switch (operador) {
			case 1:
				printf("\nInforme um nome: ");
				fflush(stdin);
				gets(_test.name);
				writeTest(_test);
				break;
			case 2:
				readAllTest();
				break;
			case 3:
				readAllTest();
				printf("\nRegistro: ");
				scanf("%d", &pos);
				printf("\nQual o novo nome: ");
				fflush(stdin);
				gets(newName);
				alterTest(newName, pos);
				readAllTest();
				break;
			case 4: 
				readAllTest();
				test(1);
				break;
			default:
				printf("\nOpcao errada!");
				break;
		}
	} while(operador != 0);
}

// wb = sobrepoe
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

int countTest() {
	long int count = 0;
	FILE *fptr = NULL;
	if ((fptr = fopen(FILE_NAME, "rb")) == NULL) {                
		return count; 
	}
	else {
		fseek(fptr, 0, 2);
		count = ftell(fptr) / sizeof(struct test); 
		fclose(fptr);                                   
		return count;                                   
	}
}

void readAllTest() {
	int loop, index;
	struct test _test;
	FILE *file = fopen(FILE_NAME, "r");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		loop = countTest();
		for (index = 0; index < loop; index++) {
			fseek(file, index*sizeof(struct test), SEEK_SET);
			fread(&_test, sizeof(struct test), 1, file);
			printf("\n[%d]: Nome: %s", index, _test.name);
		}
		printf("\n\n");
	}
	fclose(file);
}

void alterTest(char newName[30], int pos) {
	int loop, index;
	struct test *_test = NULL, current;
	FILE *file = fopen(FILE_NAME, "rb");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		loop = countTest();
		_test = malloc(loop*sizeof(struct test));
		for (index = 0; index < loop; index++) {
			fseek(file, index*sizeof(struct test), SEEK_SET);
			fread(&current, sizeof(struct test), 1, file);
			strcpy((_test + index)->name, current.name);
		}
		fclose(file);
		strcpy((_test + pos)->name, newName);
		file = fopen(FILE_NAME, "wb");
		fwrite(_test, sizeof(struct test), loop, file);
	}
	fclose(file);
}

void test(int pos) {
	int loop, index;
	struct test *_test = NULL, current;
	FILE *file = fopen(FILE_NAME, "rb");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		loop = countTest();
		_test = malloc(loop*sizeof(struct test));
		for (index = 0; index < loop; index++) {
			fseek(file, index*sizeof(struct test), SEEK_SET);
			fread(&current, sizeof(struct test), 1, file);
			strcpy((_test + index)->name, current.name);
		}
		fclose(file);
		strcpy((_test + pos)->name, "test");
		file = fopen(FILE_NAME, "wb");
		fwrite(_test, sizeof(struct test), loop, file);
	}
	fclose(file);
}