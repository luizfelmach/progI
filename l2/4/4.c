#include <stdio.h>

int main() {
    int maior = 0, cont = 0, atual = 1, i;
    float media = 0;
    while (atual) {
        scanf("%d", &atual);
        if (atual == 0) break;
        if (atual > maior) maior = atual;
        media += atual;
        cont++;
        printf("%d %.6f\n", maior, media / (float)cont);
    }
    return 0;
}
