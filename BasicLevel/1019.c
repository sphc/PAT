#include <stdio.h>
#include <string.h>

#define SIZE 10

//将n各位数放到数组a中，这样便于产生非递减和非递增的数
void trans(int *nums, int n)
{
    int size = 4;

    while (n) {
        ++nums[n % 10];
        n /= 10;
        --size;
    }

    //如果size大于0，说明数字前导的0未算进去
    if (size > 0) {
        nums[0] += size;
    }
}

//根据nums产生非递增的数
int generateFirst(int *nums, int size)
{
    int result = 0;

    for (int i = size - 1; i >= 0; --i) {
        for (int j = 0; j < nums[i]; ++j) {
            result = result * 10 + i;
        }
    }

    return result;
}

//根据nums产生非递减的数
int generateSecond(int *nums, int size)
{
    int result = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < nums[i]; ++j) {
            result = result * 10 + i;
        }
    }

    return result;
}

int main(void)
{
    int n;
    int x, y; //x:非递增的数; y:非递减的数
    int nums[SIZE] = {0}; //存放某一数中的各位数字及个数

    scanf("%d", &n);
    do {
        trans(nums, n);
        x = generateFirst(nums, SIZE);
        y = generateSecond(nums, SIZE);
        memset(nums, 0, sizeof(int) * SIZE); //清零
        n = x - y;
        printf("%.4d - %.4d = %.4d\n", x, y, n); 
    } while (n != 6174 && n != 0);

    return 0;
}
