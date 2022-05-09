#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);
float Opera(float num1, float num2, char operador);

int main() {
    float num1, num2, result = 0;
    char operador;
    scanf("%f %f %c", &num1, &num2, &operador);
    result = Opera(num1, num2, operador);
    while (scanf("%f %c", &num2, &operador) > 0) {
        result = Opera(result, num2, operador);
    }
    printf("%.2f", result);
    return 0;
}

float Opera(float num1, float num2, char operador) {
    switch (operador) {
        case '+':
            return Soma(num1, num2);
            break;
        case '-':
            return Subtracao(num1, num2);
            break;
        case '/':
            return Divisao(num1, num2);
            break;
        case '*':
            return Multiplicacao(num1, num2);
            break;
        default:
            break;
    }
}

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}
