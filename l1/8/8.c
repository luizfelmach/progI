#include <stdio.h>

#define a 65
#define e 69
#define i 73
#define o 79
#define u 85

int ehVogal(char letra) {
    if ((int)letra == a || (int)letra == a + 32) {
        return 1;
    }
    if ((int)letra == e || (int)letra == e + 32) {
        return 1;
    }
    if ((int)letra == i || (int)letra == i + 32) {
        return 1;
    }
    if ((int)letra == o || (int)letra == o + 32) {
        return 1;
    }
    if ((int)letra == u || (int)letra == u + 32) {
        return 1;
    }
    return 0;
}
int main() {
    char letra = ' ';
    scanf("%c", &letra);
    if (ehVogal(letra)) {
        printf("Vogal");
    } else {
        printf("Nao vogal");
    }
    return 0;
}
