#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char a[1010]; //输入的数A
    char q[1010]; //商Q
    int size = 0; //商的位数
    int b, r = 0; //b:除数; r:余数R
    int num; 
    const char *p;
    bool firstNumZero = true; //第一个数为零

    scanf("%s%d", a, &b);
    p = a;
    while (*p) {
        num = r * 10 + (*p++) - '0'; //字符串中的每一位数与之前未除尽的数的和
        r = num % b;
        if (firstNumZero && num / b) { //遇到第一次商不为零的情况，
            firstNumZero = false;       //意味着可将该数放入数组
        }                              //否则，不放入数组
        if (!firstNumZero) { //如果第一个数不为零，便可将商放入数组
            q[size++] = num / b + '0';
        }
    }
    if (!size) { //商为零的情况
        q[size++] = '0';
    }
    q[size] = '\0';
    printf("%s %d\n", q, r);

    return 0;
}
