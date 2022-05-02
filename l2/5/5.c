#include <math.h>
#include <stdio.h>

int main() {
    int n = 0;
    float somatorio = 0.0, pi = 0.0;
    scanf("%d", &n);
    int k;
    for (k = 1; k <= n; k++) {
        float parte = 6.0 / powf(k, 2.0);
        somatorio += parte;
    }
    pi = sqrtf(somatorio);
    printf("%.6f", pi);
    return 0;
}
