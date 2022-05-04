#include <stdio.h>

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int i;
    for (i = n + 1; i < m; i++) {
        int num1 = i / 100;
        int num2 =  i % 100;
        int soma = num1 + num2;
        int produto = soma * soma;
        if (produto == i)
            printf("%d\n", i);
    }
    return 0;
}
