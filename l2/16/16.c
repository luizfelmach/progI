#include <stdio.h>

int main() {
    char atual;
    int num, menor = 0, primeiraPos = -1, ultimaPos = -1;
    int i, cont = 0, pos = 0;
    while (1) {
        if (scanf("%d", &num) > 0) {
            if (cont == 0 || num < menor) menor = num;
            cont++;
        } else {
            scanf("%c", &atual);
            if (atual != ' ') break;
        }
    }
    cont = 0;
    while (1) {
        if (scanf("%d", &num) > 0) {
            if (num == menor && pos == 0) {
                primeiraPos = cont;
                ultimaPos = cont;
                pos++;
            } else if(num == menor) {
                ultimaPos = cont;
            }
            cont++;
        } else {
            scanf("%c", &atual);
            if (atual != ' ') break;
        }
    }
    if (primeiraPos == -1) {
        primeiraPos = cont;
        ultimaPos = cont;
    }
    printf("%d %d %d", menor, primeiraPos, ultimaPos);
    return 0;
}
