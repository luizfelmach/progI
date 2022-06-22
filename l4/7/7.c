#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} tPonto;

typedef struct {
	tPonto pInicial;
	tPonto pFinal;
} tReta;

tPonto inicializaPonto(int x, int y) {
	tPonto ponto = {x, y};
	return ponto;
}

tReta inicializaReta(tPonto p1, tPonto p2) {
	tReta reta;
	reta.pInicial = p1;
	reta.pFinal = p2;
	return reta;
}

tPonto lePonto() {
	int x, y;
	tPonto ponto;
	scanf("%d %d", &x, &y);
	ponto = inicializaPonto(x, y);
	return ponto;
}

tReta leReta() {
	tReta reta;
	tPonto p1, p2;
	p1 = lePonto();
	p2 = lePonto();
	reta = inicializaReta(p1, p2);
	return reta;
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

tPonto getPontoInicial(tReta reta) {
	return reta.pInicial;
}

tPonto getPontoFinal(tReta reta) {
	return reta.pFinal;
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

float tamanhoDaReta(tReta reta) {
	return distanciaPontos(reta.pInicial, reta.pFinal);
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

void printaReta(tReta reta) {
	printf("[");
	printaPonto(reta.pInicial);
	printf(":");
	printaPonto(reta.pFinal);
	printf("]");
}

int main() {
	int n;
	tReta reta;
	scanf("%d", &n);
	int q1, q2;
	while(n--) {
		reta = leReta();
		q1 = quadrantePonto(getPontoInicial(reta));
		q2 = quadrantePonto(getPontoFinal(reta));

		if (q1 == q2 && (q1 != 0 || q2 != 0))
			printf("MESMO\n");
		else 
			printf("DIFERENTE\n");
	}
	return 0;
}
