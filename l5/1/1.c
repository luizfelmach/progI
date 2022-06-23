#include <stdio.h>
#include <math.h>

float calculaMedia(int *notas, int tam) {
	float soma = 0;
	int i;
	for (i = 0; i < tam; i++) {
		soma += notas[i];
	}
	return soma / (float)tam;
}

float calculaDesvio(int *notas, int tam) {
	float soma = 0;
	float media = calculaMedia(notas, tam);
	int i;
	for (i = 0; i < tam; i++) {
		soma += pow(notas[i] - media, 2);
	}
	soma /= tam;
	return sqrt(soma);
}


int calculaMaior(int *notas, int tam) {
	int maior = -100;
	int i;
	for (i = 0; i < tam; i++) {
		if (maior < notas[i])
			maior = notas[i];
	}
	return maior;
}

int calculaMenor(int *notas, int tam) {
	int menor = 110;
	int i;
	for (i = 0; i < tam; i++) {
		if (menor > notas[i])
			menor = notas[i];
	}
	return menor;
}

int acimaDaMedia(int *notas, int tam) {
	int cont = 0;
	float media = calculaMedia(notas, tam);
	int i;
	for (i = 0; i < tam; i++) {
		if (notas[i] > media)
			cont++;
	}
	return cont;
}

int reprovados(int *notas, int tam) {
	int cont = 0;
	int i;
	for (i = 0; i < tam; i++) {
		if (notas[i] < 70)
			cont++;
	}
	return cont;
}

int main() {
	int n, i;
	int menor, maior, acima = 0, rep = 0;
	float media = 0, desvio;
	scanf("%d", &n);
	int notas[n];
	for (i = 0; i < n; i++)
		scanf("%d", &notas[i]);

	menor = calculaMenor(notas, n);
	maior = calculaMaior(notas, n);
	media = calculaMedia(notas, n);
	desvio = calculaDesvio(notas, n);
	acima = acimaDaMedia(notas, n);
	rep = reprovados(notas, n);

	printf("MENOR:%d, MAIOR:%d, "
		"MEDIA:%.2f, STD:%.2f, "
		"ACIMA_MEDIA_CONC:%d, REPROV:%d", 
		menor, maior, media, desvio, acima, rep);
	return 0;
}
