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
#define VAZIO ' '
#define PAREDE '#'
#define COMIDA '*'
#define DINHEIRO '$'
#define TUNEL '@'

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
    int pontuacao;
} tJogo;

// Metodos para o tipo mapa

tMapa carregaMapa(char* path);
int ehCabeca(char c);
int linhaDaCabeca(tMapa mapa);
int colunaDaCabeca(tMapa mapa);
void imprimeMapa(tMapa mapa);
tMapa atualizaMapa(tMapa mapa, tCobra cobra);
char objetoDaCabeca(tMapa, tCobra);
int temComida(tMapa mapa);

// Metodos referentes a cobra

tCobra inicializaCobra(int cabecaL, int cabecaC);
tCobra movimentaCobra(tCobra cobra, int movimento);
tCobra aumentaCobra(tCobra cobra);
int colisaoComACobra(tCobra cobra);
int passouDoMapa(tMapa mapa, tCobra cobra);
tCobra teleportaCobra(tMapa mapa, tCobra cobra);

// Metodos referentes ao jogo

tJogo iniciaJogo(int argc, char* path);
tJogo aumentaPontuacao(tJogo jogo, int quantidade);
int proximaDirecao(int movimento, int direcaoDaCabeca);
tJogo realizaMovimento(tJogo jogo, int movimento);
void perdeJogo(tJogo jogo);
void venceJogo(tJogo jogo);
void estadoAtual(tJogo jogo, int movimento);
void geraInicializacao(tJogo jogo);
void geraResumo(tJogo jogo);
void geraRanking(tJogo jogo);
void geraEstatistica(tJogo jogo);
void geraHeatMapa(tJogo jogo);

// Funcao principal

int main(int argc, char* argv[]) {
    tJogo jogo = iniciaJogo(argc, argv[1]);
    char movimento;

    geraInicializacao(jogo);

    while (scanf("%c", &movimento) == 1) {
        jogo = realizaMovimento(jogo, movimento);
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

char objetoDaCabeca(tMapa mapa, tCobra cobra) {
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};
    char objeto = mapa.objs[cabeca[LINHA]][cabeca[COLUNA]];
    return objeto;
}

int temComida(tMapa mapa) {
    int i, j;
    int quantidadeDeComida = 0;
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (mapa.objs[i][j] == COMIDA) {
                quantidadeDeComida++;
            }
        }
    }
    return quantidadeDeComida;
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
    int i, aux[2];

    // Pega a nova direcao da cabeca de acordo com o movimento
    movimento = proximaDirecao(movimento, cobra.direcao);

    // Armazena a cauda ou uma parte do corpo anterior ate chegar na cauda
    int cauda[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    // Faz o movimento da cabeca da cobra
    cobra.corpo[CABECA][LINHA] += movimentos[movimento][LINHA];
    cobra.corpo[CABECA][COLUNA] += movimentos[movimento][COLUNA];

    // Movimenta o restante do corpo
    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] != -1) {
            aux[LINHA] = cobra.corpo[i][LINHA];
            aux[COLUNA] = cobra.corpo[i][COLUNA];
            cobra.corpo[i][LINHA] = cauda[LINHA];
            cobra.corpo[i][COLUNA] = cauda[COLUNA];
            cauda[LINHA] = aux[LINHA];
            cauda[COLUNA] = aux[COLUNA];
        }
    }

    // Armazena a cauda e a ultima direcao
    cobra.cauda[LINHA] = cauda[LINHA];
    cobra.cauda[COLUNA] = cauda[COLUNA];
    cobra.direcao = movimento;

    return cobra;
}

tCobra aumentaCobra(tCobra cobra) {
    // Adiciona um corpo na cauda
    cobra.corpo[cobra.tamanho][LINHA] = cobra.cauda[LINHA];
    cobra.corpo[cobra.tamanho][COLUNA] = cobra.cauda[COLUNA];

    // Coloca a cauda como inexistente e aumenta o tamanho
    cobra.cauda[LINHA] = -1;
    cobra.cauda[COLUNA] = -1;
    cobra.tamanho++;
    return cobra;
}

int colisaoComACobra(tCobra cobra) {
    int colisao = 0, i;

    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] == cabeca[LINHA] &&
            cobra.corpo[i][COLUNA] == cabeca[COLUNA]) {
            return 1;
        }
    }

    return colisao;
}

int passouDoMapa(tMapa mapa, tCobra cobra) {
    int passouDoMapa = 0;
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    if (cabeca[LINHA] < 0 || cabeca[COLUNA] < 0) {
        return 1;
    }
    if (cabeca[LINHA] >= mapa.linhas || cabeca[COLUNA] >= mapa.colunas) {
        return 1;
    }

    return passouDoMapa;
}

tCobra teleportaCobra(tMapa mapa, tCobra cobra) {
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    if (cabeca[LINHA] < 0) {
        cobra.corpo[CABECA][LINHA] = mapa.linhas - 1;
    }
    if (cabeca[COLUNA] < 0) {
        cobra.corpo[CABECA][COLUNA] = mapa.colunas - 1;
    }
    if (cabeca[LINHA] >= mapa.linhas) {
        cobra.corpo[CABECA][LINHA] = 0;
    }
    if (cabeca[COLUNA] >= mapa.colunas) {
        cobra.corpo[CABECA][COLUNA] = 0;
    }

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

tJogo aumentaPontuacao(tJogo jogo, int quantidade) {
    jogo.pontuacao += quantidade;
    return jogo;
}

int proximaDirecao(int movimento, int direcaoDaCabeca) {
    if (movimento == 'c') {
        return direcaoDaCabeca;
    }
    if (movimento == 'h') {
        direcaoDaCabeca += 1;
        if (direcaoDaCabeca == 4) {
            direcaoDaCabeca = 0;
        }
    }

    if (movimento == 'a') {
        direcaoDaCabeca -= 1;
        if (direcaoDaCabeca == -1) {
            direcaoDaCabeca = 3;
        }
    }

    return direcaoDaCabeca;
}

tJogo realizaMovimento(tJogo jogo, int movimento) {
    jogo.cobra = movimentaCobra(jogo.cobra, movimento);

    if (passouDoMapa(jogo.mapa, jogo.cobra)) {
        jogo.cobra = teleportaCobra(jogo.mapa, jogo.cobra);
    }

    char objeto = objetoDaCabeca(jogo.mapa, jogo.cobra);

    if (objeto == PAREDE || colisaoComACobra(jogo.cobra)) {
        perdeJogo(jogo);
        exit(0);
    }
    if (objeto == COMIDA) {
        jogo.cobra = aumentaCobra(jogo.cobra);
        jogo = aumentaPontuacao(jogo, 1);
    }
    if (objeto == DINHEIRO) {
        jogo = aumentaPontuacao(jogo, 10);
    }

    jogo.mapa = atualizaMapa(jogo.mapa, jogo.cobra);

    estadoAtual(jogo, movimento);

    if (!temComida(jogo.mapa)) {
        venceJogo(jogo);
    }
    return jogo;
}

void perdeJogo(tJogo jogo) {
    printf("Game over!\n");
    printf("Pontuacao final: %d", jogo.pontuacao);
}

void venceJogo(tJogo jogo) {
    printf("Voce venceu!\n");
    printf("Pontuacao final: %d", jogo.pontuacao);
}

void estadoAtual(tJogo jogo, int movimento) {
    printf("Estado do jogo apos o movimento '%c':\n", movimento);
    imprimeMapa(jogo.mapa);
    printf("Pontuacao: %d\n", jogo.pontuacao);
    printf("\n");
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
