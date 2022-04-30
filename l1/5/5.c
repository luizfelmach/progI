#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    scanf("%d %d", &num1, &num2);
    if (num1 > num2) {
        printf("N1 = %d", num1);
    } else if (num2 > num1) {
        printf("N2 = %d", num2);
    } else {
        printf("N1 = N2");
    }
    return 0;
}
