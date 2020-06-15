#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

int testMenu();

int main() {
	printf("\noption: %d", testMenu());
}

int testMenu() {
	int index;
	static int option = 0;
	char caracter, messages[][80] = { 
		"first option!", 
		"second option!" 
	};
	do {
		system("CLS");
		for (index = 0; index < 2; index++) {
			if (option == index) {
				printf("\n> %s", messages[index]);
			}
			else {
				printf("\n%s", messages[index]);
			}
		}
		caracter = getch();
		if (caracter == 72 && option == 1) {
			option = 0;
		}
		else if (caracter == 80 && option == 0) {
			option = 1;
		}
	}while (caracter != 13);
	return option;
}