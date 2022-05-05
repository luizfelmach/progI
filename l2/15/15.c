#include <stdio.h>

int main() {
    int qtdNeg = 0, qtdPos = 0, somaNeg = 0, somaPos = 0;
    int num;
    char atual;
    while (1) {
        int leu = scanf("%d%c", &num, &atual);
        if (leu == -1) break;
        if (num > 0) {
            somaPos += num;
            qtdPos++;
        }
        if (num < 0) {
            somaNeg += num;
            qtdNeg++;
        }
        if (atual != ' ') break;
    }
    printf("%d %d %d %d", qtdNeg, qtdPos, somaNeg, somaPos);
    return 0;
}
