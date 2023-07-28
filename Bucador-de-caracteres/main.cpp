

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//Sección de variables y constantes
FILE* Arch; //Variable de tipo archivo
char c;

int cAlf = 0, cNum = 0, cEsp = 0, cMay = 0, cMin = 0;

//Selección prototipos

bool EsEspacio(char c) {

	return (c == 32);
}

bool EsNumero(char c) {

	return (c >= 48 && c >= 57);
}

bool EsMayuscula(char c) {

	return (c >= 65 && c <= 90);
}

bool EsMinuscula(char c) {

	return (c >= 97 && c <= 122);
}

bool EsAlfabetico(char c) {

	return(EsMayuscula(c) || EsMinuscula(c));
}

int main() {

	Arch = fopen("Hola.txt", "r");

	if (Arch != NULL) {

		while (feof(Arch) == 0) {

			c = fgetc(Arch); //Se obtiene caracter fileGetChar
			printf("%c", c);

			//contadores de caracteres
			if (EsEspacio(c)) cEsp++;
			if (EsNumero(c)) cNum++;
			if (EsMayuscula(c)) cMay++;
			if (EsMinuscula(c)) cMin++;
			if (EsAlfabetico(c)) cAlf++;
		}

		//Salida de resultados de los conteos

		cout << endl << endl;
		cout << "Total espacios de en blanco: " << cEsp << endl;
		cout << "Total numeros: " << cNum << endl;
		cout << "Total mayusculas: " << cMay << endl;
		cout << "Total minusculas: " << cMin << endl;
		cout << "Total caracteres alfabeticos: " << cAlf << endl;
	}

	fclose(Arch);

	return 0;
}
