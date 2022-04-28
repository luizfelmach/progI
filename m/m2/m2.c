#include <stdio.h>

int main() {
    float num = 0.0;
    scanf("%f", &num);
    int INT = (int)num;
    float REAL = num - (float)INT;
    printf("INTEIRO:%d,REAL:%.2f", INT, REAL);
    return 0;
}
