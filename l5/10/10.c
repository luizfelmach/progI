#include <stdio.h>

void ordenaCrescente(int* vet, int tam) {
	int i, j, aux;
	for (i = 0; i < tam -1; i++) {
		for (j = 0; j < tam -1; j++) {
			if (vet[j] > vet[j+1]) {
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
		}
	}
}

void imprimeDadosVetor(int* vet, int tam) {
	int i;
	printf("{");
	for (i = 0; i < tam; i++) {
		printf("%d", vet[i]);
		if (i < tam  - 1) printf(", ");
	}
	printf("}");

}

int main() {
	int n;
	scanf("%d", &n);
	int vetor[n];
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &vetor[i]);

	ordenaCrescente(vetor, n);
	imprimeDadosVetor(vetor, n);
	return 0;
}
