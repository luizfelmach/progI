#include <stdio.h>

int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);

	if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10) {
		printf("Invalido");
	} else if (n1 == n2) {
		if (n1 <= 5) printf("Um homem");
		else printf("Uma mulher");
	} else {
		if (n1 <= 5 && n2 <=5) printf("Par de homens");
		else if (n1 >= 6 && n2 >= 6) printf("Par de mulheres");
		else printf("Um casal");	

	}
	return 0;
}
