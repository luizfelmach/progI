#include <stdio.h>

int main() {
	int n1, n2;
	int tot1 = 0, tot2 = 0;

	scanf("%d %d", &n1, &n2);

	while (n1 > 0 & n2 > 0) {
		if (n1) {
			if (n1 - 5 >= 0) {
				tot1++;
				n1 -=5;
			} else {
				tot1++;
				n1 -=1;
			}
		}

		if (n2) {
			if (n2 - 5 >= 0) {
			
				tot2++;
				n2 -= 5;
			} else {
			
				tot2++;
				n2 -= 1;
			}
		}

	}


	if (n1 > n2) {
		printf("QTD troco 1 eh maior!");
	} else if (n2 > n1) {
		printf("QTD troco 2 eh maior!");
	} else {
		printf("Iguais!");
	}

	return 0;
}
