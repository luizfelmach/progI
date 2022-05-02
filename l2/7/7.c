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
    int p = 0;
    scanf("%d", &p);
    if (ehPrimo(p))
        printf("Primo");
    else
        printf("Nao primo");
    return 0;
}
