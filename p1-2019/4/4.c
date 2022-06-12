#include <stdio.h>

int ehDig(char c) {
	return c >= '0' && c <= '9';
}
int charParaInt(int c) {
	return c - '0';
}

int main() {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;

	char c;
	int num = 0;
	int cont = 1;
	while (cont <= 11) {
		scanf("%c", &c);
		if (ehDig(c)) {
			num = charParaInt(c);
			if (cont == 1) n1 = num;
			if (cont == 2) n2 = num;
			if (cont == 3) n3 = num;
			if (cont == 4) n4 = num;
			if (cont == 5) n5 = num;
			if (cont == 6) n6 = num;
			if (cont == 7) n7 = num;
			if (cont == 8) n8 = num;
			if (cont == 9) n9 = num;
			if (cont == 10) n10 = num;
			if (cont == 11) n11 = num;
			cont++;
		}
	}
	//printf("%d%d%d.%d%d%d.%d%d%d-%d%d", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);

	int dig10, dig11;
	int soma = 0;
	int aux;

	soma = n1*10 + n2*9 + n3*8 + n4*7 + n5*6 + n6*5 + n7*4 + n8*3 + n9*2;
	if (soma % 11 < 2) {
		dig10 = 0;
		aux = dig10;
	};
	if (soma % 11 >= 2) {
		dig10 = (11-(soma%11));
		aux =  dig10;
	}

	soma = 0;
	soma = n1*11 + n2*10 + n3*9 + n4*8 + n5*7 + n6*6 + n7*5 +n8*4 +n9*3 + aux*2;
	if (soma % 11 < 2) dig11 = 0;
	if (soma % 11 >= 2) dig11 = (11-(soma%11));
	
	if (dig10 == dig11) printf("CPF invalido: digitos iguais!");
	else if (dig10 != n10 && dig11 != n11) printf("CPF invalido: dois digitos!");
	else if (dig10 != n10) printf("CPF invalido: primeiro digito!");
	else if (dig11 != n11) printf("CPF invalido: segundo digito!");
	else printf("CPF valido!");
	return 0;
}
