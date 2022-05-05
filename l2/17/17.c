#include <stdio.h>

void codificar(int n) {
    char atual;
    scanf("%c", &atual);
    while (1) {
        scanf("%c", &atual);
        if (atual >= 'a' && atual <= 'z') {
            int inc = atual + (n % 26);
            if (inc > 122) inc = 97 + (inc % 123);
            printf("%c", inc);
        } else {
            printf("%c", atual);
        }
        if (atual == '.') break;
    }
}
void decodificar(int n) {
    char atual;
    scanf("%c", &atual);
    while (1) {
        scanf("%c", &atual);
        if (atual >= 'a' && atual <= 'z') {
            int inc = atual - (n % 26);
            if (inc < 97) inc = 122 - (96 % inc);
            printf("%c", inc);
        } else {
            printf("%c", atual);
        }
        if (atual == '.') break;
    }
}

int main() {
    int opt = 0, n = 0;
    scanf("%d %d", &opt, &n);
    switch (opt) {
        case 1:
            codificar(n);
            break;
        case 2:
            decodificar(n);
            break;
        default:
            printf("Operacao invalida.");
    }
    return 0;
}
