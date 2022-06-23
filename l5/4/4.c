#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int num[n];

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	
	int a, b;
	scanf("%d %d", &a, &b);

	int total = 0;

	for (i = 0; i < n; i++) {
		if (num[i] >= a && num[i] <= b)
			total++;
	}

	printf("%d %d", total, n-total);
	

	return 0;
}
