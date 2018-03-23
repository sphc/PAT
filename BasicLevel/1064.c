#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//num是否已出现过
bool isExisted(const int *arr, int index, int num)
{
    for (int i = 0; i < index; ++i) {
        if (arr[i] == num) {
            return true;
        }
    }

    return false;
}

//获取朋友证号
int friend(int num)
{
    int sum = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int cmp(const void *left, const void *right)
{ return *(int *)left - *(int *)right; }

int main(void)
{
    int n;
    int result[10010];
    int size = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;

        scanf("%d", &num);
        num = friend(num);
        if (!isExisted(result, size, num)) {
            result[size++] = num;
        }
    }

    qsort(result, size, sizeof(int), cmp);
    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", result[i]);
    }
    putchar('\n');

    return 0;
}
