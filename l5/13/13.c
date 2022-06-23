#include <stdio.h>

#define MAX 1000


void inicializaString(char* str) {
	int i;
	for (i = 0; i < MAX; i++) {
		str[i] = '\0';
	}
}

int comparaString(char* s1, char* s2) {
	int i;
	for (i = 0; i < MAX; i++) {
		if (s1[i] != s2[i]) {
			return 0;
		}
	}

	return 1;
}

int main() {
	char str1[MAX];
	char str2[MAX];

	inicializaString(str1);
	inicializaString(str2);

	while (scanf("%s", &str1) == 1 &&
			scanf("%s", &str2)  == 1) {
		if (comparaString(str1, str2)) {
			printf("IGUAL\n");
		} else {
			printf("DIFERENTE\n");
		}
		inicializaString(str1);
		inicializaString(str2);
	}

	return 0;
}
