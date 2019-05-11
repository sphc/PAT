#include <stdio.h>
#include <stdlib.h>

#define SIZE 10010

int cmp(const void *left, const void *right)
{ return *(int *)left - *(int *)right; }

int main(void)
{
    int rope[SIZE];
    int n;
    double result = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", rope + i);
    }

    //升序排序
    qsort(rope, n, sizeof(int), cmp);

    //优先连接短的绳子,可以尽可能多的保留长的绳子,以使最终结果最大
    result = rope[0];
    for (int i = 1; i < n; i ++) {
        result = (result + rope[i]) / 2.0; 
    }

    printf("%d\n", (int)result);
}
