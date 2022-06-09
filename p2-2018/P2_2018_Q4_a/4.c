#include <stdio.h>

int casa = 1;
int senha = 0;

int charToInt(char c) {
	return c - '0';
}

int somaDigitos(int n) {
	int soma = 0;
	while (n > 0) {
		soma += n % 10;
		n /= 10;
	}
	return soma;
}

int reduzInteiro(int n) {
	while (n > 9) {
		n = somaDigitos(n);
	}

	return n;
}

int montaSenha(int dig) {
	senha += dig * casa;
	casa *= 10;
	return senha;
}

void inverteSenha() {

	int grandeza = 1;
	int res = 0;
	while (grandeza <= senha) grandeza *= 10;
	grandeza /= 10;

	int cp = grandeza;

	int i;
	int dig;
	for (i = 1; i < cp * 10; i*=10) {
		dig = (senha/grandeza) % 10;
		res += dig * i; 
		grandeza /= 10;
	}

	senha = res;

}

int reduzCodigo() {
	int soma = 0;
	char c = '\0';
	int cont = 0;

	while (1) {
		scanf("%c", &c);
		if (c == ')') break;
		soma += charToInt(c);
		cont++;
	}

	if (cont == 0) return -1;

	return reduzInteiro(soma);
}


int main() {
	char c = '\0';

	int value;
	while (c != '.') {
		scanf("%c", &c);
		if (c == '(') {
			value = reduzCodigo();
			if (value == -1) printf("[ERRO]");
			else {
				printf("[%d]", value);
				montaSenha(value);
			}
		
		}
		else printf("%c", c);

	}
	inverteSenha();

	printf(" SENHA:%d\n", senha);

	return 0;
}
