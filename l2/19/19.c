#include <malloc.h>
#include <stdio.h>

typedef struct ATLETA {
    int id;
    int notas[3];
    int notasOrdenadas[3];
    int melhor;
    int pior;
    char sexo;
    struct ATLETA* prox;
} ATLETA;

typedef struct {
    int id;
    int melhorMasc;
    int melhorFem;
    int piorMasc;
    int piorFem;
    int tam;
    int campea;
    int somatorioNotas[2];
    ATLETA* atletas;
} DELEGACAO;

int* ordenaNotas(int notas[3]) {
    int i, j, aux;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (notas[j] < notas[j + 1]) {
                aux = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = aux;
            }
        }
    }
    return notas;
}

void melhor(DELEGACAO* delegacao, char sexo) {
    int melhorNota[3] = {0, 0, 0};
    ATLETA* inicio = delegacao->atletas;
    int i;
    for (i = 0; i < 3; i++) {
        while (inicio != NULL) {
            int nota = inicio->notasOrdenadas[i];
            if (nota > melhorNota[i] && inicio->sexo == sexo &&
                inicio->melhor != 0)
                melhorNota[i] = nota;
            inicio = inicio->prox;
        }

        inicio = delegacao->atletas;
        while (inicio != NULL) {
            int nota = inicio->notasOrdenadas[i];
            if (nota != melhorNota[i] && inicio->sexo == sexo)
                inicio->melhor = 0;
            inicio = inicio->prox;
        }
        inicio = delegacao->atletas;
    }

    inicio = delegacao->atletas;
    while (inicio != NULL) {
        if (sexo == 'M' && inicio->sexo == sexo && inicio->melhor == 1) {
            delegacao->melhorMasc = inicio->id;
            break;
        } else if (sexo == 'F' && inicio->sexo == sexo && inicio->melhor == 1) {
            delegacao->melhorFem = inicio->id;
            break;
        }
        inicio = inicio->prox;
    }
}

void pior(DELEGACAO* delegacao, char sexo) {
    int piorNota[3] = {1000, 1000, 1000};
    ATLETA* inicio = delegacao->atletas;
    int i, cont = 0;
    for (i = 0; i < 3; i++) {
        while (inicio != NULL) {
            int nota = inicio->notasOrdenadas[i];
            if (nota < piorNota[i] && inicio->sexo == sexo && inicio->pior != 0)
                piorNota[i] = nota;
            inicio = inicio->prox;
            cont++;
        }

        inicio = delegacao->atletas;
        while (inicio != NULL) {
            int nota = inicio->notasOrdenadas[i];
            if (nota != piorNota[i] && inicio->sexo == sexo) inicio->pior = 0;
            inicio = inicio->prox;
        }
        inicio = delegacao->atletas;
        cont = 0;
    }

    inicio = delegacao->atletas;
    while (inicio != NULL) {
        if (sexo == 'M' && inicio->sexo == sexo && inicio->pior == 1) {
            delegacao->piorMasc = inicio->id;
        } else if (sexo == 'F' && inicio->sexo == sexo && inicio->pior == 1) {
            delegacao->piorFem = inicio->id;
        }
        inicio = inicio->prox;
    }
}

void somatorioMelhoresNotas(DELEGACAO* delegacao) {
    int soma[2] = {0, 0};
    ATLETA* inicio = delegacao->atletas;
    while (inicio != NULL) {
        int nota = inicio->notasOrdenadas[0];
        if (inicio->sexo == 'M')
            soma[0] += nota;
        else if (inicio->sexo == 'F')
            soma[1] += nota;
        inicio = inicio->prox;
    }
    delegacao->somatorioNotas[0] = soma[0];
    delegacao->somatorioNotas[1] = soma[1];
}

int delegacaoCampea(DELEGACAO delegacoes[], char sexo, int qtdDelegacoes) {
    int pos = 0, maior = 0, campea = 0;
    if (sexo == 'M')
        pos = 0;
    else if (sexo == 'F')
        pos = 1;

    int i;
    for (i = 0; i < qtdDelegacoes; i++) {
        if (delegacoes[i].somatorioNotas[pos] > maior) {
            maior = delegacoes[i].somatorioNotas[pos];
        }
    }
    for (i = 0; i < qtdDelegacoes; i++) {
        if (delegacoes[i].somatorioNotas[pos] == maior) {
            return delegacoes[i].id;
        }
    }
    return -1;
}

void adicionaAtleta(DELEGACAO* delegacao, int id, int notas[], char sexo) {
    ATLETA* atleta = (ATLETA*)malloc(sizeof(ATLETA));
    atleta->id = id;
    atleta->notas[0] = notas[0];
    atleta->notas[1] = notas[1];
    atleta->notas[2] = notas[2];
    atleta->notasOrdenadas[0] = ordenaNotas(notas)[0];
    atleta->notasOrdenadas[1] = ordenaNotas(notas)[1];
    atleta->notasOrdenadas[2] = ordenaNotas(notas)[2];
    atleta->sexo = sexo;
    atleta->melhor = 1;
    atleta->pior = 1;
    atleta->prox = NULL;
    ATLETA* inicio = delegacao->atletas;
    if (inicio != NULL) {
        while (1) {
            if (inicio->prox == NULL) {
                inicio->prox = atleta;
                break;
            }
            inicio = inicio->prox;
        }
    } else {
        delegacao->atletas = atleta;
    }
    delegacao->tam++;
}

void entrada(DELEGACAO delegacoes[], int qtdDelegacoes) {
    int id, p1, p2, p3, i;
    char sexo;
    for (i = 0; i < qtdDelegacoes; i++) {
        while (1) {
            scanf("%d", &id);
            if (id > 0) {
                scanf(" %c %d %d %d", &sexo, &p1, &p2, &p3);
                int notas[3] = {p1, p2, p3};
                adicionaAtleta(&delegacoes[i], id, notas, sexo);
            } else
                break;
        }
    }
}

void iniciaDelegacao(DELEGACAO* delegacao, int id) {
    delegacao->id = id;
    delegacao->atletas = NULL;
    delegacao->campea = 0;
    delegacao->tam = 0;
}

int main() {
    int qtdDelegacoes, i;
    scanf("%d", &qtdDelegacoes);
    DELEGACAO delegacoes[qtdDelegacoes];
    for (i = 0; i < qtdDelegacoes; i++) {
        iniciaDelegacao(&delegacoes[i], i + 1);
    }
    entrada(delegacoes, qtdDelegacoes);
    for (i = 0; i < qtdDelegacoes; i++) {
        melhor(&delegacoes[i], 'M');
        melhor(&delegacoes[i], 'F');
        pior(&delegacoes[i], 'M');
        pior(&delegacoes[i], 'F');
        somatorioMelhoresNotas(&delegacoes[i]);
        printf("MELHORES ATLETAS DA DELEGACAO %d\n", i + 1);
        printf("MASCULINO: %d FEMININO: %d\n", delegacoes[i].melhorMasc,
               delegacoes[i].melhorFem);
        printf("PIORES ATLETAS DA DELEGACAO %d\n", i + 1);
        printf("MASCULINO: %d FEMININO: %d\n\n", delegacoes[i].piorMasc,
               delegacoes[i].piorFem);
    }
    int delegacaoCampeaMasc = delegacaoCampea(delegacoes, 'M', qtdDelegacoes);
    int delegacaoCampeaFem = delegacaoCampea(delegacoes, 'F', qtdDelegacoes);
    printf("DELEGACAO CAMPEA:\n");
    printf("MASCULINO: %d FEMININO: %d", delegacaoCampeaMasc,
           delegacaoCampeaFem);
    return 0;
}
