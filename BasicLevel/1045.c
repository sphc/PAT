#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE 100010

int cmp(const void *left, const void *right)
{ return *(int *)left - *(int *)right; }

int main(void)
{
    int n;
    int elements[SIZE];
    int min[SIZE]; //min[i]表示第i + 1个元素到末尾元素间的最小值
    int m = INT_MAX, max = INT_MIN;
    int size = 0; //结果的个数

    //输入元素
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", elements + i);
    }

    //求min
    for (int i = n - 1; i >= 0; --i) {
        min[i] = m;
        if (m > elements[i]) {
            m = elements[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        //对于每一个元素,它只要大于在它之前的最大值
        //并且小于在它之后的最小值,便是主元
        if (elements[i] > max && elements[i] < min[i]) {
            //将结果元素覆盖在elements中,并以size表示其个数
            elements[size++] = elements[i];
        }
        if (max < elements[i]) {
            max = elements[i];
        }
    }

    //升序排序
    qsort(elements, size, sizeof(int), cmp);

    //打印结果
    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%d", elements[i]);
    }
    printf("\n");

    return 0;
}
