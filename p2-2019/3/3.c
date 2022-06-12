#include <stdio.h>

int ehDigito(char c) {
	return c >= '0' && c <= '9';
}

int charParaInteiro(char c) {
	return c - '0';
}

void imprimePorExtenso(int d) {
	if (d == 0) printf("zero");
	if (d == 1) printf("um");
	if (d == 2) printf("dois");
	if (d == 3) printf("tres");
	if (d == 4) printf("quatro");
	if (d == 5) printf("cinco");
	if (d == 6) printf("seis");
	if (d == 7) printf("sete");
	if (d == 8) printf("oito");
	if (d == 9) printf("nove");
}

char leDigito(char d) {
	int cont = 0;
	char c;
	while (1) {
		scanf("%c", &c);
		if (ehDigito(c)) {
			if (cont == 0) printf("%c", d);
			printf("%c", c);
			cont++;
		} else {
			if (cont == 0) imprimePorExtenso(charParaInteiro(d));
			return c;
		}
	}
}

int main() {
	char terminador;
	char c = '\0';
	int k;
	scanf("%c ", &terminador);
	while (1) {
		scanf("%c", &c);
		if (c == terminador) break;
		if (ehDigito(c)){
			c = leDigito(c);
			if (c == terminador) break;
			printf("%c", c);
		} else {
			printf("%c", c);
		}
	}
	return 0;
}

