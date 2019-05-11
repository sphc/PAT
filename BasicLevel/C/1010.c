#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int expo, coef;
    bool flag = false;

    while (scanf("%d%d", &expo, &coef) == 2) {
        expo *= coef--;
        if (expo) {
            if (flag) {
                putchar(' ');
            }
            printf("%d %d", expo, coef);
            flag = true;
        }
    }
   
    //没有导数要输出0 0，这个地方坑着我百度才写出来
    if (!flag) {
        printf("0 0");
    }
    putchar('\n');

    return 0;
}
