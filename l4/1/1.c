#include <stdio.h>

typedef struct {
	int codigo;
	float preco;
	int estoque;
} tProduto; 

tProduto leProduto() {
	tProduto produto;
	scanf("%d;%f;%d\n", &produto.codigo,
			&produto.preco,
			&produto.estoque);
	return produto;
}

int ehProduto1MaiorQ2(tProduto p1, tProduto p2) {
	int ehMaior = 0;

	if(p1.preco > p2.preco) ehMaior = 1;

	return ehMaior;
}

int ehProduto1MenorQ2(tProduto p1, tProduto p2) {
	int ehMenor = 0;

	if(p1.preco < p2.preco) ehMenor = 1;

	return ehMenor;
}

int temProdutoEmEstoque(tProduto p) {
	return p.estoque > 0;
	}

void imprimeProduto(tProduto p) {
	printf("COD %d, PRE %.2f, QTD %d\n", p.codigo,
			p.preco,
			p.estoque);
}

int main() {
	int qtd; scanf("%d\n", &qtd);
	tProduto produto;
	tProduto maiorProduto;
	tProduto menorProduto;

	int i;
	for (i = 0; i < qtd; i++) {
		produto = leProduto();
		if (i == 0) {
			maiorProduto = produto;
			menorProduto = produto;
		}
		if (!temProdutoEmEstoque(produto)) {
			printf("FALTA:");
			imprimeProduto(produto);
		}
		if (ehProduto1MaiorQ2(produto, maiorProduto)) {
			maiorProduto = produto;
		}
		if (ehProduto1MenorQ2(produto, menorProduto)) {
			menorProduto = produto;
		}
	}
	printf("MAIOR:");
	imprimeProduto(maiorProduto);
	printf("MENOR:");
	imprimeProduto(menorProduto);
	return 0;
}
