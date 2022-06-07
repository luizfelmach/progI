#include <stdio.h>

int ehPar(int n) {
	return !(n % 2);
}

int main() {
	int qtd;
	scanf("%d", &qtd);

	int qtdNums = 0;

	int num;
	int chave = 0;

	int i;
	for (i = 0; i < qtd; i++) {
		scanf("%d", &num);
		if (i == 0) {
			if (ehPar(num)) {
				chave = 0;
				qtdNums++;
				continue;
			} else {
				chave = 1;
				qtdNums++;
				continue;
			}
		}

		if (chave == 0 && ehPar(num)) qtdNums++;
		else if (chave == 1 && !ehPar(num)) qtdNums++;
	}

	if (chave == 0)
		printf("QTD PARES:%d", qtdNums);
	else if (chave == 1)
		printf("QTD IMPARES:%d", qtdNums);

	return 0;
}
