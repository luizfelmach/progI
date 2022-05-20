#include <stdio.h>

int main() {
	int n1 = 0, n2 = 0;
	int inter = 0;
	int num1 = 0, num2 = 0;
	char c = '\0';
	scanf("(%c,%d,%d)", &c, &n1, &n2);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		num1 = n1;
		num2 = n2;
	} else {
		num1 = n2;
		num2 = n1;
	}

	inter += num1 % 10;
	num1 /= 10;
	inter += num1 % 10 * 100;
	num1 /= 10;
	inter += num1 % 10 * 10000;
	num1 /= 10;
	inter += num1 % 10 * 1000000;

	inter += num2 % 10 * 10;
	num2 /= 10;
	inter += num2 % 10 * 1000;
	num2 /= 10;
	inter += num2 % 10 * 100000;
	num2 /= 10;
	inter += num2 % 10 * 10000000;

	printf("(%d)\n", inter);
	return 0;
}
