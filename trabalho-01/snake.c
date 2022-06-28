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
    int comida;
    int tamanho;
    int dinheiro;
    int movimento;
} tJogo;

/*
 * Metodos para o tipo mapa
 *
 */

tMapa carregaMapa(char* path);
tMapa posicoesIniciais(tMapa mapa);
void inicializaMapa(tMapa mapa);

/*
 * Metodos referentes ao jogo
 *
 */

tJogo iniciaJogo(int argc, char* path);

/*
 *
 * Funcao principal
 *
 */

int main(int argc, char* argv[]) {
    tJogo jogo = iniciaJogo(argc, argv[1]);

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

tMapa posicoesIniciais(tMapa mapa) {
    int i, j;
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (mapa.objs[i][j] == '>') {
                mapa.linhaInicial = i;
                mapa.colunaInicial = j;
            }
        }
    }

    return mapa;
}

void inicializaMapa(tMapa mapa) {
    int i, j;
    FILE* arquivo = fopen("inicializacao.txt", "w");

    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            fprintf(arquivo, "%c", mapa.objs[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "A cobra comecara o jogo na linha %d e coluna %d\n",
            mapa.linhaInicial + 1, mapa.colunaInicial + 1);

    fclose(arquivo);
}

/*
 * Metodos referentes ao jogo
 *
 */

tJogo iniciaJogo(int argc, char* path) {
    tJogo jogo;

    if (argc == 1) {
        printf(
            "ERRO: O diretorio de arquivos de configuracao nao foi "
            "informado\n");
        exit(0);
    }

    jogo.mapa = carregaMapa(path);
    jogo.mapa = posicoesIniciais(jogo.mapa);

    inicializaMapa(jogo.mapa);

    return jogo;
}
