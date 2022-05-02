#include <stdio.h>

int ehPrimo(int p) {
    int div = 0, i;
    for (i = 1; i <= p; i++) {
        if (p % i == 0) {
            div++;
        }
    }
    return (div == 2);
}

void multiplos(int p, int m) {
    int cont = 0, i;
    for (i = p + 1; i < m; i++) {
        if (i % p == 0) {
            printf("%d ", i);
            cont++;
        }
    }
    if (cont == 0)
        printf("*\n");
    else
        printf("\n");
}

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int i;
    for (i = n + 1; i < m; i++) {
        if (ehPrimo(i)) {
            printf("%d\n", i);
            multiplos(i, m);
        };
    }
    return 0;
}
