#include <stdio.h>

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void trocaValor(char* vet, int pos) {
	vet[pos] = '1';
}

int main() {
	int n;
	scanf("%d\n", &n);
	int h, w;

	scanf("%d %d\n", &w, &h);
	char mapa[h][w];
	int antes = 0;
	int depois = 0;

	int i, j;
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			scanf("%c", &mapa[i][j]);
			if (mapa[i][j] == '0')
				antes++;
		}
		scanf("%*c");
	}
	int k;
	int start = '1';
	while (n--) {
		for(i = 0; i < h; i++) {
			for(j = 0; j < w; j++) {
				if (mapa[i][j] == start) {
					if (mapa[i][min(w-1, j+1)] != start)
						mapa[i][min(w-1, j+1)] = start+1;
					if (mapa[i][max(0, j-1)] != start)
						mapa[i][max(0, j-1)] = start+1;
					if (mapa[min(h-1, i+1)][j] != start)
						mapa[min(h-1, i+1)][j] = start+1;
					if (mapa[max(0, i-1)][j] != start)
						mapa[max(0, i-1)][j] = start+1;
				}
			}
		}
		start++;
	
	}
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if (mapa[i][j] == '0')
				depois++;
		}
	}
	printf("%d %d\n", antes, depois);
	return 0;
}
