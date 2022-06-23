#include <stdio.h>

void troca(int *vetor, int i, int j) {
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int main() {
	int n;
	scanf("%d", &n);
	int notas[n];

	int iguais = 1, cre = 1, dec = 1;

	int i, j;
	for (i = 0; i < n; i++)
		scanf("%d", &notas[i]);

	int prev = notas[0];
	int primeiraNota = notas[0];

	for (i = 1; i < n; i++) {
		if (notas[i] != primeiraNota)
			iguais = 0;
		if (notas[i] > prev)
			dec = 0;
		if (notas[i] < prev)
			cre = 0;

		prev =  notas[i];
	}

	if (iguais)
		printf("CRESCENTE&DECRESCENTE");
	else if (cre)
		printf("CRESCENTE");
	else if (dec)
		printf("DECRESCENTE");
	else
		printf("DESORDENADO");

	return 0;
}
