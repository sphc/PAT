#include <stdio.h>

#define SIZE 129

int count[SIZE] = {0}; //下标为某一字符，保存摊主该字符的个数

int main(void)
{
    int c;
    int left = 0; //多余的
    int lack = 0; //缺少的

    //输入摊主珠串，并为各字符计数
    while ((c = getchar()) != EOF && c != '\n') {
        ++count[c];
    }
    //输入小红珠串，并从字符总数中将其减去
    while ((c = getchar()) != EOF && c != '\n') {
        --count[c];
    }
    //统计缺少的个数，多余的个数
    for (int i = 0; i < SIZE; ++i) {
        if (count[i] < 0) {
            lack += -count[i];
        }
        else if (count[i] > 0) {
            left += count[i];
        }
    }
    if (lack > 0) {
        printf("No %d\n", lack);
    }
    else {
        printf("Yes %d\n", left);
    }

    return 0;
}
