#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PAIR_SIZE 100010
#define ID_SIZE 10010
#define NOT_FOUND -1

int cmp(const void *left, const void *right)
{ return *(int *)left - *(int *)right; }

//二分搜索
int binarySearch(const int *arr, int left, int right, int value) 
{
    int mid = (left + right) / 2;

    if (left > right) {
        return NOT_FOUND;
    }
    else if (arr[mid] > value) {
        return binarySearch(arr, left, mid - 1, value);
    }
    else if (arr[mid] < value) {
        return binarySearch(arr, mid + 1, right, value);
    }
    else {
        return mid;
    }
}

void initPair(int *pair, int size, int value)
{
    for (int i = 0; i < size; ++i) {
        pair[i] = value;
    }
}

int main(void)
{
    int n, m;
    int id[ID_SIZE]; //输入的id
    int result[ID_SIZE]; //单身狗id
    int resultSize = 0; //单身狗个数
    int pair[PAIR_SIZE]; //下标和值表示一对夫妻的id

    initPair(pair, PAIR_SIZE, NOT_FOUND);
    scanf("%d", &n);
    //构造映射关系,pair[夫]=妻,pair[妻]=夫
    for (int i = 0; i < n; ++i) {
        int first, second;

        scanf("%d%d", &first, &second);
        pair[first] = second;
        pair[second] = first;
    }

    scanf("%d", &m);
    //输入id
    for (int i = 0; i < m; ++i) {
        scanf("%d", id + i);
    }

    //id按升序排
    qsort(id, m, sizeof(int), cmp);

    for (int i = 0; i < m; ++i) {
        //id未出现在pair中或未找到其伴侣
        if (pair[id[i]] == NOT_FOUND || binarySearch(id, 0, m - 1, pair[id[i]]) == NOT_FOUND) {
            result[resultSize++] = id[i];
        }
    }

    //打印结果
    printf("%d\n", resultSize);
    for (int i = 0; i < resultSize; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%.5d", result[i]);
    }
    //resultSize为0时不打印换行，否则会有测试点过不去
    if (resultSize) {
        printf("\n");
    }

    return 0;
}
