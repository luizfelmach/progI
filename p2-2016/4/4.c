#include <stdio.h>


float fazOperacao(float num1, float num2, char op) {
	switch (op) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '/':
			return num1 /num2;
		case '*':
			return num1 * num2;
	}
}

int terminouOp(char c) {
	return c == ')';
}

float resolve() {
	char op = '\0';
	float res = 0;
	float n1, n2;

	scanf("%f %f %c ", &n1, &n2, &op);
	res = fazOperacao(n1, n2, op);
	

	while (scanf("%f %c ", &n2, &op) == 2) {
		res = fazOperacao(res, n2, op);
	}

	scanf("%*c");
	return res;	
}

int terminou(char c) {
	return c == '.';
}

int achouOp(char c) {
	return c == '(';
}

int main() {
	float maior = 0;
	char letra = '\0';
	float res = 0;
	int cont = 0;

	while (!terminou(letra)) {
		scanf("%c", &letra);

		if (achouOp(letra)) {
			res = resolve();
			printf("%.2f", res);
			if (cont == 0) maior = res;
			if (res > maior) maior = res;
		} else {
			printf("%c", letra);

		}
		cont++;
		
	}
	printf(" MAIOR:%.2f", maior);
	return 0;
}
