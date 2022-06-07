#include <stdio.h>

int main() {
	int h1, m1, s1;
	int h2, m2, s2;
	int tot1 = 0;
	int tot2 = 0;
	int soma = 0;

	scanf("%d %d %d", &h1, &m1, &s1);
	scanf("%d %d %d", &h2, &m2, &s2);

	tot1 = h1*3600 + m1*60 + s1;
	tot2 = h2*3600 + m2*60 + s2;

	if (tot1 > tot2) {
		soma = h1 + m1 + s1;
	} else if (tot2 > tot1) {
		soma = h2 + m2 + s2;
	} else {
		printf("IGUAIS");
		return 0;
	}

	soma /= 10;
	printf("RESP:%d", soma % 10);
	return 0;
}
