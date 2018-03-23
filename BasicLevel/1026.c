#include <stdio.h>

#define CLK_TCK 100

//将second按时间格式输出
void printTime(int second)
{
    int h, m;

    h = second / 3600;
    second %= 3600;
    m = second / 60;
    second %= 60;
    printf("%.2d:%.2d:%.2d", h, m, second);
}

//四舍五入
int myRound(double num)
{ return num + 0.5; }

int main(void)
{
    int c1, c2;

    scanf("%d%d", &c1, &c2);
    printTime(myRound((double)(c2 - c1) / CLK_TCK));
    putchar('\n');

    return 0;
}
