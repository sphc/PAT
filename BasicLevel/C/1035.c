#include <stdio.h>
#include <stdbool.h>

#define SIZE 10000

bool equal(const int *left, const int *right, int size)
{
    for (int i = 0; i < size; ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }

    return true;
}

void printArr(const int *a, int size)
{
    for (int i = 0; i < size; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

bool insertSort(int *a, int size, const int *sequence)
{
    bool success = false;

    for (int i = 1; i < size; ++i) {
        int j = i;
        int tmp = a[i];

        for (; j > 0 && a[j - 1] > tmp; --j) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
        if (success) {
            printArr(a, size);
            break;
        }
        if (equal(a, sequence, size)) {
            printf("Insertion Sort\n");
            success = true;
        }
    }

    return success;
}

void merge(int *a, int *tmp, int left, int leftEnd, int rightEnd)
{
    int right = leftEnd;
    int tmpPos = left;
    int count = rightEnd - left;

    while (left < leftEnd && right < rightEnd) {
        tmp[tmpPos++] = a[right] < a[left] ? a[right++] : a[left++];
    }
    while (left < leftEnd) {
        tmp[tmpPos++] = a[left++];
    }
    while (right < rightEnd) {
        tmp[tmpPos++] = a[right++];
    }

    while (count--) {
        --rightEnd;
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(int *a, int size, const int *sequence)
{
    int tmp[SIZE];
    bool success = false;

    for (int step = 1; step < size; step *= 2) {
        int left, mid, right;
        for (left = 0; left < size - step; left = right) {
            mid = left + step; 
            right = (mid + step > size ? size : mid + step);
            merge(a, tmp, left, mid, right);
        }
        if (success) {
            printArr(a, size);
            return;
        }
        if (equal(a, sequence, size)) {
            printf("Merge Sort\n");
            success = true;
        }
    }
}

int main(void)
{
    int n;
    int a[SIZE], b[SIZE];
    int sequence[SIZE];
    int tmp[SIZE];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", sequence + i);
    }
    if (!insertSort(a, n, sequence)) {
        mergeSort(b, n, sequence);
    }

    return 0;
}
