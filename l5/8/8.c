#include <stdio.h>

void trocaParEImpar(int* vet, int tam) {
	int i, aux;
	for (i = 0; i < tam -1; i+=2) {
		aux = vet[i];
		vet[i] = vet[i+1];
		vet[i+1] = aux;
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

	trocaParEImpar(vetor, n);
	imprimeDadosVetor(vetor, n);
	return 0;
}
