#include <stdio.h>

//将num以base进制打印
void printBase(int num, int base)
{
    if (num / base) {
        printBase(num / base, base);
    }
    printf("%d", num % base);
}

int main(void)
{
    int a, b, base;

    scanf("%d%d%d", &a, &b, &base);
    printBase(a + b, base);
    printf("\n");

    return 0;
}
