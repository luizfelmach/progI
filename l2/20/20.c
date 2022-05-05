#include <math.h>
#include <stdio.h>

float valorY(int x, float a, float b, float c, float d) {
    float y = a * powf(x, 3) + b * powf(x, 2) + c * x + d;
    return y;
}

int main() {
    float a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    int e = 0, f = 0;
    int achouPico = 0, achouVale = 0;
    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);
    float yAtual = 0.0, yPosterior = 0.0, yAnterior = 0.0;
    int i;
    for (i = e; i <= f; i++) {
        yAnterior = valorY(i - 1, a, b, c, d);
        yAtual = valorY(i, a, b, c, d);
        yPosterior = valorY(i + 1, a, b, c, d);
        if (yAtual > yAnterior && yAtual > yPosterior) {
            achouPico++;
            printf("Pico em x=%d\n", i);
        }
        if (yAtual < yAnterior && yAtual < yPosterior) {
            achouVale++;
            printf("Vale em x=%d\n", i);
        }
    }
    if (!achouPico) printf("Nao ha pico\n");
    if (!achouVale) printf("Nao ha vale");
    return 0;
}
