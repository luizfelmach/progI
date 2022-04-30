#include <stdio.h>

int ultimo(int pessoas, int itens) {
    int ultimo = (itens % pessoas) ? (itens % pessoas) : pessoas;
    return ultimo;
}

int main() {
    int pessoas = 0, itens = 0;
    scanf("%d %d", &pessoas, &itens);
    printf("RESP:%d", ultimo(pessoas, itens));
    return 0;
}
