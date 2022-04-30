#include <stdio.h>

int main() {
    float x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    float lar = x2 - x1;
    float alt = y2 -y1;
    float per = 2 * lar + 2 * alt;
    printf("%.2f", per);
    return 0;
}
