#include <stdio.h>

char up (char n) {
	char charUp = n;

	if (n >= 'a' && n <= 'z') {
		charUp = 'A' + (n - 'a');
	}

	return charUp;
}

int main() {
	char letra = '\0';
	char codigo[4];

	scanf("%c", &letra);
	if (letra >= 'A' && letra <= 'Z')
		codigo[0] = letra;
	else {
		printf("Invalido");
		return 0;
	}

	scanf("%c", &letra);
	if (letra >= '0' && letra <= '9')
		codigo[1] = letra;
	else {
		printf("Invalido");
		return 0;
	}

	scanf("%c", &letra);
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
		codigo[2] = letra;
	else {
		printf("Invalido");
		return 0;
	}

	scanf("%c", &letra);
	if ((letra >= 'a' && letra <= 'z') && letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u') 
		codigo[3] = letra;
	else {
		printf("Invalido");
		return 0;
	}

	printf("%c%c%c%c", up(codigo[0]), up(codigo[1]), up(codigo[2]), up(codigo[3]));

	return 0;

}
