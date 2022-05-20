#include <stdio.h>

int area(int x1, int y1, int x2, int y2) {
	int base = x2 - x1;
	int altura = y2 - y1;	
	return base * altura;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2) {
	int area_total = 0;
	int area_ret_1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
	int area_ret_2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
	int area_comum = 0;

	if (r2_x1 <= r1_x2 && r2_y1 <= r1_y2) {
		area_comum = area(r1_x2, r1_y2, r2_x1, r2_y1);
	}
	
	area_total = area_ret_1 + area_ret_2 - area_comum;
	return area_total;
}

int main() {
	int r1_x1, r1_y1, r1_x2, r1_y2;
	int r2_x1, r2_y1, r2_x2, r2_y2;
	scanf("%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
	scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

	printf("RESP:%d", area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2 ));
	return 0;
}
