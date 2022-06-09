#include <stdio.h>

int main() {
	int x1, y1;
	int x2, y2;

	int xse = 0, yse = 0;
	int xie = 0, yie = 0;
	int xid = 0, yid = 0;
	int xsd = 0, ysd = 0;

	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);


	if (y1 > y2) {
		if (x1 > x2) {
			xsd = x1;
			ysd = y1;
			xie = x2;
			yie = y2;

			xse = x2;
			yse = y1;
			xid = x1;
			yid = y2;
		} else if ( x2 > x1) {
			xse = x1;
			yse = y1;
			xid = x2;
			yid = y2;

			xsd = x2;
			ysd = y1;
			xie = x1;
			yie = y2;
		}
	}

	if (y2 > y1) {
		if (x1 > x2) {
			xid = x1;
			yid = y1;
			xse = x2;
			yse = y2;

			xsd = x1;
			ysd = y2;
			xie = x2;
			yie = y1;
		} else if ( x2 > x1) {
			xie = x1;
			yie = y1;
			xsd = x2;
			ysd = y2;

			xid = x2;
			yid = y1;
			xse = x1;
			yse = y2;
		}
	}


	printf("(%d,%d)(%d,%d)", xse, yse, xie, yie);
	printf("(%d,%d)(%d,%d)", xid, yid, xsd, ysd);
	printf("\n");


	return 0;
}
