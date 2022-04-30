#include <stdio.h>

int main() {
    int l, c, i, j;
    int somaTotal = 0, soma = 0, atual = 0;
    scanf("%d %d", &l, &c);
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &atual);
            soma += atual;
        }
        printf("%d\n", soma);
        somaTotal += soma;
        soma = 0;
    }
    printf("%d\n", somaTotal);
    return 0;
}
