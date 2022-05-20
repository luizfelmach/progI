#include <stdio.h>

int propriedade(int num) {
	int soma = 0, _num = num;
	int produto = 0;
	soma += _num % 100;
	_num /= 100;
	soma += _num;
	produto = soma * soma;
	if (produto == num) return 1;
	return 0;
}

int main() {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int i;
	for (i = n + 1; i < m; i++) {
		if (propriedade(i)) printf("%d\n", i);
	}
	return 0;
}
