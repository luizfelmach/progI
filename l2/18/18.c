#include <stdio.h>

int main() {
    int l = 0, c = 0, atual = 0;
    int maior = 0, lMaior = 0, cMaior = 0;
    scanf("%d %d", &l, &c);
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &atual);
            if (i == 0 && j == 0) {
                maior = atual;
                lMaior = i + 1;
                cMaior = j + 1;
            }
            if (atual > maior) {
                maior = atual;
                lMaior = i + 1;
                cMaior = j + 1;
            }
        }
    }
    printf("%d (%d, %d)", maior, lMaior, cMaior);
    return 0;
}
