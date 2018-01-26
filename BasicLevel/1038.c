#include <stdio.h>
#include <stdbool.h>

//下标表示成绩，值表示人数
int count[110] = {0};

int main(void)
{
    int n, k;
    bool first = true; //第一次打印

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int grade;

        scanf("%d", &grade);
        ++count[grade];
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int grade;

        scanf("%d", &grade);
        if (!first) {
            putchar(' ');
        }
        printf("%d", count[grade]);
        first = false;
    }
    putchar('\n');

    return 0;
}
