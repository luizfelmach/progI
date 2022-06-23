#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int codigo;
	char sobrenome[21];
	char nome[21];
	int nota;
	int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato * vet, int qtd);

int main(){
	int qtdCand, i = 0, j;
	scanf("%d", &qtdCand);
	tCandidato candidatos[qtdCand];
	for(i = 0; i < qtdCand; i++){
		candidatos[i] = LeCandidato();
	}
	OrdenaCrescente(candidatos, qtdCand);

	for(i = 0; i < qtdCand; i++){
		ImprimeCandidato(candidatos[i]);
	}
	return 0;
}
tCandidato LeCandidato(){
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
	return candidato;
}

void ImprimeCandidato(tCandidato candidato){
	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
	candidato.codigo, candidato.nome,
	candidato.sobrenome, candidato.nota, candidato.idade);
}

void concatenaString(char* str1, char* str2, char* out) {
	int i;
	char atual;
	int s = 0;
	for (i = 0; i < 20; i++) {
		atual = str1[s];
		if (atual == '\0') break;
		out[i] = atual;
		s++;
	}

	s = 0;
	for (; i < 20; i++) {
		atual = str2[s];
		if (atual == '\0') break;
		out[i] = atual;
		s++;
	}
}

void OrdenaCrescente(tCandidato * vet, int qtd) {
	int i, j;
	tCandidato cur, next;
	char nomeCompletoCur[50];
	char nomeCompletoNext[50];

	for (i = 0; i < qtd; i++) {
		for (j = 0; j < qtd -1; j++) {
			cur = vet[j];
			next = vet[j+1];
			concatenaString(cur.nome, cur.sobrenome, nomeCompletoCur);
			concatenaString(next.nome, next.sobrenome, nomeCompletoNext);
			if (strcmp(nomeCompletoCur, nomeCompletoNext) > 0) {
			
				vet[j] = next;
				vet[j+1] = cur;
			}
		}
	}
}

