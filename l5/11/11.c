#include <stdio.h>

int ordena(int* vet, int tam) {
	int i, j;
	int cur, next;
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam -1; j++) {
			cur = vet[j];
			next = vet[j+1];
			if (cur > next) {
				vet[j] = next;
				vet[j+1] = cur;
			}
		}
	}
}

int main() {
	int i;
	int n1, n2;
	scanf("%d", &n1);
	int a[n1];
	for (i = 0; i < n1; i++)
		scanf("%d", &a[i]);

	scanf("%d", &n2);
	int b[n2];
	for (i = 0; i < n2; i++)
		scanf("%d", &b[i]);

	ordena(a, n1);
	ordena(b, n2);


	int x = 0, y = 0;
	int p1, p2;
	while (x < n1 || y < n2) {
		p1 = a[x];
		p2 = b[y];
		
		if (x >= n1) p1 = 1000000000;
		if (y >= n2) p2 = 1000000000;

		if (p1 <= p2) {
			printf("A");
			x++;
		} else {
			printf("B");
			y++;
		}
	}

	return 0;
}
