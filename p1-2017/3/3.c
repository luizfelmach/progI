#include <stdio.h>

int ehMai(char c) {
	int ehMai = (c >= 'A' && c <= 'Z');
	return ehMai;
} 

int ehLetra(char c) {
	int ehMin = (c >= 'a' &&  c <= 'z');
	return ehMin || ehMai(c);
}

int ehChar(char c) {
	int ehNum = (c >= '0' && c <= '9');
	return ehLetra(c) || ehNum;
}

char minus(char c) {
	if (ehMai(c)) {
		return 'a' + c - 'A';
	}
	return c;
}



int main() {
	char c1, c2, c3, c4;
	scanf("%c%c %c%c", &c1, &c2, &c3, &c4);

	if (!ehChar(c1) || !ehChar(c2) || !ehChar(c3) || !ehChar(c4)) {
		printf("Invalido");
		return 0;
	}

	if (minus(c1) == minus(c3) && minus(c2) ==minus(c4)) {
		printf("IGUAIS");
	} else printf("DIFERENTES");



	return 0;
}
