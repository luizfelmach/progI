#include <stdio.h>

int main() {
	int n1, n2;
	char op;
	int res = 0;
	scanf("%d %d %c", &n1, &n2, &op);

	if (op == '+') res = n1 + n2;
	else if (op == '-') res = n1 - n2;
	else if (op == '*') res = n1 * n2;
	else if (op == '/') res = n1 / n2;
	else {
		printf("Invalido");
		return 0;
	}

	printf("RESP:%d", res);

	return 0;
}
