#include <stdio.h>

int ehPar(int x) {
	return x % 2 == 0;
}

void printaPares(int N) {
	int i, j;
	for (i = 0, j = 2; i < N; j++) {
		if (ehPar(j)) {
			printf("%d ", j);
			i++;
		}
	}
}

void printaImpares(int N) {
	int i, j;
	for (i = 0, j = 1; i < N; j++) {
		if (!ehPar(j)) {
			printf("%d ", j);
			i++;
		}
	}
}

int main() {
	int opt = 0, n = 0;
	scanf("%d %d", &opt, &n);

	if (opt == 0) printaPares(n);
	else printaImpares(n);

	return 0;
}
