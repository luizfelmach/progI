#include <stdio.h>

#define inicio 97
#define fim 122
#define variacao 32

int main() {
    char letra = ' ';
    scanf("%c", &letra);
    if ((int)letra >= inicio && (int)letra <= fim) {
        printf("%c(%d)", letra - variacao, letra - variacao);
    } else if ((int)letra >= inicio - variacao &&
               (int)letra <= fim - variacao) {
        printf("A letra deve ser minuscula!");
    } else {
        printf("Nao e letra!");
    }
    return 0;
}
