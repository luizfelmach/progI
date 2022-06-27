/*
 * Trabalho de ProgI
 *
 * Sobre: Jogo snake em C
 * Autor: Luiz Felipe Machado <luiz.f.machado@edu.ufes.br>
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constantes globais
 *
 */

#define TAM_MAPA 200

/*
 * Metodos para o tipo mapa
 *
 *      tMapa carregaMapa(char* path)
 *
 */

typedef struct {
    char objs[TAM_MAPA][TAM_MAPA];
    int linhas, colunas;
} tMapa;

tMapa carregaMapa(char* path);

/*
 *
 * Funcao principal
 *
 */

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        carregaMapa(argv[1]);
    } else {
        printf(
            "ERRO: O diretorio de arquivos de configuracao nao foi "
            "informado\n");
        exit(0);
    }
    return 0;
}

/*
 * Metodos para o tipo mapa
 *
 */

tMapa carregaMapa(char* path) {
    int i, j;
    char obj;
    tMapa m;
    FILE* arquivo = fopen(path, "r");

    if (!arquivo) {
        printf("Nao foi possivel ler o arquivo %s\n", path);
        exit(0);
    }

    fscanf(arquivo, "%d %d\n", &m.linhas, &m.colunas);

    for (i = 0; i < m.linhas; i++) {
        for (j = 0; j < m.colunas; j++) {
            fscanf(arquivo, "%c", &obj);
            m.objs[i][j] = obj;
        }
        fscanf(arquivo, "%*c");
    }

    fclose(arquivo);
    return m;
}
