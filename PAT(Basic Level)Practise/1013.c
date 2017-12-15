#include <stdio.h>
#include <stdbool.h>

//判断是否素数
bool isPrim(int num)
{
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

//产生一个大于num的素数
int generatePrim(int num)
{
    while (!isPrim(++num)) {
    }
    
    return num;
}

int main(void)
{
    int m, n;
    int prim = 0;
    int i = 0; //第几个素数

    scanf("%d%d", &m, &n);
    while (i < m) {
        prim = generatePrim(prim);
        ++i;
    }
    while (i <= n) {
        printf("%d", prim = generatePrim(prim));
        //控制格式
        if ((i - m + 1) % 10 == 0) {
            putchar('\n');
        }
        else {
            if (i != n) {
                putchar(' ');
            }
        }
        ++i;
    }
    if ((n - m + 1) % 10 != 0) {
        putchar('\n');
    }

    return 0;
}
