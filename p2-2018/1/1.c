#include <stdio.h>

int main() {
	int qtd; scanf("%d", &qtd);

	int num;
	int soma = 0;
	int i;
	for (i = 0; i < qtd; i++) {
		scanf("%d", &num);
		if (num  % 2 == 0 && i % 2 == 0) soma += num;
		if (num  % 2 == 1 && i % 2 == 1) soma += num;
	}
	printf("SOMA:%d", soma);
	return 0;
}
