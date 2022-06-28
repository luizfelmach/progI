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
 * Estruturas para o jogo
 *
 *      tMapa -> Armazena os objetos do mapa
 *      tJogo -> Armazena os tipos referentes ao jogo
 *
 */

typedef struct {
    char objs[TAM_MAPA][TAM_MAPA];
    int linhas, colunas;
    int linhaInicial, colunaInicial;
} tMapa;

typedef struct {
    tMapa mapa;
    int pontuacao;
    int comidas;
    int tamanho;
    int dinheiro;
    int movimento;
} tJogo;

/*
 * Metodos para o tipo mapa
 *
 *      tMapa carregaMapa(char* path)
 *      void inicializaMapa(tMapa m)
 *
 */

tMapa carregaMapa(char* path);
void inicializaMapa(tMapa m);


/*
 * Metodos referentes ao jogo
 *
 */


/*
 *
 * Funcao principal
 *
 */

int main(int argc, char* argv[]) {
    tJogo jogo;
    tMapa mapa;
    if (argc >= 2) {
        mapa = carregaMapa(argv[1]);
    } else {
        printf(
            "ERRO: O diretorio de arquivos de configuracao nao foi "
            "informado\n");
        exit(0);
    }

    inicializaMapa(mapa);

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

    fscanf(arquivo, "%d %d", &m.linhas, &m.colunas);
    fscanf(arquivo, "%*c");

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

void inicializaMapa(tMapa m) {
    int i, j;
    FILE* arquivo = fopen("inicializacao.txt", "w");

    for (i = 0; i < m.linhas; i++) {
        for (j = 0; j < m.colunas; j++) {
            fprintf(arquivo, "%c", m.objs[i][j]);

            if (m.objs[i][j] == '>') {
                m.linhaInicial = i;
                m.colunaInicial = j;
            }
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "A cobra comecara o jogo na linha %d e coluna %d\n",
            m.linhaInicial + 1, m.colunaInicial + 1);

    fclose(arquivo);
}
