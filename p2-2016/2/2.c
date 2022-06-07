#include <stdio.h>

int soma = 0;

int ehPrimo(int n) {
	int divs = 0;

	int i;
	for ( i = 1; i <= n; i++) {
		if (n % i == 0) divs++;
	}

	return divs == 2;
}

int maiorDigitoPrimo(int n) {
	int num = n;
	int digito = 0;
	int maiorDigito = 0;

	while (num > 0) {
		digito = num % 10;

		if (ehPrimo(digito)) {
			if (digito > maiorDigito) maiorDigito = digito;
		}

		num /= 10;
	}

	return maiorDigito;
}

int main() {
	int num = 0;

	while (scanf("%d", &num) == 1) {
		soma += maiorDigitoPrimo(num);
	}

	printf("SOMA:%d", soma);
	return 0;
}
