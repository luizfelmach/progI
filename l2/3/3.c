#include <stdio.h>

int main() {
    int qtd = 0, maior = 0, menor = 0, qtdPares = 0, qtdImpares = 0;
    float media = 0.0;
    scanf("%d", &qtd);
    int nums[qtd];
    int i;
    for (i = 0; i < qtd; i++) {
        int lido = 0;
        scanf("%d", &lido);
        nums[i] = lido;
        media += lido;
        if (i == 0 || lido < menor) menor = lido;
        if (i == 0 || lido > maior) maior = lido;
        if (lido % 2 == 0) qtdPares++;
        if (lido % 2 == 1) qtdImpares++;
    }
    media /= (float)qtd;
    printf("%d %d %d %d %.6f", maior, menor, qtdPares, qtdImpares, media);
    return 0;
}
