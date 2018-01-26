#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int findMax(const int *arr, int size)
{
    int max = 0;

    for (int i = 0; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

//读取一行，丢弃末尾的换行
void getLine(char *s)
{
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }

    *s = '\0';
}

//输入一个学生的答案
void inputAnAnswer(char *choice)
{
    int c;

    while (isspace(c = getchar()) || c != '(') {
    }
    while ((c = getchar()) != ')') {
        *choice++ = c;
    }
    *choice = '\0';
}

int main(void)
{
    int n, m;
    char answer[120][30]; // 答案
    int grade[1010] = {0};
    int mistake[120] = {0}; //下标+1表示编号，值表示错误次数
    int max;

    scanf("%d%d", &n, &m);
    //将剩余空白读掉
    //这个地方用一个getchar会导致第一个案例过不去，用两个getchar会导致只有第一个案例能过
    getLine(answer[0]);
    for (int i = 0; i < m; ++i) {
        getLine(answer[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char choice[30]; //学生的选择

            inputAnAnswer(choice);
            //输入的答案的格式为：下标为0的值是满分，下标4开始是选项个数和答案
            //故从下标4开始比较相同后可知学生答题正确
            if (strcmp(answer[j] + 4, choice) == 0) {
                grade[i] += answer[j][0] - '0';
            }
            else {
                //统计错误次数
                ++mistake[j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", grade[i]);
    }

    max = findMax(mistake, m);
    //max为0表示没有错误
    if (max == 0) {
        printf("Too simple");
    }
    else {
        printf("%d", max);
        for (int i = 0; i < m; ++i) {
            if (mistake[i] == max) {
                printf(" %d", i + 1);
            }
        }
    }
    putchar('\n');

    return 0;
}
