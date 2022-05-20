#include <stdio.h>

int verificapH(float pH) {
	if (pH > 7.0)
		return 2;
	else if (pH < 7.0)
		return 1;
	else return 0;
}

float porcentagem(float total, float valor) {
	return valor / total * 100;
}

int verificaGotaChuvaAcida(float pH) {
	return pH < 5.7;
}

float positivo(float n) {

	if (n < 0) return n * -1;
	return n;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
	if (porcentagemGotasChuvaAcida >= 75.0) 
		printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	else if (porcentagemGotasChuvaNormal >= 75.0)
		printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	else 
		printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}

int main() {
	int area = 0, densidade = 0, tempo = 0, gotas = 0;
	int pH = 0;
	float porcentagemAcido = 0, porcentagemNormal = 0;
	int acido = 0;
	int qtdAcido = 0, qtdBasico = 0, qtdNeutro = 0;
	float gota = 0.0;
	float maisAcido = 15.0, maisBasico = 0.0, maisNeutro = 15;
	
	scanf("%d %d %d", &area, &densidade, &tempo);
	gotas = densidade * area * tempo;

	if (gotas == 0) {
		printf("Nenhuma gota foi avaliada");
		return 0;
	}

	int i;
	for (i = 0; i < gotas; i++) {
		scanf("%f", &gota);
		pH = verificapH(gota);

		if (gota < maisAcido) maisAcido = gota;
		if (gota > maisBasico) maisBasico = gota;
		if (positivo(7.0 - gota) < positivo(7.0 - maisNeutro)) maisNeutro = gota;

		if (pH == 1) qtdAcido++;
		else if (pH == 2) qtdBasico++;
		else qtdNeutro++;

		if (verificaGotaChuvaAcida(gota)) acido++;
	}

	porcentagemAcido = porcentagem(gotas, acido);
	porcentagemNormal = 100.0 - porcentagemAcido;


	
	printf("%d %d %d %.2f %.2f %.2f\n", qtdAcido, qtdBasico, qtdNeutro, maisAcido, maisBasico, maisNeutro);
	imprimeResultadosAnalise(porcentagemAcido, porcentagemNormal);
	return 0;
}
