#include <stdio.h>

void printaMatriz(int *vet, int c) {
	int i;
	for (i = 0; i < c; i++) {
		printf("%d", vet[i]);
		if (i < c -1) printf(" ");
	}
}

int main() {
	int qtd;
	scanf("%d", &qtd);

	int c1, l1;
	int c2, l2;
	int i, j, k;
	int soma = 0;
	while (qtd--) {
		scanf("%d %d", &c1, &l1);
		int vet1[l1][c1];
		for (i = 0; i < l1; i++) {
			for(j = 0; j < c1; j++) {
				scanf("%d", &vet1[i][j]);
			}
		}

		scanf("%d %d", &c2, &l2);
		int vet2[l2][c2];
		for (i = 0; i < l2; i++) {
			for(j = 0; j < c2; j++) {
				scanf("%d", &vet2[i][j]);
			}
		}

		if (c1 != l2) {
			printf("IMPOSSIVEL\n\n");
			continue;
		}

		int vetRes[l1][c2];

		for (i = 0; i < l1; i++) {
			for (j = 0; j < c2; j++) {
				soma = 0;
				for (k = 0; k < l2; k++) {
			soma += vet1[i][k]*vet2[k][j];
				}
				vetRes[i][j] = soma;
			}
		}

		for (i = 0; i < l1; i++) {
			printaMatriz(vetRes[i], c2);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
