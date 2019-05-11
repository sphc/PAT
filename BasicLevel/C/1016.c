#include <stdio.h>

//计算pn
int p(int n, int dn)
{
    int tmp;
    int result = 0;

    while (n) {
        tmp = n % 10;
        if (tmp == dn) {
            result = result * 10 + tmp;
        }
        n /= 10;
    }

    return result;
}

int main(void)
{
    int a, da;
    int b, db;

    scanf("%d%d%d%d", &a, &da, &b, &db);
    printf("%d\n", p(a, da) + p(b, db)); 

    return 0;
}
