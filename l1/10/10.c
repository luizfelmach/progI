#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    if (num < 0) {
        num *= -1;
    }
    if (num % 2 == 0) {
        printf("Par");
    }
    if (num % 2 == 1) {
        printf("Impar");
    }
    return 0;
}
