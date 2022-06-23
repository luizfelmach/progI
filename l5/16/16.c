#include <stdio.h>
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
void OrdenaCrescente(tCandidato * vet, int qtd) {
	tCandidato cur, next;
	int i, j;
	for ( i = 0; i < qtd; i++) {
		for (j = 0; j < qtd -1; j++) {
			cur = vet[j];
			next = vet[j+1];
			if (cur.nota < next.nota) {
				vet[j] = next;
				vet[j+1] = cur;
			}
			if (cur.nota == next.nota) {
				if (cur.idade > next.idade) {
					vet[j] = next;
					vet[j+1] = cur;
				}

				if (cur.idade == next.idade) {
				
					if (cur.codigo > next.codigo) {
						vet[j] = next;
						vet[j+1] = cur;
					}
				}
			}
		}
	}
}

void ImprimeCandidato(tCandidato candidato){
	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
	candidato.codigo, candidato.nome,
	candidato.sobrenome, candidato.nota, candidato.idade);
}
