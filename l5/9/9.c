#include <stdio.h>

void inverteVetor(int* vet, int tam) {
	int i, f, aux;
	for (i = 0, f = tam -1; i < tam/2; i++, f--) {
		aux = vet[i];
		vet[i] = vet[f];
		vet[f] = aux;
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

	inverteVetor(vetor, n);
	imprimeDadosVetor(vetor, n);
	return 0;
}
