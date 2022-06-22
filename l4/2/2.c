#include <stdio.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} tData;

int ehBissexto(int ano) {
	return ano % 4 == 0;
}

int ultimoDiaDoMes(int mes, int ano) {
	if (ehBissexto(ano) && mes == 2) {
		return 29;
	}
	if (mes == 1) return 31;
	if (mes == 2) return 28;
	if (mes == 3) return 31;
	if (mes == 4) return 30;
	if (mes == 5) return 31;
	if (mes == 6) return 30;
	if (mes == 7) return 31;
	if (mes == 8) return 31;
	if (mes == 9) return 30;
	if (mes == 10) return 31;
	if (mes == 11) return 30;
	if (mes == 12) return 31;
	return 0;
}

tData corrigeData(tData data) {
	int dia = data.dia;
	int mes = data.mes;
	int ano =  data.ano;
	if (mes > 12) mes = 12;
	int ultimoDia = ultimoDiaDoMes(mes, ano);
	if (dia > ultimoDia) dia = ultimoDia;
	data.dia = dia;
	data.mes = mes;
	return data;
}

tData leData() {
	int dia, mes, ano;
	scanf("%d %d %d", &dia, &mes, &ano);
	tData data = {dia, mes, ano};
	data = corrigeData(data);
	return data;
}

tData acrescentaData(tData data) {
	int dia = data.dia;
	int mes = data.mes;
	int ano =  data.ano;
	int ultimoDia = ultimoDiaDoMes(mes, ano);
	if (dia + 1 > ultimoDia) {
		dia = 1;
		mes++;
	} else {
		dia++;
	}
	if (mes > 12) {
		mes = 1;
		ano++;
	}
	data.dia = dia;
	data.mes = mes;
	data.ano = ano;
	return data;
}

int ehDataIgual(tData d1, tData d2) {
	return d1.dia == d2.dia &&
		d1.mes == d2.mes &&
		d1.ano == d2.ano;
}

void printData(tData data) {
	printf("'%02d/%02d/%04d'\n", data.dia, data.mes, data.ano);
}

int main() {
	tData dataInicial = leData();
	tData dataFinal = leData();

	tData i;
	for (i = dataInicial; !ehDataIgual(i, dataFinal); i = acrescentaData(i)) {
		printData(i);
	}
	return 0;
}
