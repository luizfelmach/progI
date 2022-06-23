#include <stdio.h>

#define TODOS 2
#define PARCIAL 1
#define NENHUM 0

int achaValor(int *vetor, int tam, int x) {
	int i;
	for (i = 0; i < tam; i++) {
		if (vetor[i] == x) {
			return 1;
		}
	}

	return 0;
}

int main() {
	int n1, n2;
	int i;

	scanf("%d", &n1);
	int num1[n1];
	for (i = 0; i < n1; i++)
		scanf("%d", &num1[i]);

	scanf("%d", &n2);
	int num2[n2];
	for (i = 0; i < n2; i++)
		scanf("%d", &num2[i]);

	int cont = 0;
	for (i = 0; i < n1; i++) {
		if(achaValor(num2, n2, num1[i])) {
			cont++;
		}
	}

	if (cont == n1)
		printf("TODOS");
	else if (cont == 0)
		printf("NENHUM");
	else 
		printf("PARCIAL");
	return 0;
}
