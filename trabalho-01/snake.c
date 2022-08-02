/*
 * Trabalho de ProgI
 *
 * Sobre: Jogo snake em C
 * Autor: Luiz Felipe Machado <luiz.f.machado@edu.ufes.br>
 *
 */

// Bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constantes globais

#define TAM_MAPA 200
#define TAM_COBRA 200
#define TAM_DIRETORIO 1010

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

#define SAIDA_DIR "/saida"
#define MAPA_DIR "/mapa.txt"
#define INICIALIZACAO_DIR "/inicializacao.txt"
#define RESUMO_DIR "/resumo.txt"
#define RANKING_DIR "/ranking.txt"
#define ESTATISTICAS_DIR "/estatisticas.txt"
#define HEATMAPA_DIR "/heatmap.txt"


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
 *      tRanking -> Armazena o tipo ranking
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
  int pontos[TAM_MAPA * TAM_MAPA][3];
  int tamanho;
} tRanking;

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
  tRanking ranking;
  tCobra cobra;
  char diretorio[TAM_DIRETORIO];
  int numeroDaJogada;
  int pontuacao;
  int status;
} tJogo;

// Metodos para o tipo mapa

tMapa carregaMapa(char *diretorio);
int ehCabeca(tMapa mapa, char c);
int ehCorpo(tMapa mapa, char c);
int linhaDaCabeca(tMapa mapa);
int colunaDaCabeca(tMapa mapa);
void imprimeMapa(tMapa mapa);
void imprimeMapaCobraMorta(tMapa mapa);
tMapa atualizaMapa(tMapa mapa, tCobra cobra);
char objetoDaCabeca(tMapa, tCobra);
int temComida(tMapa mapa);

// Metodos para o resumo

void resumeGerouDinheiro(tJogo jogo, int movimento);
void resumeCrescimentoCobraSemTerminar(tJogo jogo, int movimento);
void resumeCrescimentoCobraTerminandoJogo(tJogo jogo, int movimento);
void resumeFimDeJogoPorColisao(tJogo jogo, int movimento);

// Metodos para o tipo heatMapa

tHeatMapa inicializaHeatMapa(char *diretorio);
tHeatMapa rastreiaMovimento(tHeatMapa heatMapa, tCobra cobra);

// Metodos para o tipo estatisticas
tEstatisticas inicializaEstatisticas();
tEstatisticas contaMovimento(tEstatisticas estatisticas);
tEstatisticas contaMovimentoSemPontuar(tEstatisticas estatisticas);
tEstatisticas contaMovimentoDirecionado(tEstatisticas estatisticas,
                                        int movimento);

// Metodos para o tipo estatisticas

tRanking inicializaRanking();
tRanking atualizaRanking(tJogo jogo);
tRanking ordenaRanking(tJogo jogo);

// Metodos referentes a cobra

tCobra inicializaCobra(tMapa mapa);
tCobra movimentaCobra(tCobra cobra, int movimento);
tCobra aumentaCobra(tCobra cobra);
int colisaoComACobra(tCobra cobra);
int passouDoMapa(tMapa mapa, tCobra cobra);
tCobra teleportaCobra(tMapa mapa, tCobra cobra);

// Metodos referentes ao jogo

tJogo iniciaJogo(int argc, char *diretorio);
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

int main(int argc, char *argv[]) {
  tJogo jogo = iniciaJogo(argc, argv[1]);
  char movimento;

  geraInicializacao(jogo);

  //FILE *temp = fopen("./saida/resumo.txt", "w");
  //fclose(temp);

  while (scanf("%c", &movimento) == 1) {
    // system("clear");
    jogo = realizaMovimento(jogo, movimento);
    if (terminouJogo(jogo)) {
      break;
    }
    scanf("%*c");
    // usleep(70000);
  }

  // geraResumo(jogo);
  geraRanking(jogo);
  geraEstatistica(jogo);
  geraHeatMapa(jogo);

  return 0;
}

// Metodos para o tipo mapa

tMapa carregaMapa(char *diretorio) {
  int i, j;
  char obj, path[TAM_DIRETORIO*2] = "";
  tMapa mapa = {.direcoes = {'^', '>', 'v', '<'},
                .vazio = ' ',
                .parede = '#',
                .comida = '*',
                .dinheiro = '$',
                .tunel = '@',
                .cobraMorta = 'X',
                .corpo = 'o'};

  strcat(path, diretorio);
  strcat(path, MAPA_DIR);

  FILE *arquivo = fopen(path, "r");

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

// Metodos para o resumo

void resumeGerouDinheiro(tJogo jogo, int movimento) {
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, RESUMO_DIR);

  FILE *arquivo = fopen(path, "a");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  fprintf(arquivo, "Movimento %d (%c) gerou dinheiro\n", jogo.numeroDaJogada,
          movimento);
  fclose(arquivo);
}

void resumeCrescimentoCobraSemTerminar(tJogo jogo, int movimento) {
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, RESUMO_DIR);

  FILE *arquivo = fopen(path, "a");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  fprintf(arquivo, "Movimento %d (%c) fez a cobra crescer para o tamanho %d\n",
          jogo.numeroDaJogada, movimento, jogo.cobra.tamanho);
  fclose(arquivo);
}

void resumeCrescimentoCobraTerminandoJogo(tJogo jogo, int movimento) {
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, RESUMO_DIR);

  FILE *arquivo = fopen(path, "a");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  fprintf(arquivo,
          "Movimento %d (%c) fez a cobra crescer para o tamanho %d, terminando "
          "o jogo\n",
          jogo.numeroDaJogada, movimento, jogo.cobra.tamanho);
  fclose(arquivo);
}

void resumeFimDeJogoPorColisao(tJogo jogo, int movimento) {
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, RESUMO_DIR);

  FILE *arquivo = fopen(path, "a");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  fprintf(arquivo,
          "Movimento %d (%c) resultou no fim de jogo por conta de colisao\n",
          jogo.numeroDaJogada, movimento);
  fclose(arquivo);
}

// Metodos para o tipo heatMapa

tHeatMapa inicializaHeatMapa(char *diretorio) {
  int i, j;
  tHeatMapa heatMapa;

  char path[TAM_DIRETORIO*2] = "";

  strcat(path, diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, HEATMAPA_DIR);

  FILE *arquivo = fopen(path, "r");

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

// Metodos para o tipo estatisticas

tEstatisticas inicializaEstatisticas() {
  tEstatisticas estatisticas = {.totalMovimentos = 0,
                                .semPontuar = 0,
                                .movimentosDirecionados = {0, 0, 0, 0}};

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

tEstatisticas contaMovimentoDirecionado(tEstatisticas estatisticas,
                                        int movimento) {
  estatisticas.movimentosDirecionados[movimento] += 1;
  return estatisticas;
}

// Metodos para o tipo estatisticas

tRanking inicializaRanking() {
  tRanking ranking = {.tamanho = 0};
  return ranking;
}

tRanking atualizaRanking(tJogo jogo) {
  int i;
  int linhaCabeca = jogo.cobra.corpo[CABECA][LINHA];
  int colunaCabeca = jogo.cobra.corpo[CABECA][COLUNA];

  for (i = 0; i < jogo.ranking.tamanho; i++) {
    if (jogo.ranking.pontos[i][LINHA] == linhaCabeca &&
        jogo.ranking.pontos[i][COLUNA] == colunaCabeca) {
      jogo.ranking.pontos[i][2] += 1;
      return jogo.ranking;
    }
  }

  jogo.ranking.pontos[jogo.ranking.tamanho][LINHA] = linhaCabeca;
  jogo.ranking.pontos[jogo.ranking.tamanho][COLUNA] = colunaCabeca;
  jogo.ranking.pontos[jogo.ranking.tamanho][2] = 1;
  jogo.ranking.tamanho += 1;

  return jogo.ranking;
}

tRanking ordenaRanking(tJogo jogo) {
  int i, j, auxL, auxC, auxV, l1, c1, v1, l2, c2, v2;

  for (i = 0; i < jogo.ranking.tamanho; i++) {
    for (j = 0; j < jogo.ranking.tamanho - 1; j++) {
      l1 = jogo.ranking.pontos[j][LINHA];
      c1 = jogo.ranking.pontos[j][COLUNA];
      v1 = jogo.ranking.pontos[j][2];

      l2 = jogo.ranking.pontos[j + 1][LINHA];
      c2 = jogo.ranking.pontos[j + 1][COLUNA];
      v2 = jogo.ranking.pontos[j + 1][2];

      if (v1 < v2) {
        auxL = jogo.ranking.pontos[j][LINHA];
        auxC = jogo.ranking.pontos[j][COLUNA];
        auxV = jogo.ranking.pontos[j][2];

        jogo.ranking.pontos[j][LINHA] = jogo.ranking.pontos[j + 1][LINHA];
        jogo.ranking.pontos[j][COLUNA] = jogo.ranking.pontos[j + 1][COLUNA];
        jogo.ranking.pontos[j][2] = jogo.ranking.pontos[j + 1][2];

        jogo.ranking.pontos[j + 1][LINHA] = auxL;
        jogo.ranking.pontos[j + 1][COLUNA] = auxC;
        jogo.ranking.pontos[j + 1][2] = auxV;
      } else if (v1 == v2) {
        if (l1 > l2) {

          auxL = jogo.ranking.pontos[j][LINHA];
          auxC = jogo.ranking.pontos[j][COLUNA];
          auxV = jogo.ranking.pontos[j][2];

          jogo.ranking.pontos[j][LINHA] = jogo.ranking.pontos[j + 1][LINHA];
          jogo.ranking.pontos[j][COLUNA] = jogo.ranking.pontos[j + 1][COLUNA];
          jogo.ranking.pontos[j][2] = jogo.ranking.pontos[j + 1][2];

          jogo.ranking.pontos[j + 1][LINHA] = auxL;
          jogo.ranking.pontos[j + 1][COLUNA] = auxC;
          jogo.ranking.pontos[j + 1][2] = auxV;
        } else if (l1 == l2) {
          if (c1 > c2) {
            auxL = jogo.ranking.pontos[j][LINHA];
            auxC = jogo.ranking.pontos[j][COLUNA];
            auxV = jogo.ranking.pontos[j][2];

            jogo.ranking.pontos[j][LINHA] = jogo.ranking.pontos[j + 1][LINHA];
            jogo.ranking.pontos[j][COLUNA] = jogo.ranking.pontos[j + 1][COLUNA];
            jogo.ranking.pontos[j][2] = jogo.ranking.pontos[j + 1][2];

            jogo.ranking.pontos[j + 1][LINHA] = auxL;
            jogo.ranking.pontos[j + 1][COLUNA] = auxC;
            jogo.ranking.pontos[j + 1][2] = auxV;
          }
        }
      }
    }
  }

  return jogo.ranking;
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

tJogo iniciaJogo(int argc, char *diretorio) {
  // Verifica se foi passado um arquivo
  if (argc == 1) {
    printf("ERRO: O diretorio de arquivos de configuracao nao foi "
           "informado\n");
    exit(0);
  }

  // Inicia o jogo com as variaveis resetadas
  tJogo jogo = {.mapa = carregaMapa(diretorio),
                .heatMapa = inicializaHeatMapa(diretorio),
                .estatisticas = inicializaEstatisticas(),
                .cobra = inicializaCobra(jogo.mapa),
                .ranking = inicializaRanking(),
                .pontuacao = 0,
                .numeroDaJogada = 0,
                .status = JOGANDO};

  strcpy(jogo.diretorio, diretorio);

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
  jogo.ranking = atualizaRanking(jogo);
  jogo.estatisticas = contaMovimentoDirecionado(
      jogo.estatisticas, proximaDirecao(movimento, jogo.cobra.direcao));
  jogo.cobra = movimentaCobra(jogo.cobra, movimento);
  jogo.numeroDaJogada += 1;

  if (passouDoMapa(jogo.mapa, jogo.cobra)) {
    jogo.cobra = teleportaCobra(jogo.mapa, jogo.cobra);
  }

  char objeto = objetoDaCabeca(jogo.mapa, jogo.cobra);

  if (objeto == jogo.mapa.parede || colisaoComACobra(jogo.cobra)) {
    jogo.status = PERDEU;
    jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
    jogo.ranking = atualizaRanking(jogo);
    resumeFimDeJogoPorColisao(jogo, movimento);
  }
  if (objeto == jogo.mapa.comida) {
    jogo.cobra = aumentaCobra(jogo.cobra);
    jogo = aumentaPontuacao(jogo, 1);

    if (temComida(jogo.mapa) == 1) {
      jogo.status = VENCEU;
      // jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
      resumeCrescimentoCobraTerminandoJogo(jogo, movimento);
    } else {
      resumeCrescimentoCobraSemTerminar(jogo, movimento);
    }
  }
  if (objeto == jogo.mapa.dinheiro) {
    jogo = aumentaPontuacao(jogo, 10);
    resumeGerouDinheiro(jogo, movimento);
  }
  if (objeto != jogo.mapa.dinheiro && objeto != jogo.mapa.comida) {
    jogo.estatisticas = contaMovimentoSemPontuar(jogo.estatisticas);
  }

  jogo.estatisticas = contaMovimento(jogo.estatisticas);
  jogo.mapa = atualizaMapa(jogo.mapa, jogo.cobra);

  if (!temComida(jogo.mapa)) {
    jogo.status = VENCEU;
    jogo.heatMapa = rastreiaMovimento(jogo.heatMapa, jogo.cobra);
    jogo.ranking = atualizaRanking(jogo);
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
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, INICIALIZACAO_DIR);

  FILE *arquivo = fopen(path, "w");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  for (i = 0; i < jogo.mapa.linhas; i++) {
    for (j = 0; j < jogo.mapa.colunas; j++) {
      fprintf(arquivo, "%c", jogo.mapa.objs[i][j]);
    }
    fprintf(arquivo, "\n");
  }

  int cabecaL = jogo.cobra.corpo[CABECA][LINHA] + 1;
  int cabecaC = jogo.cobra.corpo[CABECA][COLUNA] + 1;

  fprintf(arquivo, "A cobra comecara o jogo na linha %d e coluna %d\n", cabecaL,
          cabecaC);

  fclose(arquivo);
}

void geraResumo(tJogo jogo) {
  FILE *arquivo = fopen("./saida/resumo.txt", "w");
  fclose(arquivo);
}

void geraRanking(tJogo jogo) {
  int i;
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, RANKING_DIR);

  FILE *arquivo = fopen(path, "w");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  jogo.ranking = ordenaRanking(jogo);

  for (i = 0; i < jogo.ranking.tamanho; i++) {
    fprintf(arquivo, "(%d, %d) - %d\n", jogo.ranking.pontos[i][LINHA],
            jogo.ranking.pontos[i][COLUNA], jogo.ranking.pontos[i][2]);
  }
  fclose(arquivo);
}

void geraEstatistica(tJogo jogo) {
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, ESTATISTICAS_DIR);

  FILE *arquivo = fopen(path, "w");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

  fprintf(arquivo, "Numero de movimentos: %d\n",
          jogo.estatisticas.totalMovimentos);
  fprintf(arquivo, "Numero de movimentos sem pontuar: %d\n",
          jogo.estatisticas.semPontuar);
  fprintf(arquivo, "Numero de movimentos para baixo: %d\n",
          jogo.estatisticas.movimentosDirecionados[BAIXO]);
  fprintf(arquivo, "Numero de movimentos para cima: %d\n",
          jogo.estatisticas.movimentosDirecionados[CIMA]);
  fprintf(arquivo, "Numero de movimentos para esquerda: %d\n",
          jogo.estatisticas.movimentosDirecionados[ESQUERDA]);
  fprintf(arquivo, "Numero de movimentos para direita: %d\n",
          jogo.estatisticas.movimentosDirecionados[DIREITA]);
  fclose(arquivo);
}

void geraHeatMapa(tJogo jogo) {
  int i, j;
  char path[TAM_DIRETORIO*2] = "";

  strcat(path, jogo.diretorio);
  strcat(path, SAIDA_DIR);
  strcat(path, HEATMAPA_DIR);

  FILE *arquivo = fopen(path, "w");

  if (!arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", path);
    exit(0);
  }

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
