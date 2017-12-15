#include <stdio.h>
#include <string.h>
#include <ctype.h>

//打印单词
void print(const char *s)
{
    while (*s != '\0' && !isspace(*s)) {
        putchar(*s++);
    }
}

void reversePrint(const char *s)
{
    size_t i = strlen(s) - 1; //字符串最后一个字符下标

    //空字符串，不处理
    if (!strlen(s)) {
        return;
    }

    //倒序遍历，若s[i]为空格，说明s[i]后面有一个单词可以打印
    while (i--) {
        if (isspace(s[i])) {
            print(s + i + 1);
            putchar(' ');
        }
    }
    //打印第一个单词
    print(s);
}

int main(void)
{
    char s[82];

    gets(s);
    reversePrint(s);
    putchar('\n');

    return 0;
}
