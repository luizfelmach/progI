#include <stdio.h>

int ehLetra(char c) {
	int ma = c >= 'A' && c <= 'Z';
	int mi = c >= 'a' && c <= 'z';
	return ma || mi;
}

void removePontuacao(char* s) {
	int i, j;
	char cur, next;
	for (i = 0; i < 500;i++) {
		cur = s[i];
		next = s[i+1];
		if (!ehLetra(cur)) {
			if (next == '\0') {
				s[i] = '\0';
			}
			if (next != '\0') {
				s[i] = next;
			}
		}
	}
}

void reseta(char* s) {
	int i;
	for (i = 0; i < 501;i++) {
		s[i] = '\0';
	}
}

void copiaPalavra(char* t, char* buffer) {
	reseta(t);
	int i;
	for (i = 0; i < 501; i++) {
		t[i] = buffer[i];
	}
}

int main() {
	char texto[500][501];

	int i = 0, scan;
	int palavra = 0;
	char c;
	char buffer[501];
	reseta(buffer);

	while(1) {
		int scan = scanf("%c", &c);
		if (scan != 1) {
			if (buffer[0] != '\0') {
					copiaPalavra(texto[palavra], buffer);
					palavra++;
				}
				break;
		}
		if (!ehLetra(c)) {
			if (buffer[0] != '\0') {
				copiaPalavra(texto[palavra], buffer);
				palavra++;
			}
			reseta(buffer);
			i= 0;
			continue;
		}
		buffer[i] = c;
		i++;
	}

	while(palavra--) {
		printf(" %s", texto[palavra]);
	}
	printf(" ");
	return 0;
}
