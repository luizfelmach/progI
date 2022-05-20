#include <stdio.h>

int letraMinuscula(char c) {
	return c >= 'a' && c <= 'z';
}

int letraMaiuscula(char c) {
	return c >= 'A' && c <= 'Z';
}

int calculaValorPalavra() {
	int valor = 0;
	char letra =  '\0';
	while (letra != '\n') {
		if (scanf("%c", &letra) == 1) {
			if (letraMinuscula(letra))
				valor += letra - 'a' + 1;
			else if (letraMaiuscula(letra))
				valor += letra - 'A' + 27;
		} else break;

	}
	return valor;
}

int ehPrimo(int n) {
        int div = 0;

        int i;
        for (i = 1; i <= n; i++) {
                if (n % i == 0) div++;
        }

        return div == 2;
}

int proximoPrimo(int n) {
	int primo = n + 1;
	while (1) {
		if (ehPrimo(primo))
			return primo;
		primo++;
	}
	return -1;
}

int main() {
	int n = 1;
	while (n) {
		n =  calculaValorPalavra();
		if (n == 0) break;
		if (ehPrimo(n))
			printf("E primo\n");
		else {
			printf("Nao e primo %d\n", proximoPrimo(n));
		}

	}
	return 0;
}
