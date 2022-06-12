#include <stdio.h>

int ehDigito(char c) {
	return c >= '0' && c <= '9';
}

int ehLetra(char c) {
	int ma = c >= 'a' && c <= 'z';
	int mi = c >= 'A' && c <= 'Z';
	return ma || mi;
}

int main() {
	char c1, c2, c3, c4,
	     c5, c6, c7, c8;
	scanf("%c%c%c%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8);

	int haProblemaLetras = 0;
	int haProblemaDigitos = 0;
	if (!ehLetra(c1) || !ehLetra(c2) || !ehLetra(c3)) {
		haProblemaLetras++;
	}
	if (!ehDigito(c5) || !ehDigito(c6) ||!ehDigito(c7)||!ehDigito(c8) ) {
	
		haProblemaDigitos++;
	}

	if (haProblemaLetras && haProblemaDigitos) printf("Codigo invalido!Problema nas letras e nos numeros!");
	else if (haProblemaLetras) printf("Codigo invalido!Problema nas letras!");
	else if (haProblemaDigitos) printf("Codigo invalido!Problema nos numeros!");
	else if (!haProblemaLetras && !haProblemaDigitos) printf("Codigo valido!");
	return 0;
}
