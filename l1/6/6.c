#include <stdio.h>

int main() {
    int nota1 = 0, nota2 = 0;
    scanf("%d %d", &nota1, &nota2);
    float media = ((float)nota1 + (float)nota2) / 2.0;
    if (media >= 7.0) {
        printf("%.1f - Aprovado", media);
    } else if (media >= 5.0) {
        printf("%.1f - De Recuperacao", media);
    } else {
        printf("%.1f - Reprovado", media);
    }
    return 0;
}
