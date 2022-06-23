#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct {
	int codigo;
	char sobrenome[MAX];
	char nome[MAX];
	int nota;
	int idade;
	int imprimiu;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
int ComparaString(char* s1, char* s2);
int jaExisteSobrenome(tCandidato* candidatos, int tam, int emAnalise);
int imprimeMesmoSobrenome(tCandidato* c, int tam, int emAnalise);

int main() {
	int qtdCand, i = 0;
	scanf("%d", &qtdCand);
	tCandidato candidatos[qtdCand];
	for (i = 0; i < qtdCand; i++) {
		candidatos[i] = LeCandidato();
	}
	for (i = 0; i < qtdCand; i++) {
		if (jaExisteSobrenome(candidatos, qtdCand, i)) {
			imprimeMesmoSobrenome(candidatos, qtdCand, i);
		}
	}
	return 0;
}

tCandidato LeCandidato() {
	tCandidato candidato;
	scanf("%*[^{]");
	scanf("%*[{ ]");
	scanf("%d", &candidato.codigo);
	scanf("%*[, ]");
	scanf("%[^,],", candidato.sobrenome);
	scanf("%*[ ]");
	scanf("%[^,],", candidato.nome);
	scanf("%d", &candidato.nota);
	scanf("%*[, ]");
	scanf("%d", &candidato.idade);
	scanf("%*[^\n]\n");
	candidato.imprimiu = 0;
	return candidato;
}
void ImprimeCandidato(tCandidato candidato){
	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
	candidato.codigo, candidato.nome,
	candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char* s1, char* s2) {
	int i = 0;
	char as1, as2;
	while (1) {
		as1 = s1[i];
		as2 = s2[i];
		if (as1 == '\0' && as2 == '\0') return 1;
		if (as1 != as2) return 0;
		i++;
	}
	return 1;
}

int jaExisteSobrenome(tCandidato* c, int tam, int emAnalise) {
	int i;
	for (i = 0; i < tam; i++) {
		if (i != emAnalise && ComparaString(c[emAnalise].sobrenome, c[i].sobrenome)) {
			return 1;
		}
	}

	return 0;
}

int imprimeMesmoSobrenome(tCandidato* c, int tam, int emAnalise) {
	
	int i;
	for (i = 0; i < tam; i++) {
		if (!c[i].imprimiu && ComparaString(c[emAnalise].sobrenome, c[i].sobrenome)) {
			ImprimeCandidato(c[i]);
			c[i].imprimiu = 1;
		}
	}
}
