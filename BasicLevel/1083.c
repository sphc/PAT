#include <stdio.h>

#define SIZE 10010

//返回x的绝对值
int abs(int x)
{ return x >= 0 ? x : -x; }

int main(void)
{
    int n, max = -1; //max:最大差值
    int a[SIZE] = {0}; //下标保存差值,值为该差值出现的次数

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;

        scanf("%d", &x);
        x = abs(x - i);
        ++a[x];
        if (max < x) {
            max = x;
        }
    }

    while (max >= 0) {
        if (a[max] > 1) {
            printf("%d %d\n", max, a[max]);
        }
        --max;
    }

    return 0;
}
