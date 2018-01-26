#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//两个数组是否相等
bool equal(const int *arr1, const int *arr2, int n)
{
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

//打印数组
void printArr(const int *arr, int n)
{
    for (int i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", arr[i]);
    }
}

void merge(int *result, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = 0;
    int *tmp = malloc(sizeof(int) * (end - start + 1));

    while (i <= mid && j <= end) {
        if (result[i] < result[j]) {
            tmp[k++] = result[i++];
        }
        else {
            tmp[k++] = result[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = result[i++];
    }
    while (j <= end) {
        tmp[k++] = result[j++];
    }

    for (int x = 0; x < k; ++x) {
        result[start++] = tmp[x];
    }

    free(tmp);
}

//归并排序处理，right为最右边元素
void mergeSort(int *result, const int *input, int left, int right, int n, bool success)
{
    //只剩1个元素
    if (left != right) {
        int mid = (left + right) / 2;
        bool getSequence = equal(result, input, n);

        mergeSort(result, input, left, mid, n, success);
        mergeSort(result, input, mid + 1, right, n, success);
        merge(result, left, mid, right);
        if (!success && getSequence) {
            success = true;
            printf("Merge Sort\n");
            printArr(result, n);
            putchar('\n');
        }
    }
    printf("left:%d, right:%d\n", left, right);
    printArr(result, n);
    putchar('\n');
}

int main(void)
{
    int n;
    int input[110]; //存储输入序列
    int a[110]; 
    bool success = false;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", input + i);
    }
    mergeSort(a, input, 0, n - 1, n, &success);
    /*
    for (int i = 0; i < n; ++i) {
        if (i) { //控制格式
            putchar(' ');
        }
        printf("%d", a[i]);
    }
    */

    return 0;
}
