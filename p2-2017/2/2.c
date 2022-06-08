#include <stdio.h>

int ehIgual(int a, int b) {
	return a == b;
}

int inverte(int n) {
	int res = 0;
	int grandeza = 1;
	
	while (grandeza <= n) {
		grandeza *= 10;
	}
	grandeza /= 10;

	int a;

	for (grandeza, a = 1; grandeza >= 1; grandeza/=10, a*=10) {
		res += ((n / grandeza) % 10) * a;
	}

	return res;
}

int main() {
	int num; 
	int invertido;
	int cont = 0;

	while (scanf("%d", &num) == 1) {
		invertido = inverte(num);
		if (ehIgual(invertido, num)) cont++;
	}

	printf("COUNT:%d", cont);

	return 0;
}
