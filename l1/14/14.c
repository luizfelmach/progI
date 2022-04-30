#include <stdio.h>

int y(float y1, float y2, float py) {
    if (y1 > y2) {
        y1 *= -1;
        y2 *= -1;
        py *= -1;
    }
    if (py >= y1 && py <= y2) {
        return 1;
    }
    return 0;
}

int x(float x1, float x2, float px) {
    if (x1 > x2) {
        x1 *= -1;
        x2 *= -1;
        px *= -1;
    }
    if (px >= x1 && px <= x2) {
        return 1;
    }
    return 0;
}

int main() {
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, px = 0, py = 0;
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &px, &py);
    if (x(x1, x2, px) && y(y1, y2, py)) {
        printf("Dentro");
    } else {
        printf("Fora");
    }
    return 0;
}
