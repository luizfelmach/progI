#include <stdio.h>


int ehPrimo(int num){
	int i, div = 0;
	for (i = 1; i <= num; i++) {
		if (num % i == 0) div++;
	}
	return div == 2;
}


int main() {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int i;
	for (i = n + 1; i < m; i++) {
		if (ehPrimo(i)) printf("%d ", i);
	}
	return 0;

} 
