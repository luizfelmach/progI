#include <math.h>
#include <stdio.h>

void s1() {
    double acumulador = 0.0;
    int i;
    for (i = 1; i < 51; i++) {
        double num = i * 2 - 1;
        acumulador += (double)num / (double)i;
    }
    printf("%.6lf", acumulador);
}

void s2() {
    double acumulador = 0.0;
    int i;
    for (i = 1; i < 51; i++) {
        acumulador += (double)pow(2, i) / (double)(51 - i);
    }
    printf("%.6lf", acumulador);
}

void s3() {
    double acumulador = 0.0;
    int i;
    for (i = 1; i < 11; i++) {
        acumulador += (double)i / (double)pow(i, 2);
    }
    printf("%.6lf", acumulador);
}

int main() {
    int s = 0;
    scanf("%d", &s);
    if (s == 1)
        s1();
    else if (s == 2)
        s2();
    else
        s3();
    return 0;
}
