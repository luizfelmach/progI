#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} tPonto;

tPonto inicializaPonto(int x, int y) {
	tPonto ponto = {x, y};
	return ponto;
}

tPonto lePonto() {
	int x, y;
	tPonto ponto;
	scanf("%d %d", &x, &y);
	ponto.x = x;
	ponto.y = y;
	return ponto;
}

tPonto alteraPontoX(tPonto ponto, int n) {
	ponto.x = n;
	return ponto;
}

tPonto alteraPontoY(tPonto ponto, int n) {
	ponto.y = n;
	return ponto;
}

int getX(tPonto ponto) {
	return ponto.x;
}

int getY(tPonto ponto) {
	return ponto.y;
}

tPonto deslocaPontoX(tPonto ponto, int n) {
	ponto.x += n;
	return ponto;
}

tPonto deslocaPontoY(tPonto ponto, int n) {
	ponto.y += n;
	return ponto;
}

float distanciaPontos(tPonto p1, tPonto p2) {
	float a1 = pow(p1.x - p2.x, 2);
	float a2 = pow(p1.y - p2.y, 2);
	return sqrt(a1 + a2);
}

int quadrantePonto(tPonto ponto) {
	int x = ponto.x;
	int y = ponto.y;
	if (y > 0) {
		if (x > 0)
			return 1;
		else if (x < 0)
			return 2;
	} else if ( y < 0) {
		if (x < 0)
			return 3;
		else if (x > 0)
			return 4;
	}
	return 0;
}

tPonto simetricoPonto(tPonto ponto) {
	ponto.x *= -1;
	ponto.y *= -1;
	return ponto;
}

void printaPonto(tPonto ponto) {
	printf("(%d,%d)", ponto.x, ponto.y);
}

int main() {
	int n;
	float dist;
	tPonto pontoAtual;
	tPonto pontoPrev;
	scanf("%d", &n);
	pontoPrev = lePonto();
	printf("-\n");
	n--;
	while(n--) {
		pontoAtual = lePonto();
		dist = distanciaPontos(pontoPrev, pontoAtual);
		printf("%.2f\n", dist);
		pontoPrev = pontoAtual;
	}
	return 0;
}
