#include <stdio.h>
#include <stdlib.h>

//四舍五入
int myRound(double num)
{ return num + 0.5; }

int cmp(const void *left, const void *right)
{ return *(int *)left - *(int *)right; }

//计算left到right(不包括right)的平均值
double average(const int *arr, int left, int right)
{
    double sum = 0;;
    int size = right - left;

    while (left < right) {
        sum += arr[left++];
    }
    if (size > 0) {
        sum /= size;
    }

    return sum;
}

int main(void)
{
    int n, m;
    int score[110]; //评分

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int size = 0;

        for (int j = 0; j < n; ++j) {
            int grade;

            scanf("%d", &grade);
            if (grade >= 0 && grade <= m) {
                score[size++] = grade;
            }
        }
        qsort(score + 1, size - 1, sizeof(int), cmp);
        printf("%d\n", myRound((score[0] + average(score, 2, size - 1)) / 2));
    }

    return 0;
}
