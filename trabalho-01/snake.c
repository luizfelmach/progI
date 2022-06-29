/*
 * Trabalho de ProgI
 *
 * Sobre: Jogo snake em C
 * Autor: Luiz Felipe Machado <luiz.f.machado@edu.ufes.br>
 *
 */

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>

// Constantes globais

#define TAM_MAPA 200
#define CIMA 0
#define DIREITA 1
#define BAIXO 2
#define ESQUERDA 3
const int movimentos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

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
} tMapa;

typedef struct {
    tMapa mapa;
} tJogo;

// Metodos para o tipo mapa

tMapa carregaMapa(char* path);
int ehCabeca(char c);
int linhaDaCabeca(tMapa mapa);
int colunaDaCabeca(tMapa mapa);

// Metodos referentes ao jogo

tJogo iniciaJogo(int argc, char* path);
int cabecaAtualDaCobra(tJogo jogo);
int proximoMovimento(int mov, int cabecaAtual);
tJogo realizaMovimento(tJogo jogo, int mov);
void geraInicializacao(tJogo jogo);
void geraResumo(tJogo jogo);
void geraRanking(tJogo jogo);
void geraEstatistica(tJogo jogo);
void geraHeatMapa(tJogo jogo);

// Funcao principal

int main(int argc, char* argv[]) {
    tJogo jogo = iniciaJogo(argc, argv[1]);
    char mov;

    geraInicializacao(jogo);

    while (scanf("%c", &mov) == 1) {
        jogo = realizaMovimento(jogo, mov);
        scanf("%*c");
    }

    geraResumo(jogo);
    geraRanking(jogo);
    geraEstatistica(jogo);
    geraHeatMapa(jogo);

    return 0;
}

// Metodos para o tipo mapa

tMapa carregaMapa(char* path) {
    int i, j;
    char obj;
    tMapa mapa;
    FILE* arquivo = fopen(path, "r");

    if (!arquivo) {
        printf("Nao foi possivel ler o arquivo %s\n", path);
        exit(0);
    }

    fscanf(arquivo, "%d %d", &mapa.linhas, &mapa.colunas);
    fscanf(arquivo, "%*c");

    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            fscanf(arquivo, "%c", &obj);
            mapa.objs[i][j] = obj;
        }
        fscanf(arquivo, "%*c");
    }

    fclose(arquivo);
    return mapa;
}

int ehCabeca(char c) { return c == '^' || c == '>' || c == 'v' || c == '<'; }

int linhaDaCabeca(tMapa mapa) {
    int i, j;
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (ehCabeca(mapa.objs[i][j])) {
                return i;
            }
        }
    }
    return -1;
}

int colunaDaCabeca(tMapa mapa) {
    int i, j;
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (ehCabeca(mapa.objs[i][j])) {
                return j;
            }
        }
    }
    return -1;
}

// Metodos referentes ao jogo

tJogo iniciaJogo(int argc, char* path) {
    tJogo jogo;

    if (argc == 1) {
        printf(
            "ERRO: O diretorio de arquivos de configuracao nao foi "
            "informado\n");
        exit(0);
    }

    jogo.mapa = carregaMapa(path);

    return jogo;
}

int cabecaAtualDaCobra(tJogo jogo) {
    int i, j;
    char obj;
    for (i = 0; i < jogo.mapa.linhas; i++) {
        for (j = 0; j < jogo.mapa.colunas; j++) {
            obj = jogo.mapa.objs[i][j];
            if (obj == '^') {
                return CIMA;
            } else if (obj == '>') {
                return DIREITA;
            } else if (obj == 'v') {
                return BAIXO;
            } else if (obj == '<') {
                return ESQUERDA;
            }
        }
    }

    return -1;
}

int proximoMovimento(int mov, int cabecaAtual) {
    if (mov == 'c') {
        return cabecaAtual;
    }
    if (mov == 'h') {
        cabecaAtual += 1;
        if (cabecaAtual == 4) {
            cabecaAtual = 0;
        }
    }

    if (mov == 'a') {
        cabecaAtual -= 1;
        if (cabecaAtual == -1) {
            cabecaAtual = 3;
        }
    }

    return cabecaAtual;
}

tJogo realizaMovimento(tJogo jogo, int mov) { return jogo; }

void geraInicializacao(tJogo jogo) {
    int i, j;
    FILE* arquivo = fopen("inicializacao.txt", "w");

    for (i = 0; i < jogo.mapa.linhas; i++) {
        for (j = 0; j < jogo.mapa.colunas; j++) {
            fprintf(arquivo, "%c", jogo.mapa.objs[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    int cabecaL = linhaDaCabeca(jogo.mapa) + 1;
    int cabecaC = colunaDaCabeca(jogo.mapa) + 1;

    fprintf(arquivo, "A cobra comecara o jogo na linha %d e coluna %d\n",
            cabecaL, cabecaC);

    fclose(arquivo);
}

void geraResumo(tJogo jogo) {
    FILE* arquivo = fopen("resumo.txt", "w");
    fclose(arquivo);
}

void geraRanking(tJogo jogo) {
    FILE* arquivo = fopen("ranking.txt", "w");
    fclose(arquivo);
}

void geraEstatistica(tJogo jogo) {
    FILE* arquivo = fopen("estatisticas.txt", "w");
    fclose(arquivo);
}

void geraHeatMapa(tJogo jogo) {
    FILE* arquivo = fopen("heat_map.txt", "w");
    fclose(arquivo);
}
