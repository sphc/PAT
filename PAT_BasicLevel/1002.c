#include <stdio.h>

const char *chineseNum[] = {"ling", "yi", "er", "san", "si",
                            "wu", "liu", "qi", "ba", "jiu"};

//对数num的各位数字求和
int numSum(const char *num)
{
    int sum = 0;

    while (*num) {
        sum += *num - '0';
        ++num;
    }

    return sum;
}

//将数值以拼音形式输出
void proc(int value)
{
    if (value) {
        proc(value / 10);
        if (value / 10) { //若不是第一个数字，则在输出前加一个空格
            putchar(' ');
        }
        printf("%s", chineseNum[value % 10]);
    }
}

int main(void)
{
    char num[110];

    scanf("%s", num);
    proc(numSum(num));
    putchar('\n');

    return 0;
}
