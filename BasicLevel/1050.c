#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10010

int matrix[SIZE][SIZE] = {0};

int cmp(const void *left, const void *right)
{ return *(int *)right - *(int *)left; }

//获取n和m的值
void getNM(int *n, int *m, int N) 
{
    int i = 1;
    int j = N / i;

    while (i <= N && i <= j) {
        if (i * j == N) {
            *n = i;
            *m = j;
        }
        j = N / ++i;
    }
}

int main(void)
{
    int N;
    int n, m;
    int nums[SIZE];
    int x = 0, y = 0;
    int cur = 0;

    //输入数字
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", nums + i);
    }

    //降序排序
    qsort(nums, N, sizeof(int), cmp);

    getNM(&n, &m, N);

    //填入第一个数
    matrix[x][y] = nums[cur++];
    while (cur < N) {
        //一直向右填到不能填为止
        while (y + 1 < n && !matrix[x][y + 1]) {
            matrix[x][++y] = nums[cur++];
        }

        //一直向下填到不能填为止
        while (x + 1 < m && !matrix[x + 1][y]) {
            matrix[++x][y] = nums[cur++];
        }

        //一直向左填到不能填为止
        while (y - 1 >= 0 && !matrix[x][y - 1]) {
            matrix[x][--y] = nums[cur++];
        }

        //一直向上填到不能填为止
        while (x - 1 >= 0 && !matrix[x - 1][y]) {
            matrix[--x][y] = nums[cur++];
        }
    }

    //打印矩阵
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
