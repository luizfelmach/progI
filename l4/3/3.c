#include <stdio.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} tData;

int ehBisexto(tData data) {
	return data.ano % 4 == 0;
}

int ultimoDiaDoMes(tData data) {
	int mes = data.mes;
	int ano = data.ano;
	if (ehBisexto(data) && mes == 2) {
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
	if (mes <= 0) mes = 1;
	if (dia <=  0) dia = 1;
	data.dia = dia;
	data.mes = mes;
	int ultimoDia = ultimoDiaDoMes(data);
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

void printaData(tData data) {
	printf("'%02d/%02d/%04d'", data.dia, data.mes, data.ano);
}

int main() {
	int n;
	tData data;
	scanf("%d", &n);
	while(n--) {
		data = leData();
		printaData(data);
		if(ehBisexto(data))
			printf(":Bisexto\n");
		else
			printf(":Normal\n");
	}
	return 0;
}
