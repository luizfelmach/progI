#include <stdio.h>

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    printf("RESP:");
    int i;
    for (i = n + 1; i < m; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
