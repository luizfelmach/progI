#include <stdio.h>

int main() {
    char atual = ' ';
    scanf("%c", &atual);
    while (1) {
        if ((int)atual >= 97 && (int)atual <= 122)
            printf("%c", (int)atual - 32);
        else if (atual == '!' || atual == '.' || atual == '?')
            break;
        else
            printf("%c", atual);
        scanf("%c", &atual);
    }
    printf("%c", atual);
    return 0;
}
