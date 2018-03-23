#include <stdio.h>

int score[10000] = {0}; //每道题的满分值
int answer[10000] = {0}; //每道题的正确答案

int main(void)
{
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", score + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", answer + i);
    }
    for (int i = 0; i < n; ++i) {
        int grade = 0; //每个学生的得分
        int a; //每个答案

        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            if (a == answer[j]) {
                grade += score[j];
            }
        }
        printf("%d\n", grade);
    }

    return 0;
}
