#include <stdio.h>

int qtdDebitoPlaca(int presc) {
	int res = 0;
	int deb, p;
	char c = '\0';
	while (c != '\n') {
		scanf("%c", &c);
		if (c == '(') {
			scanf("%d:%d)", &deb, &p);
			if (p <= presc) res += deb;
		}
	}
	return res;
}

int main() {
	int qtd;
	scanf("%d", &qtd);
	int soma = 0;
	int debito = 0;
	int presc;
	char p1 = '\0', p2 = '\0', p3 = '\0';

	int mDebito = 0;
	char mp1, mp2, mp3;


	int i;
	for(i = 0; i <qtd; i++) {
		
		while (1) {
			scanf("%d\n", &presc);
			scanf("%c%c%c", &p1, &p2, &p3);

			if (p1 == 'F' && p2 == 'I' && p3 == 'M') break;

			debito = qtdDebitoPlaca(presc);
			if (debito > mDebito) {
				mDebito = debito;
				mp1 = p1;
				mp2 = p2;
				mp3 = p3;
			}
		}

		
		soma += mDebito;
		if (mDebito == 0) {
			printf("SEM DEBITO!\n");
			continue;
		}
		printf("PLACA:%c%c%c DEBITO:%d", mp1, mp2, mp3, mDebito);
		printf("\n");
		mDebito = 0;
	}
	printf("SOMA:%d\n", soma);
	return 0;
}
