#include <stdio.h>

int main() {

	int inc;
	int dias = 0, horas = 0, minutos = 0;

	scanf("%d:%d %d", &horas, &minutos, &inc);
	int aux;
	minutos += inc;
	aux = minutos / 60;
	minutos %= 60;
	horas += aux;
	aux = horas / 24;
	horas %= 24;
	dias += aux;

	if (dias) {
		if (dias == 1) printf("(1 dia)");
		else printf("(%d dias)", dias);
	}
	if (horas) {
		if (horas == 1) printf("(1 hora)");
		else printf("(%d horas)", horas);
	}
	if (minutos) {
		if (minutos == 1) printf("(1 minuto)");
		else printf("(%d minutos)", minutos);
	}
	printf("\n");
	return 0;
}
