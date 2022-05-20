#include <stdio.h>

int somadosdigitos(int n) {
	int soma = 0;

	while (n > 0) {
		soma += n % 10;
		n /= 10;
	}
	return soma;
}

void parImpar(int n) {
	if (n % 2 == 0)
		printf("Par");
	else printf("Impar");
}

int ehPrimo(int n) {
	int div = 0;

	int i;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) div++;
	}

	return div == 2;
}

void valorPrimo(int n) {
	if (ehPrimo(n))
		printf("Primo");
	else printf("Nao e primo");
}

int main() {
	int n = 0;
	scanf("%d", &n);
	do {
		n =  somadosdigitos(n);
		printf("%d ", n);
		parImpar(n);
		printf(" ");
		valorPrimo(n);
		printf("\n");
	} while (n >= 10);
	return 0;
}
