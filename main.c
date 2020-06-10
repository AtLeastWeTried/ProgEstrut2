#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define FILE_NAME "imovel.bin"

void writeTest(struct test _test);
struct test {
	char name[30];
};

int main() {

}

void writeTest(struct test _test) {
	FILE *file = fopen(FILE_NAME, "ab");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		fwrite(&_test, sizeof(struct test), 1, file);
	}
}

void readAllTest() {
	FILE *file = fopen(FILE_NAME, "rb");
	if (file == NULL) {
		printf("\nErro ao abrir o arquivo.");
	}
	else {
		
	}
}