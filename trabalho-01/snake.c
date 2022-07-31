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

#define JOGANDO 0
#define PERDEU 1
#define VENCEU 2

const char direcoes[4] = {'^', '>', 'v', '<'};
const int movimentos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

/*
 * Estruturas para o jogo
 *
 *      tMapa -> Armazena os objetos do mapa
 *      tHeatMapa -> Armazena o tipo HeatMapa
 *      tCobra -> Armazena o tipo cobra
 *      tJogo -> Armazena os tipos referentes ao jogo
 *      tEstatisticas -> Armazena as estatisticas do jogo
 *
 */

typedef struct {
    char objs[TAM_MAPA][TAM_MAPA];
    int linhas, colunas;
    char direcoes[4];
    char vazio;
    char parede;
    char comida;
    char dinheiro;
    char tunel;
    char cobraMorta;
    char corpo;
} tMapa;

typedef struct {
    char objs[TAM_MAPA][TAM_MAPA];
    int linhas, colunas;
} tHeatMapa;

typedef struct {
    int totalMovimentos;
    int semPontuar;
    int movimentosDirecionados[4];
} tEstatisticas;

typedef struct {
    int corpo[TAM_COBRA][2];
    int cauda[2];
    int direcao;
    int tamanho;
} tCobra;

typedef struct {
    tMapa mapa;
    tHeatMapa heatMapa;
    tEstatisticas estatisticas;
    tCobra cobra;
    int pontuacao;
    int status;
} tJogo;

// Metodos para o tipo mapa

tMapa carregaMapa(char* path);
int ehCabeca(tMapa mapa, char c);
int ehCorpo(tMapa mapa, char c);
int linhaDaCabeca(tMapa mapa);
int colunaDaCabeca(tMapa mapa);
void imprimeMapa(tMapa mapa);
void imprimeMapaCobraMorta(tMapa mapa);
tMapa atualizaMapa(tMapa mapa, tCobra cobra);
char objetoDaCabeca(tMapa, tCobra);
int temComida(tMapa mapa);

// Metodos para o tipo heatMapa

tHeatMapa inicializaHeatMapa(char* path);
tHeatMapa rastreiaMovimento(tHeatMapa heatMapa, tCobra cobra);

// Metodos para o tipo heatMapa
tEstatisticas inicializaEstatisticas();
tEstatisticas contaMovimento(tEstatisticas estatisticas);
tEstatisticas contaMovimentoSemPontuar(tEstatisticas estatisticas);
tEstatisticas contaMovimentoDirecionado(tEstatisticas estatisticas, int movimento);


// Metodos referentes a cobra

tCobra inicializaCobra(tMapa mapa);
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
int terminouJogo(tJogo jogo);
void geraInicializacao(tJogo jogo);
void geraResumo(tJogo jogo);
void geraRanking(tJogo jogo);
void geraEstatistica(tJogo jogo);
void geraHeatMapa(tJogo jogo);

// Funcao principal

tJogo jogo;

int main(int argc, char* argv[]) {
    jogo = iniciaJogo(argc, argv[1]);
    char movimento;

    geraInicializacao(jogo);

    while (scanf("%c", &movimento) == 1) {
        system("clear");
        jogo = realizaMovimento(jogo, movimento);
        if (terminouJogo(jogo)) {
            break;
        }
        scanf("%*c");
        //usleep(70000);
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
    tMapa mapa = {
        .direcoes = {'^', '>', 'v', '<'},
        .vazio = ' ',
        .parede = '#',
        .comida = '*',
        .dinheiro = '$',
        .tunel = '@',
        .cobraMorta = 'X',
        .corpo = 'o'
    };
    FILE* arquivo = fopen(path, "r");

    // Verifica se o arquivo existe
    if (!arquivo) {
        printf("Nao foi possivel ler o arquivo %s\n", path);
        exit(0);
    }

    // Le as dimensoes do mapa
    fscanf(arquivo, "%d %d", &mapa.linhas, &mapa.colunas);
    fscanf(arquivo, "%*c");

    // Carrega o mapa para a estrutura
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

int ehCabeca(tMapa mapa, char c) {
    int i;
    for (i = 0; i < 4; i++) {
        if (mapa.direcoes[i] == c) {
            return 1;
        }
    }
    return 0;
}

int ehCorpo(tMapa mapa, char c) {
    int verificacao = c == mapa.corpo;
    return verificacao;
}

int linhaDaCabeca(tMapa mapa) {
    int i, j;

    // Percorre o mapa para achar a cabeca e retorna a linha
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (ehCabeca(mapa, mapa.objs[i][j])) {
                return i;
            }
        }
    }

    return -1;
}

int colunaDaCabeca(tMapa mapa) {
    int i, j;

    // Percorre o mapa para achar a cabeca e retorna a coluna
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (ehCabeca(mapa, mapa.objs[i][j])) {
                return j;
            }
        }
    }

    return -1;
}

void imprimeMapa(tMapa mapa) {
    int i, j;

    // Percorre e imprime o mapa
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            printf("%c", mapa.objs[i][j]);
        }
        printf("\n");
    }
}

void imprimeMapaCobraMorta(tMapa mapa) {
    int i, j;
    char objeto;

    // Percorre e imprime o mapa
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            objeto = mapa.objs[i][j];
            if (ehCabeca(mapa, objeto) || ehCorpo(mapa, objeto)) {
                printf("%c", mapa.cobraMorta);
            } else {
                printf("%c", objeto);
            }
        }
        printf("\n");
    }
}

tMapa atualizaMapa(tMapa mapa, tCobra cobra) {
    int i, linha, coluna;

    // Pega a cauda da cobra
    int cauda[2] = {cobra.cauda[LINHA], cobra.cauda[COLUNA]};

    // Pega a coordenada da cabeca
    int l = cobra.corpo[CABECA][LINHA];
    int c = cobra.corpo[CABECA][COLUNA];

    // Atualiza o corpo para onde estava a cabeca
    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] != -1) {
            linha = cobra.corpo[i][LINHA];
            coluna = cobra.corpo[i][COLUNA];
            mapa.objs[linha][coluna] = 'o';
        }
    }

    // Se a cauda existir, apague
    if (cauda[LINHA] != -1) {
        mapa.objs[cauda[LINHA]][cauda[COLUNA]] = ' ';
    }

    // Atualiza a direcao da cabeca
    mapa.objs[l][c] = direcoes[cobra.direcao];

    return mapa;
}

char objetoDaCabeca(tMapa mapa, tCobra cobra) {
    // Pega as coordenadas da cabeca
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    // Retorna o objeto da cabeca
    char objeto = mapa.objs[cabeca[LINHA]][cabeca[COLUNA]];
    return objeto;
}

int temComida(tMapa mapa) {
    int i, j;
    int quantidadeDeComida = 0;

    // Percorre o mapa retorna a quantidade de comida
    for (i = 0; i < mapa.linhas; i++) {
        for (j = 0; j < mapa.colunas; j++) {
            if (mapa.objs[i][j] == mapa.comida) {
                quantidadeDeComida++;
            }
        }
    }

    return quantidadeDeComida;
}

// Metodos para o tipo heatMapa

tHeatMapa inicializaHeatMapa(char* path) {
    int i, j;
    tHeatMapa heatMapa;
    FILE* arquivo = fopen(path, "r");

    // Verifica se o arquivo existe
    if (!arquivo) {
        printf("Nao foi possivel ler o arquivo %s\n", path);
        exit(0);
    }

    // Le as dimensoes do mapa
    fscanf(arquivo, "%d %d", &heatMapa.linhas, &heatMapa.colunas);

    // Zera todos os valores do mapa
    for (i = 0; i < heatMapa.linhas; i++) {
        for (j = 0; j < heatMapa.colunas; j++) {
            heatMapa.objs[i][j] = 0;
        }
    }

    fclose(arquivo);
    return heatMapa;
}

tHeatMapa rastreiaMovimento(tHeatMapa heatMapa, tCobra cobra) {
    // Pega as coordenadas da cabeca da cobra
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};
    heatMapa.objs[cabeca[LINHA]][cabeca[COLUNA]] += 1;

    return heatMapa;
}

// Metodos para o tipo heatMapa

tEstatisticas inicializaEstatisticas() {
    tEstatisticas estatisticas = {
        .totalMovimentos = 0,
        .semPontuar = 0,
        .movimentosDirecionados = {0, 0, 0, 0}
    };

    return estatisticas;
}

tEstatisticas contaMovimento(tEstatisticas estatisticas) {
    estatisticas.totalMovimentos += 1;
    return estatisticas;
}

tEstatisticas contaMovimentoSemPontuar(tEstatisticas estatisticas) {
    estatisticas.semPontuar += 1;
    return estatisticas;
}

tEstatisticas contaMovimentoDirecionado(tEstatisticas estatisticas, int movimento) {
    estatisticas.movimentosDirecionados[movimento] += 1;
    return estatisticas;
}

// Metodos referentes a cobra

tCobra inicializaCobra(tMapa mapa) {
    int i;

    // Coordenadas da cabeca
    int cabecaL = linhaDaCabeca(mapa);
    int cabecaC = colunaDaCabeca(mapa);

    // Inicializa cobra com tamanho 1, direcao para direita e as coordenadas da
    // cabeca
    tCobra cobra = {
        .tamanho = 1, .direcao = DIREITA, .corpo[0] = {cabecaL, cabecaC}};

    // Define o resto do corpo como inexistente
    for (i = 1; i < TAM_COBRA; i++) {
        cobra.corpo[i][LINHA] = -1;
        cobra.corpo[i][COLUNA] = -1;
    }

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

    // Atualiza a cauda e a ultima direcao
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

    // Pega as coordenadas da cabeca
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    // Percorre o corpo e ve se a cabeca colidiu com algun deles
    for (i = 1; i < TAM_COBRA; i++) {
        if (cobra.corpo[i][LINHA] == cabeca[LINHA] &&
            cobra.corpo[i][COLUNA] == cabeca[COLUNA]) {
            return 1;
        }
    }

    return colisao;
}

int passouDoMapa(tMapa mapa, tCobra cobra) {
    // Pega as coordenadas da cabeca
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    // Retorna verdadeiro caso tenha passado do mapa
    if (cabeca[LINHA] < 0 || cabeca[COLUNA] < 0) {
        return 1;
    }
    if (cabeca[LINHA] >= mapa.linhas || cabeca[COLUNA] >= mapa.colunas) {
        return 1;
    }

    return 0;
}

tCobra teleportaCobra(tMapa mapa, tCobra cobra) {
    // Pega as coordenadas da cabeca
    int cabeca[2] = {cobra.corpo[CABECA][LINHA], cobra.corpo[CABECA][COLUNA]};

    // Teleporta a cabeca da cobra para o outro lado do mapa
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
    // Verifica se foi passado um arquivo
    if (argc == 1) {
        printf(
            "ERRO: O diretorio de arquivos de configuracao nao foi "
            "informado\n");
        exit(0);
    }

    // Inicia o jogo com as variaveis resetadas
    tJogo jogo = {.mapa = carregaMapa(path),
                  .heatMapa = inicializaHeatMapa(path),
                  .estatisticas = inicializaEstatisticas(),
                  .cobra = inicializaCobra(jogo.mapa),
                  .pontuacao = 0,
                  .status = JOGANDO};

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
            direcaoDaCabeca = CIMA;
        }
    }

    if (movimento == 'a') {
        direcaoDaCabeca -= 1;
        if (direcaoDaCabeca == -1) {
            direcaoDaCabeca = ESQUERDA;
        }
    }

    return direcaoDaCabeca;
}

tJogo realizaMovimento(tJogo jogo, int movimento) {
    jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
    jogo.cobra = movimentaCobra(jogo.cobra, movimento);

    if (passouDoMapa(jogo.mapa, jogo.cobra)) {
        jogo.cobra = teleportaCobra(jogo.mapa, jogo.cobra);
    }

    char objeto = objetoDaCabeca(jogo.mapa, jogo.cobra);

    if (objeto == jogo.mapa.parede || colisaoComACobra(jogo.cobra)) {
        jogo.status = PERDEU;
        jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
    }
    if (objeto == jogo.mapa.comida) {
        jogo.cobra = aumentaCobra(jogo.cobra);
        jogo = aumentaPontuacao(jogo, 1);
    }
    if (objeto == jogo.mapa.dinheiro) {
        jogo = aumentaPontuacao(jogo, 10);
    }
    if (objeto != jogo.mapa.dinheiro && objeto != jogo.mapa.comida) {
        jogo.estatisticas = contaMovimentoSemPontuar(jogo.estatisticas);
    }

    jogo.estatisticas = contaMovimento(jogo.estatisticas);
    jogo.mapa = atualizaMapa(jogo.mapa, jogo.cobra);

    if (!temComida(jogo.mapa)) {
        jogo.status = VENCEU;
        jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
    }

    estadoAtual(jogo, movimento);

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
    printf("\n");
    printf("Estado do jogo apos o movimento '%c':\n", movimento);
    if (jogo.status == JOGANDO) {
        imprimeMapa(jogo.mapa);
        printf("Pontuacao: %d", jogo.pontuacao);
    }
    if (jogo.status == VENCEU) {
        imprimeMapa(jogo.mapa);
        printf("Pontuacao: %d\n", jogo.pontuacao);
        venceJogo(jogo);
    }
    if (jogo.status == PERDEU) {
        imprimeMapaCobraMorta(jogo.mapa);
        printf("Pontuacao: %d\n", jogo.pontuacao);
        perdeJogo(jogo);
    }
    printf("\n");
}

int terminouJogo(tJogo jogo) {
    return jogo.status == PERDEU || jogo.status == VENCEU;
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
    fprintf(arquivo, "Numero de movimentos: %d\n", jogo.estatisticas.totalMovimentos);
    fprintf(arquivo, "Numero de movimentos sem pontuar: %d\n", jogo.estatisticas.semPontuar);
    fclose(arquivo);
}

void geraHeatMapa(tJogo jogo) {
    int i, j;
    FILE* arquivo = fopen("heatmap.txt", "w");

    for (i = 0; i < jogo.heatMapa.linhas; i++) {
        for (j = 0; j < jogo.heatMapa.colunas; j++) {
            fprintf(arquivo, "%d", jogo.heatMapa.objs[i][j]);
            if (j < jogo.heatMapa.colunas - 1) {
                fprintf(arquivo, " ");
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}
