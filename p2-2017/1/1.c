#include <stdio.h>

int main() {
	int qtd;
	int pos = 0;
	int menor = 0;
	scanf("%d", &qtd);

	int cur;
	int i;
	for (i = 1; i <= qtd; i++) {
		scanf("%d", &cur);
		if (i == 1) {
			menor = cur;
			pos = i;
		}

		if (cur < menor) {
			menor = cur;
			pos = i;
		}
	}


	if (pos == 0) return 0;
	printf("POS:%d", pos);
	return 0;
}
