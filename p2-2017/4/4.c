#include <stdio.h>

int letras = 0;
int vogais = 0;
int consoantes = 0;

int ehLetra(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int ehVogal(char c) {
	int vogalMa = c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	int vogalMi = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';

	return vogalMa || vogalMi;
}

int reconheceSimbolo(char c) {
	int simb;
	char fim;
	if (c != '*') return 0;
	if (c == '*') {
		scanf("%d", &simb);
		scanf("%c", &fim);
		if (fim != '*') {
			scanf("%*[^*]");
			scanf("%*c");
			return -1;
		}
		if (simb >= 1 && simb <= 3) return simb;
		else return -1;
	}
	return -1;
}

int main() {
	char c = '\0';
	int rec = 0;

	while (c != '.') {
		scanf("%c", &c);
		rec = reconheceSimbolo(c);

		if (rec == -1) {
			printf("*ERRO*");
		
		} else if (rec == 0) {
			if (ehLetra(c)) {
				printf("%c", c);
				letras++;
				if (ehVogal(c)) vogais++;
				else consoantes++;
			}

		} else {

			if (rec == 1) {
				printf("*L:%d V:%d C:%d*", letras, vogais, consoantes);
				letras = 0;
				vogais = 0;
				consoantes = 0;
			} else if (rec == 2) {
				printf("*V:%d*", vogais);
				vogais = 0;
			} else {
				printf("*C:%d*", consoantes);
				consoantes = 0;
			}
		
		}
		
	}
	printf(".");
	return 0;
}
