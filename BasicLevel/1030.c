#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *first, const void *second)
{ return *(int *)first - *(int *)second; }

//这里计算可能溢出，让我想了很久才想到
bool valid(int m, int M, int p)
{ return M <= m * (long long)p; }

int perfect(const int *a, int size, int p)
{
    int max = size ? 1 : 0; //size大于0的话，至少可选一个

    for (int i = 0; i < size; ++i) {
        //只有在下一次长度超过max时，计算才有意义，所以j = i + max
        for (int j = i + max; j < size; ++j) {
            if (!valid(a[i], a[j], p)) {
                break;
            }
            else {
                max = j - i + 1;
            }
        }
    }

    return max;
}

int main(void)
{
    int n, p;
    int *a;

    scanf("%d%d", &n, &p);
    a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    //从小到大排序
    qsort(a, n, sizeof(int), cmp);
    printf("%d", perfect(a, n, p));
    putchar('\n');
    
    return 0;
}
