#include <stdio.h>

//正整数的长度
int lenOfNum(int num)
{
    int len = 0;
    
    while (num) {
        num /= 10;
        ++len;
    }

    return len;
}

void _print(int num, int len, int *count)
{
    if (num) {
        _print(num / 10, len, count);
        printf("%d", num % 10);
        //若后面的数的个数能被3整则打印逗号
        if (++*count != len && (len - *count) % 3 == 0) {
            printf(",");
        }
    }
}

void printFormat(int num)
{
    int count = 0; //已打印数的个数
    int len = lenOfNum(num);

    if (num < 0) {
        printf("-");
        num = -num;
    }

    if (num == 0) {
        printf("0");
    }
    else {
        _print(num, len, &count);
    }
}

int main(void)
{
    int a, b;

    scanf("%d%d", &a, &b);
    printFormat(a + b);
    printf("\n");
}
