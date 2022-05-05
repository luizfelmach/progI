#include <stdio.h>

int main() {
    unsigned int num = 0;
    scanf("%d", &num);
    int i = 1;
    int soma = 0;
    printf("RESP:");
    while (1) {
        float div = ((float)num / (float)i);
        int dig = (int)div % 10;
        soma += dig;
        i *= 10;
        if (div < 1) {
            if (soma < 10) {
                printf("%d", soma);
                break;
            }
            num = soma;
            soma = 0;
            i = 1;
        }
    }
    return 0;
}
