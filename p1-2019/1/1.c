#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int res = 0; // 0 -> Crescente 1 -> Descrescente 2 -> TD
	if (a < b && b < c) printf("CRESCENTE");
	else if (a > b && b > c) printf("DECRESCENTE");
	else printf("TUDO DOIDO");
	return 0;
}
