#include <stdio.h>
#include <string.h>

int charParaNumero(char numero) { return (int)(numero - 48); }

int ehImpar(int numero) { return numero % 2; }

int main() {
    char numero[5] = "";
    int interesse = 0;
    scanf("%s %d", numero, &interesse);
    int algarismo = charParaNumero(numero[strlen(numero) - interesse]);
    if (ehImpar(algarismo)) {
        printf("IMPAR");
    } else {
        printf("PAR");
    }
    return 0;
}
