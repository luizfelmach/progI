#include <stdio.h>

int main() {
    int nums[3];
    int ordem[3] = {1, 2, 3};
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 2; j++) {
            if (nums[j] > nums[j + 1]) {
                int tmp1 = nums[j + 1], tmp2 = nums[j];
                int tmp3 = ordem[j + 1], tmp4 = ordem[j];
                nums[j] = tmp1;
                nums[j + 1] = tmp2;
                ordem[j] = tmp3;
                ordem[j + 1] = tmp4;
            }
        }
    }
    printf("N%d = %d, N%d = %d, N%d = %d", ordem[0], nums[0], ordem[1], nums[1],
           ordem[2], nums[2]);
    return 0;
}
