#include <stdio.h>

int ehPrimo(int num) {
	int i, div = 0;
	for (i = 1; i <= num; i++) {
		if (num % i == 0) div++;
	}
	return div == 2;
}

int imprimeMultiplos (int num, int max) {
	int i, cont = 0;
	for (i = num + 1; i < max; i++) {
		if (i % num == 0){
			printf("%d ", i);
			cont++;
		}
	}
	if (cont == 0) {
		printf("*\n");
	} else printf("\n");

}

int main() {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int i;
	for (i = n + 1; i < m; i++) {
		if (ehPrimo(i)) {
			printf("%d\n", i);
			imprimeMultiplos(i, m);
		}
	}

	return 0;
}
