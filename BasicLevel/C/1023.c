#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a[10] = {0};

    for (int i = 0; i < 10; ++i) {
        scanf("%d", a + i);
    }

    //打印除0以外的最小数
    for (int i = 1; i < 10; ++i) {
        if (a[i]) {
            printf("%d", i);
            --a[i];
            break;
        }
    }

    //剩余数字从小到大依次打印
    for (int i = 0; i < 10; ++i) {
        while (a[i]--) {
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}
