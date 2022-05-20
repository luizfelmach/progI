#include <stdio.h>

int verificaNegativo(int n) {
	return n < 0;
}

int verificaPrimo(int n) {
	int i, div = 0;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) div++;
	} 
	return div == 2; 

}

int transformaPrimo(int n) {
	int primo = n;
	if (verificaNegativo(primo)) {
		primo *=  -1;
		while (1) {
			if(verificaPrimo(primo)) {
				primo *= -1;
				if (primo >= -32000 && primo <= 32000)
					return primo;
				else return n;
			}
			primo++;
		
		}
	} else {
		while (1) {
			if(verificaPrimo(primo)) {
				if (primo >= -32000 && primo <= 32000)
					return primo;
				else return n;
			}
			primo++;
		
		}
	}
	return 0;
}

int main() {
	int l = 0, c = 0, valor = 0;
	scanf("%d %d", &l, &c);
	int i, j;
	for (i = 0; i < l; i++) {
		printf("	");
		for (j = 0; j < c; j++) {
			scanf("%d", &valor);
			printf("%d ", transformaPrimo(valor));
		}
		printf("\n");
	}

	return 0;
}
