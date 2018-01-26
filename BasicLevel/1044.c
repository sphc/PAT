#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NPOS -11111 //表示未找到

//低位
const char *low[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };

//高位
const char *high[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

//火星文数字转整数
int marstoi(const char *mars)
{
    for (int i = 0; i < 13; ++i) {
        if (strcmp(mars, low[i]) == 0) {
            return i;
        }
    }
    for (int i = 0; i < 12; ++i) {
        if (strcmp(mars, high[i]) == 0) {
            return (i + 1) * 13;
        }
    }

    return NPOS;
}

//以整型打印火星文mars
void printInt(char *mars)
{
    char *p = mars;
    int value = 0;

    //计算高位
    while (*p) {
        if (*p == ' ') {
            *p = '\0';
            value = value * 10 + marstoi(mars);
            mars = ++p;
            continue;
        }
        ++p;
    }
    value += marstoi(mars); //加上最后的低位
    printf("%d", value);
}

//打印高位
void printHigh(int num)
{
    if (num != 0) {
        printHigh(num / 13);
        printf("%s", high[num % 13 - 1]);
    }
}

//以火星文打印num
void printMars(int num)
{
    printHigh(num / 13);
    //有高位时，不打印低位的零
    if (num / 13 != 0 && num % 13 != 0) {
        printf(" %s", low[num % 13]);
    }
    else if (num / 13 == 0) { //没有高位时，不打印前面的空格
        printf("%s", low[num % 13]);
    }
}

int main(void)
{
    int n;
    char num[10];
    char *tmp;

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        gets(num);
        if (isdigit(num[0])) {
            printMars(atoi(num));
        }
        else {
            printInt(num);
        }
        putchar('\n');
    }

    return 0;
}
