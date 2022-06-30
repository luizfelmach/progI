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
#define TAM_COBRA 200
#define CABECA 0
#define LINHA 0
#define COLUNA 1
#define CIMA 0
#define DIREITA 1
#define BAIXO 2
#define ESQUERDA 3

const char direcoes[4] = {'^', '>', 'v', '<'};
const int movimentos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

/*
 * Estruturas para o jogo
 *
 *      tMapa -> Armazena os objetos do mapa
 *      tCobra -> Armazena o tipo cobra
 *      tJogo -> Armazena os tipos referentes ao jogo
 *
 */

typedef struct {
    char objs[TAM_MAPA][TAM_MAPA];
    int linhas, colunas;
} tMapa;

typedef struct {
    int corpo[TAM_COBRA][2];
    int cauda[2];
    int direcao;
    int tamanho;
} tCobra;

typedef struct {
    tMapa mapa;
    tCobra cobra;
} tJogo;

// Metodos para o tipo mapa

tMapa carregaMapa(char* path);
int ehCabeca(char c);
int linhaDaCabeca(tMapa mapa);
int colunaDaCabeca(tMapa mapa);
void imprimeMapa(tMapa mapa);
tMapa atualizaMapa(tMapa mapa, tCobra cobra);

// Metodos referentes a cobra

tCobra inicializaCobra(int cabecaL, int cabecaC);
tCobra movimentaCobra(tCobra cobra, int movimento);

// Metodos referentes ao jogo

tJogo iniciaJogo(int argc, char* path);
int proximoMovimento(int mov, int direcaoDaCabeca);
tJogo realizaMovimento(tJogo jogo, int movimento);
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

int ehCabeca(char c) {
    int verificacao = c == '^' || c == '>' || c == 'v' || c == '<';
    return verificacao;
}

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

void imprimeMapa(tMapa mapa) {
    int i, j;
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            printf("%c", mapa.objs[i][j]);
        }
        printf("\n");
    }
}

tMapa atualizaMapa(tMapa mapa, tCobra cobra) {
    int i, linha, coluna;
    int linhaDaCauda = cobra.cauda[LINHA];
    int colunaDaCauda = cobra.cauda[COLUNA];
    int l = cobra.corpo[CABECA][LINHA];
    int c = cobra.corpo[CABECA][COLUNA];
    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] != -1) {
            linha = cobra.corpo[i][LINHA];
            coluna = cobra.corpo[i][COLUNA];
            mapa.objs[linha][coluna] = 'o';
        }
    }
    if (linhaDaCauda != -1) {
        mapa.objs[linhaDaCauda][colunaDaCauda] = ' ';
    }
    mapa.objs[l][c] = direcoes[cobra.direcao];
    return mapa;
}

// Metodos referentes a cobra

tCobra inicializaCobra(int cabecaL, int cabecaC) {
    tCobra cobra;
    cobra.tamanho = 1;
    cobra.direcao = 1;
    int i;
    for (i = 0; i < TAM_COBRA; i++) {
        cobra.corpo[i][LINHA] = -1;
        cobra.corpo[i][COLUNA] = -1;
    }
    cobra.corpo[CABECA][LINHA] = cabecaL;
    cobra.corpo[CABECA][COLUNA] = cabecaC;

    return cobra;
}

tCobra movimentaCobra(tCobra cobra, int movimento) {
    int i;
    int auxLinha, auxColuna;
    int linhaAnterior = cobra.corpo[CABECA][LINHA];
    int colunaAnterior = cobra.corpo[CABECA][COLUNA];
    cobra.corpo[CABECA][LINHA] += movimentos[movimento][LINHA];
    cobra.corpo[CABECA][COLUNA] += movimentos[movimento][COLUNA];
    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] != -1) {
            auxLinha = cobra.corpo[i][LINHA];
            auxColuna = cobra.corpo[i][COLUNA];
            cobra.corpo[i][LINHA] = linhaAnterior;
            cobra.corpo[i][COLUNA] = colunaAnterior;
            linhaAnterior = auxLinha;
            colunaAnterior = auxColuna;
        }
    }
    cobra.cauda[LINHA] = linhaAnterior;
    cobra.cauda[COLUNA] = colunaAnterior;
    cobra.direcao = movimento;
    return cobra;
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
    int cabecaL = linhaDaCabeca(jogo.mapa);
    int cabecaC = colunaDaCabeca(jogo.mapa);
    jogo.cobra = inicializaCobra(cabecaL, cabecaC);

    return jogo;
}

int proximoMovimento(int mov, int direcaoDaCabeca) {
    if (mov == 'c') {
        return direcaoDaCabeca;
    }
    if (mov == 'h') {
        direcaoDaCabeca += 1;
        if (direcaoDaCabeca == 4) {
            direcaoDaCabeca = 0;
        }
    }

    if (mov == 'a') {
        direcaoDaCabeca -= 1;
        if (direcaoDaCabeca == -1) {
            direcaoDaCabeca = 3;
        }
    }

    return direcaoDaCabeca;
}

tJogo realizaMovimento(tJogo jogo, int movimento) {

    int realMov = proximoMovimento(movimento, jogo.cobra.direcao);
    jogo.cobra = movimentaCobra(jogo.cobra, realMov);
    jogo.mapa = atualizaMapa(jogo.mapa, jogo.cobra);

    printf("Estado do jogo apos o movimento '%c'\n", movimento);
    imprimeMapa(jogo.mapa);
    printf("\n");
    return jogo;
}

void geraInicializacao(tJogo jogo) {
    int i, j;
    FILE* arquivo = fopen("inicializacao.txt", "w");

    for (i = 0; i < jogo.mapa.linhas; i++) {
        for (j = 0; j < jogo.mapa.colunas; j++) {
            fprintf(arquivo, "%c", jogo.mapa.objs[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    int cabecaL = jogo.cobra.corpo[CABECA][LINHA] + 1;
    int cabecaC = jogo.cobra.corpo[CABECA][COLUNA] + 1;

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
