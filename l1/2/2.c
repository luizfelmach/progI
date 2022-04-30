#include <stdio.h>

int main() {
    float alt = 0.0, lar = 0.0;
    scanf("%f %f", &alt, &lar);
    float per = 2 * alt + 2 * lar;
    printf("%.2f", per);
    return 0;
}
