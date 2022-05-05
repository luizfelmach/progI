#include <stdio.h>

int main() {
    char atual = ' ';
    int podeImprimir = 0;
    int par = 0;
    printf("RESP:");
    while (1) {
        scanf("%c", &atual);
        if (atual == '.' && podeImprimir == 0) break;
        if (atual == '(') {
            par++;
            podeImprimir = 1;
            if (par == 1) continue;
        };
        if (atual == ')') {
            par--;
            if (par == 0) {
                podeImprimir = 0;
            }
        }
        if (podeImprimir) {
            printf("%c", atual);
        }
    }
    return 0;
}
