#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool maybe[100010] = {0}; //标记可能是主元的元素

int cmp(const void *first, const void *second)
{ return *(int *)first - *(int *)second; }

//index下标处的元素可能是主元,则返回true
bool maybeMajor(const int *nums, int size, int index)
{
    //检查左侧
    for (int i = index - 1; i >= 0; --i) {
        if (nums[i] < nums[index] && maybe[i]) {
            break;
        }
        else if (nums[i] > nums[index]) {
            return false;
        }
    }
    //检查右侧
    for (int i = index + 1; i < size; ++i) {
        if (nums[i] > nums[index] && maybe[i]) {
            break;
        }
        if (nums[index] > nums[i]) {
            return false;
        }
    }
    maybe[index] = true;

    return maybe[index];
}

void printArr(const int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", arr[i]);
    }
}

int main(void)
{
    int n, len = 0; //len：result保存的元素个数
    int nums[100010];
    int result[100010];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", nums + i);
    }
    //从两端开始向中间递进的判断，以便每一次的判断都可能减少后续判断的次数
    for (int i = 0; i < n / 2; ++i) {
        if (maybeMajor(nums, n, i)) {
            result[len++] = nums[i];
        }
        if (maybeMajor(nums, n, n - 1 - i)) {
            result[len++] = nums[n - 1 - i];
        }
    }
    //如果n为奇数，则前面的循环未处理到中间的数
    if (n % 2 && maybeMajor(nums, n, n / 2)) {
        result[len++] = nums[n / 2];
    }

    qsort(result, len, sizeof(int), cmp);
    printf("%d\n", len);
    printArr(result, len);
    putchar('\n');

    return 0;
}
