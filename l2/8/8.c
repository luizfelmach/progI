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

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    printf("RESP:");
    int i;
    for (i = n + 1; i < m; i++) {
        if (ehPrimo(i)) printf("%d ", i);
    }
    return 0;
}
