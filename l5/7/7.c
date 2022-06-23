#include <stdio.h>

int main() {
	int n, i;
	scanf("%d", &n);
	int nums[n];

	for(i = 0; i < n; i++)
		scanf("%d", &nums[i]);

	if (n == 1) {
		printf("NAO");
		return 0;
	}

	int primeiro = nums[0];
	int razao = nums[1] - nums[0];

	for(i = 1; i < n; i++) {
		primeiro += razao;
		if (nums[i] != primeiro) {
			printf("NAO");
			return 0;
		}
	}
	printf("RESP:%d", razao);
	return 0;
}
