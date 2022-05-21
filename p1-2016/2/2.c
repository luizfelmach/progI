#include <stdio.h>

int main() {
	int a = 0, b = 0;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
	int total = 0;
	int valor1, valor2, valor3;
	int i;
	valor1 = a * x1 + b;
	valor2 = a * x2 + b;
	valor3 = a * x3 + b;
	if (valor1 == y1) total++;
	if (valor2 == y2) total++;
	if (valor3 == y3) total++;

	if (total == 3)
		printf("Todos");
	else if (total == 2)
		printf("Dois");
	else if (total == 1)
		printf("Um");
	else printf("Nenhum");
	return 0;
}
