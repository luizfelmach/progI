#include <stdio.h>

int ehFinalDaLista(int v) {
	return v == -1;
}

int encontraMaiorBuraco() {
	int maiorBuraco = 0;
	int num = 0;
	while (1) {
		scanf("%d", &num);
		if (!ehFinalDaLista(num)) {
			if (num > maiorBuraco) maiorBuraco = num;
		} else break;
	}
	return maiorBuraco;
}

int contaEsferasGrandes(int maiorBuraco) {
	int cont = 0;
	int num = 0;

	while (1) {
		scanf("%d", &num);
		if (!ehFinalDaLista(num)) {
			if (num >= maiorBuraco) cont++;
		} else break;
	}
	return cont;
}

int main() {
	int maiorBuraco = encontraMaiorBuraco();
	int qtdQueNaoPassou = contaEsferasGrandes(maiorBuraco);
	printf("QTD:%d\n", qtdQueNaoPassou);
	return 0;
}
