#include <stdio.h>

int main() {
	int custo = 0;

	int n1, n2, n3;
	int qtd;
	scanf("%d %d %d\n", &n1, &n2, &n3);
	scanf("%d\n", &qtd);

	int i, num;
	for (i = 0; i < qtd; i++) {
		scanf("%d", &num);
		if (num == 1) custo += n1;
		if (num == 2) custo += n2;
		if (num == 3) custo += n3;
	}

	printf("CUSTO:%d\n", custo);
	return 0;
}
