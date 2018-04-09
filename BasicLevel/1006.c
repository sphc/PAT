#include <stdio.h>

//打印个位
void printGe(int ge)
{
    if (ge == 0) {
        return;
    }
    printGe(ge - 1);
    printf("%d", ge);
}

//打印百位
void printBai(int bai)
{
    for (int i = 0; i < bai; ++i) {
        putchar('B');
    }
}

//打印十位
void printShi(int shi)
{
    for (int i = 0; i < shi; ++i) {
        putchar('S');
    }
}

//以新格式打印
void printNewFormat(int num)
{
    int bai = 0, shi = 0, ge = 0;

    bai = num / 100;
    num %= 100;
    shi = num / 10;
    ge = num % 10;
    printBai(bai);
    printShi(shi);
    printGe(ge);
}

int main(void)
{
    int num;

    scanf("%d", &num);
    printNewFormat(num);
    putchar('\n');

    return 0;
}
