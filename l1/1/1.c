#include <math.h>
#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    float res = 0.0;
    scanf("%d %d", &num1, &num2);
    res = sqrtf(num1) + sqrtf(num2);
    printf("%.2f", res);
    return 0;
}
