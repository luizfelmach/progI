#include <stdio.h>

float to_celsius(float temp) {
    float temp_conv = (temp - 32.0) * 5.0 / 9.0;
    return temp_conv;
}

float to_fahrenheit(float temp) {
    float temp_conv = temp * 9.0 / 5.0 + 32.0;
    return temp_conv;
}

int main() {
    float temp = 0.0;
    char unidade_medida = ' ';
    scanf("%f %c", &temp, &unidade_medida);
    if (unidade_medida == 'c' || unidade_medida == 'C') {
        float temp_conv = to_fahrenheit(temp);
        printf("%.2f (F)", temp_conv);
    } else if (unidade_medida == 'f' || unidade_medida == 'F') {
        float temp_conv = to_celsius(temp);
        printf("%.2f (C)", temp_conv);
    }
    return 0;
}
