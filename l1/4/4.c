#include <math.h>
#include <stdio.h>

#define PI 3.141592

int main() {
    float raio = 0.0, area = 0.0, raioQuando = 0.0;
    scanf("%f", &raio);
    area = PI * powf(raio, 2.0);
    raioQuando = sqrtf(area / (2.0 * PI));
    printf("%.2f %.2f", area, raioQuando);
    return 0;
}
