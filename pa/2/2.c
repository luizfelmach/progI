#include <stdio.h>

int main() {
	int t, m;
	scanf("%d %d", &t, &m);

	int dia, und;
	int i;

	for (dia = t, und = m - t;dia <= m; dia+=2, und-=2) {
		for (i = 0; i < und/2; i++) {
			printf("_");
		}
		for (i = 0; i < dia; i++) {
			printf("$");
		}
		for (i = 0; i < und/2; i++) {
			printf("_");
		}
		printf("\n");
	}

	for (dia = m -2, und = 2;dia >= 1; dia-=2, und+=2) {
		for (i = 0; i < und/2; i++) {
			printf("_");
		}
		for (i = 0; i < dia; i++) {
			printf("$");
		}
		for (i = 0; i < und/2; i++) {
			printf("_");
		}
		printf("\n");
	}
	return 0;
}
