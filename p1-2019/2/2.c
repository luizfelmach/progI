#include <stdio.h>

int main() {
	int a, b;
	char op;
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+') {
		printf("SOMA:%d", a+b);
	}
	if (op == '-') {
		printf("SUB:%d", a-b);
	}
	if (op == '*') {
		printf("MULT:%d", a*b);
	}
	if (op == '/') {
		int ehInt = !(a % b);

		if (ehInt) {
			printf("DIV:%d", a/b);
		}else {
			printf("DIV:%d, RESTO:%d", a/b, a%b);
		}
	}
	return 0;
}
