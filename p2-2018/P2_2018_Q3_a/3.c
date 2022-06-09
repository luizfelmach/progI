#include <stdio.h>

#define INF 0x3f3f3f3f

double leNotasECalculaMediaAluno() {
	double media = 0;
	int menorNota = INF;
	int nota;
	int cont = 0;
	while (scanf("%d ", &nota) == 1) {
		media += (double)nota;
		cont++;
		if (nota < menorNota) {
			menorNota = nota;
		}
	}
	scanf("%*c%*c");

	if (cont == 1) {
		return media;
	} else {
		media -= menorNota;
		cont--;
		return media/(double)cont;
	}
	return media;
}

int contaAlunosAprovadosTurma() {
	int qtdAluno;
	double media;
	scanf("%d\n", &qtdAluno);
	int res = 0;
	char c1, c2;
	int i;
	for (i = 0; i < qtdAluno; i++) {
		scanf("%c%c%*c", &c1, &c2);
		media = leNotasECalculaMediaAluno();

		if (media >= 70) {
			printf("%c\n", c1);
			res++;
		}
	}

	return res;
}

int main() {
	int qtd;
	scanf("%d", &qtd);
	int maior = -INF, menor = INF;
	int conta;

	int ma = 1;
	int me = 1;

	int i;
	for (i = 1; i <= qtd; i++) {
		printf("TURMA:%d\n", i);
		conta = contaAlunosAprovadosTurma();
		if (conta > maior) {
			maior = conta;
			ma = i;
		};
		if (conta < menor) {
			menor = conta;
			me = i;
		};
	}

	printf("MAIOR:TURMA %d MENOR:TURMA %d\n", ma, me);
	return 0;
}

