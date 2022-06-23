#include <stdio.h>

int pos(int x) {
	if (x < 0) return x * -1;
	return x;
}

void printaPontos(int a, int b) {
	printf(" (%d %d)", a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	int postes[n];
	int alturas[n-1];

	int i, j;
	for (i = 0; i < n; i++)
		scanf("%d", &postes[i]);

	int maiorAltura = -100;

	for (i = 0; i < n - 1; i++) {
		alturas[i] = pos(postes[i+1] - postes[i]);
		if (alturas[i] > maiorAltura)
			maiorAltura = alturas[i];
	}
	
	if (maiorAltura == -100) {
		printf("IMPOSSIVEL");
		return 0;
	}


	for (i = 0; i < n - 1; i++) {
		if (alturas[i] == maiorAltura)
			printaPontos(i, i+1);
	}

	return 0;
}
