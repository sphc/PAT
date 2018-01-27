#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 110
#define SEQUENCE_SIZE 10000

typedef struct {
    int base[SEQUENCE_SIZE];
    int size;
} Array;

int cmp(const void *left, const void *right)
{ return *(int *)right - *(int *)left; }

void initArray(Array *array)
{ array->size = 0; }

//num存在array中则返回true
bool isExisted(const Array *array, int num)
{
    for (int i = 0; i < array->size; ++i) {
        if (array->base[i] == num) {
            return true;
        }
    }

    return false;
}

//产生3n+1猜想过程中的序列
void generateSequence(Array *array, int num)
{
    while (num != 1) {
        array->base[array->size++] = num;
        num = ((num % 2) ? (3 * num + 1): num) / 2;
    }
    array->base[array->size++] = 1;
}

int main(void)
{
    int k;
    Array nums[SIZE]; //保存每个数3n+1猜想过程中产生的序列
    int result[SIZE]; //保存结果
    int numSize = 0, resultSize = 0; 

    //初始化
    for (int i = 0; i < SIZE; ++i) {
        initArray(nums + i);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int num;
        bool existed = false;

        scanf("%d", &num);
        //每一次都查看已经产生的序列中是否包含num，若包含则说明num不可能是关键数
        //这时不保存num及其序列
        for (int j = 0; j < i; ++j) {
            if (existed = isExisted(&nums[j], num)) {
                break;
            }
        }
        if (!existed) {
            generateSequence(&nums[numSize++], num);
        }
    }

    //检查每一个数是否被其他序列包含,若未被包含,则说明是关键数,保存至result中
    for (int i = 0; i < numSize; ++i) {
        bool existed = false;

        for (int j = 0; j < numSize; ++j) {
            if (i != j && (existed = isExisted(&nums[j], nums[i].base[0]))) {
                break;
            }
        }
        if (!existed) {
            result[resultSize++] = nums[i].base[0];
        }
    }

    //降序排序
    qsort(result, resultSize, sizeof(int), cmp);

    for (int i = 0; i < resultSize; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    if (resultSize > 0) {
        printf("\n");
    }

    return 0;
}
