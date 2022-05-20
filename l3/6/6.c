#include <stdio.h>

int ehPalindromo(int num) {
	int mul = 0, novoNum = 0, _num = num;
	int i =1;
	while (1) {
		if ( num  % i == num) {
			mul = i/10;
			break;
		}
		i *= 10;
	}
	while (_num > 0) {
		novoNum += (_num % 10) * mul;
		mul /= 10;
		_num /= 10;
	}
	return novoNum == num;
}

int main() {
	int num = 0;
	while (scanf("%d", &num) == 1) {
		if (ehPalindromo(num))
			printf("S\n");
		else printf("N\n");
	}
	return 0;
}
