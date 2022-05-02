#include <stdio.h>

int main() {
    char atual = ' ';
    scanf("%c", &atual);
    printf("RESP:");
    while (1) {
        if (atual == ' ')
            printf("");
        else if (atual == '!' || atual == '.' || atual == '?')
            break;
        else
            printf("%c", atual);
        scanf("%c", &atual);
    }
    printf("%c", atual);
    return 0;
}
