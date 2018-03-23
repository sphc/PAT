#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE (1 << 20 + 10)

char newStr[SIZE];

typedef void (* solveFunction)(const char *);

void trans(int num, char **str)
{
    if (num) {
        trans(num / 10, str);
        *(*str)++ = num % 10 + '0';
    }
}

//int转换为字符串
void myItoa(int num, char *str)
{
    trans(num, &str);
    *str = '\0';
}

//压缩
void compress(const char *str)
{
    int count = 1;
    int size = 0;
    char num[12]; //重复个数的字符串版本

    for (int i = 1; i < strlen(str); ++i) {
        if (str[i] == str[i - 1]) {
            ++count;
        }
        else {
            if (count > 1) {
                myItoa(count, num);
                strcat(newStr, num);
                size += strlen(num);
                count = 1;
            }
            newStr[size++] = str[i - 1];
        }
    }
    //最后一部分
    if (count > 1) {
        myItoa(count, num);
        strcat(newStr, num);
        size += strlen(num);
    }
    newStr[size++] = str[strlen(str) - 1];
    newStr[size] = '\0';

    printf("%s", newStr);
}

//解压
void decompress(const char *str)
{
    int size = 0;

    for (int i = 0; i < strlen(str); ++i) {
        int count = 0;

        while (isdigit(str[i])) {
            count = count * 10 + str[i++] - '0';
        }
        //只有一个字符
        if (count == 0) {
            newStr[size++] = str[i];
        }
        //将字符全部解压
        while (count--) {
            newStr[size++] = str[i];
        }
    }
    newStr[size] = '\0';

    printf("%s", newStr);
}

int main(void)
{
    char str[1024];
    char choice;
    solveFunction solve[2] = { compress, decompress };

    choice = getchar();
    getchar();
    fgets(str, SIZE, stdin);
    solve[choice - 'C'](str);

    return 0;
}
