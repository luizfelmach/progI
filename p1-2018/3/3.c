#include <stdio.h>

int ehDigito(char c) {
	return c >= '0' && c <=	'9';
}

int ehLetra(char c) {
	int mi =  c >= 'a' && c <= 'z';
	int ma =  c >= 'A' && c <= 'Z';
	return ma || mi;

}

int ehMin(char c) {
	int mi =  c >= 'a' && c <= 'z';
	return mi;
}

char toUpp(char c) {
	if (ehMin(c)) return 'A' + c - 'a';
	
	return c;
}


int main() {

	char c1, c2, c3;
	char m1, m2, m3;
	scanf("%c%c%c %c%c%c", &c1, &c2, &c3, &m1, &m2, &m3);

	char r1, r2, r3;


	if (!ehDigito(c1) || !ehDigito(m1)) {
		printf("Codigo invalido!\n");
		return 0;
	}

	if (!ehMin(c2) || !ehMin(m2)) {
		printf("Codigo invalido!\n");
		return 0;
	}
	if (!ehLetra(c3) || !ehLetra(m3)) {
		printf("Codigo invalido!\n");
		return 0;
	}


	if (c1 == m1) {
		r1 = 'I';
	} else {
		r1 = 'D';
	}

	if (c2 == m2) {
		r2 = 'I';
	} else  {
		r2 = 'D';
	}


	if (c3 == m3) {
		r3 = 'I';
	} else if (toUpp(c3) == toUpp(m3)) {
		r3 = 'C';
	} else  {
		r3 = 'D';
	}

	printf("%c%c%c\n", r1, r2, r3);

	return 0;
}
