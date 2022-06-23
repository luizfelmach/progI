#include <stdio.h>

int ehIgual(int a, int b) {
	return a == b;
}

int maiorDigito(int n) {
	int maior = 0;
	int dig;
	while (n > 0) {
		dig = n % 10;
		if (dig > maior) maior = dig;
		n /= 10;
	}
	return maior;
}

int main() {
	int ma, mb;
	int a, b;
	int cont = 0;
	while (scanf("(%d,%d)", &a, &b) == 2) {
		ma = maiorDigito(a);
		mb = maiorDigito(b);
		if (ehIgual(ma, mb)) cont++;
	}

	printf("COUNT:%d", cont);
	return 0;
}
