#include <stdio.h>

int main() {
	int n1, n2, n3;
	int alg[3] =  {-1, -1, -1};
	scanf("%d %d %d", &n1, &n2, &n3);
	int menor = 1000000;
	n1 /= 100;
	n2 /= 100;
	n3 /= 100;

	if (n1 > 0) alg[0] = n1 % 10;
	if (n2 > 0) alg[1] =  n2 % 10;
	if (n3 > 0) alg[2] =  n3 % 10;

	if (alg[0] == -1 && alg[1] == -1 && alg[2] == -1) {
		printf("Nenhum");
		return 0;
	}
	int i;
	for (i = 0; i < 3; i++) {
		if (alg[i] < menor && alg[i] != -1)
			menor =  alg[i];
	}

	for (i = 0; i < 3; i++) {
		if (alg[i] == menor && alg[i] != -1) {
			printf("N%d", i+1);
			break;
		}
	}
	return 0;
}
