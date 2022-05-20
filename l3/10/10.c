#include <stdio.h>

int ehLetra(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int ehLetraMaiuscula(char c) {
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int ehLetraMinuscula(char c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

char codifica(char letra, int n) {
	char letraCodificada = letra;
	int chaveReal = n;

	if (ehLetra(letra)) {
		if (ehLetraMinuscula(letra)) {
			chaveReal %= 26;
			chaveReal = letra - 'a' + chaveReal;
			chaveReal %= 26;
			letraCodificada = 'a' + chaveReal;
		} else {
			chaveReal *= 2;
			chaveReal %= 26;
			chaveReal = letra - 'A' + chaveReal;
			chaveReal %= 26;
			letraCodificada = 'A' + chaveReal;
		}
	
	}
	
	return letraCodificada;
}

char decodifica(char letra, int n) {
	char letraDecodificada =  letra;
	int chaveReal = n;

	if (ehLetra(letra)) {
		if (ehLetraMinuscula(letra)) {
			chaveReal %= 26;
			chaveReal = 'z' - letra + chaveReal;
			chaveReal %= 26;
			letraDecodificada = 'z' - chaveReal;
		} else {
			chaveReal *= 2;
			chaveReal %= 26;
			chaveReal = 'Z' - letra + chaveReal;
			chaveReal %= 26;
			letraDecodificada = 'Z' - chaveReal;
		}
	}

	return letraDecodificada;
}

int main() {
	int chave = 0, opt = 0;
	char letra = '\0';
	scanf("%d %d ", &opt, &chave);

	while (letra != '.') {
		scanf("%c", &letra);
		if (opt == 1) letra = codifica(letra, chave);
		else if (opt == 2) letra = decodifica(letra, chave);
		else {
			printf("Operacao invalida.");
			break;
		}

		printf("%c", letra);
	}
	return 0;
}
