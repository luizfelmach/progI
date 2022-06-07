#include <stdio.h>

int ehProduto(char prd) {
	return prd >= 'A' && prd <= 'Z';
}

int acabaramOsProdutos(char prd) {
	return prd == '0';
}

int qtdDoProdutoMaisComprado() {

	char prd = '\0';
	char ant = '\0';

	int qtd = 0;
	int qtdMaisGuloso = 0;

	while (!acabaramOsProdutos(prd)) {
		scanf("%c", &prd);

		if (ant == '\0') ant = prd;

		if (ehProduto(prd)) {
			if (prd == ant) {
				qtd++;
			} else {
				if (qtd > qtdMaisGuloso) qtdMaisGuloso = qtd;
				qtd = 1;
				ant = prd;
			}

		}

	}
	
	return qtdMaisGuloso;
}

int main() {
	int cliente = 0;
	int qtdProdutos = 0;


	int clienteGuloso = 0;
	int qtdGuloso = 0;

	while (1) {
		scanf("%d", &cliente);
		scanf("%*c");
		if (cliente == -1) break;

		qtdProdutos = qtdDoProdutoMaisComprado();

		if (qtdProdutos > qtdGuloso) {
			clienteGuloso = cliente;
			qtdGuloso = qtdProdutos;
		}
		
	}

	printf("CLIENT:%d QTD:%d", clienteGuloso, qtdGuloso);
	return 0;
}
