#include <stdio.h>

int main() {
	int x, n;
	int index = -1;
	scanf("%d %d", &x, &n);
	int num[n];

	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	
	for (i = 0; i < n; i++) {
		if (num[i] == x) {
			index = i;
			break;
		}
	}
	if (index == -1)
		printf("RESP:%d", n);
	else
		printf("RESP:%d", index);
	return 0;
}
