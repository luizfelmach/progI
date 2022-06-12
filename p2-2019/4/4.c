#include <stdio.h>

int ehLetraMaiuscula(char c) {
	return c >= 'A' && c <= 'Z';
}

int ehLetraMinuscula(char c) {
	return c >= 'a' && c <= 'z';
}

int ehNumero(char c) {
	return c >= '0' && c <= '9';
}


int analisaSenha() {
	scanf("%*c");
	char c = '\0';
	int qtdChar = 0;
	int qtdMaiuscula = 0;
	int qtdMinuscula = 0;
	int qtdNum = 0;
	int qtdNAlfa = 0;

	while (1) {
		scanf("%c", &c);
		if (c == ')') break;

		if (ehLetraMaiuscula(c)) qtdMaiuscula++;
		if (ehLetraMinuscula(c)) qtdMinuscula++;
		if (!ehLetraMinuscula(c) && !ehLetraMaiuscula(c) && !ehNumero(c)) qtdNAlfa++;
		if (ehNumero(c)) qtdNum++;
		
		qtdChar++;
	}

	scanf("%*c");
	if (qtdChar < 6) return 0;
	else {
		if (qtdMaiuscula && qtdMinuscula && qtdNum && qtdNAlfa) return 2;
		else return 1;
	}
	return 0;
}

int main() {
	int qtd; scanf("%d\n", &qtd);

	int maiorForte = -1;
	int forteIndex = 0;
	int maiorFraca = -1;
	int fracaIndex = 0;
	int maiorInvalida = -1;
	int invalidaIndex = 0;

	int p, v;
	int forte = 0;
	int fraca = 0;
	int invalida = 0;

	int i;
	for(i = 1; i <= qtd; i++) {
		printf("GRUPO %d\n", i);
		while (1) {
			scanf("%d", &p);
			if(p == -1) break;
			v = analisaSenha();	
			//printf("%d\n", p);
			if (v == 0) {
				invalida++;
				printf("INVALIDA\n");
			}
			else if (v == 1) {
				fraca++;
				printf("FRACA\n");
			}
			else if (v == 2) {
				forte++;
				printf("FORTE\n");
			}
		}
		if (invalida > maiorInvalida) {
			maiorInvalida = invalida;
			invalidaIndex = i;
		}
		if (fraca > maiorFraca) {
			maiorFraca = fraca;
			fracaIndex = i;
		}
		if (forte > maiorForte) {
			maiorForte = forte;
			forteIndex = i;
		}
		invalida = 0;
		fraca = 0;
		forte = 0;
		printf("\n");
	}

	printf("FORTES: GRUPO(%d) QTD(%d)\n", forteIndex, maiorForte);
	printf("FRACAS: GRUPO(%d) QTD(%d)\n", fracaIndex, maiorFraca);
	printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", invalidaIndex, maiorInvalida);
	return 0;
}
