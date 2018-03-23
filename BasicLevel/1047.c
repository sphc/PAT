#include <stdio.h>

int grade[10010] = {0}; //下标表示队伍编号，值代表总成绩

int main(void)
{
    int n;
    int max = 0; //成绩最高的队伍编号

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int teamNum, memberNum, score;

        scanf("%d-%d%d", &teamNum, &memberNum, &score);
        grade[teamNum] += score;
        if (grade[teamNum] > grade[max]) {
            max = teamNum;
        }
    }
    printf("%d %d\n", max, grade[max]);

    return 0;
}
