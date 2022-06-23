#include <stdio.h>

#define MAX 1000

void concatenaString(char* str1, char* str2, char* out) {
	int i;
	char atual;
	int s = 0;
	for (i = 0; i < MAX; i++) {
		atual = str1[s];
		if (atual == '\0') break;
		out[i] = atual;
		s++;
	}

	s = 0;
	for (; i < MAX*2; i++) {
		atual = str2[s];
		if (atual == '\0') break;
		out[i] = atual;
		s++;
	}
}

void inicializaString(char *str) {
	int i;
	for (i = 0; i < MAX; i++)
		str[i] = '\0';
}

int main() {
	char nome[MAX];
	char sobrenome[MAX];
	char nomeCompleto[2*MAX];

	inicializaString(nome);
	inicializaString(sobrenome);

	while(scanf("%s", sobrenome) == 1 &&
			scanf("%s", nome) == 1) {
		concatenaString(nome, sobrenome, nomeCompleto);
		printf("%s\n", nomeCompleto);
		inicializaString(nome);
		inicializaString(sobrenome);
		inicializaString(nomeCompleto);
	}


	return 0;
}
