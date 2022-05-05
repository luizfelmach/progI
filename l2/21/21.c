#include <stdio.h>

int main() {
    int qtd = 0;
    scanf("%d", &qtd);
    int nums[qtd];
    int i;
    for (i = 0; i < qtd; i++) {
        scanf("%d", &nums[i]);
    }

    char atual;
    int num = 0;
    int lerChar = 1;
    int aspas = 0;
    scanf("%c", &atual);
    while (1) {
        if (lerChar) {
            scanf("%c", &atual);
            if (atual != '"' && atual != '%') {
                printf("%c", atual);
            } else if (atual == '%') {
                lerChar = 0;
            } else if (atual == '"') {
                aspas++;
                if (aspas == 2) {
                    break;
                }
            }
        } else {
            scanf("%d", &num);
            if (num > qtd || num < 1)
                printf("ERRO");
            else
                printf("%d", nums[num - 1]);
            lerChar = 1;
        }
    }
    return 0;
}
