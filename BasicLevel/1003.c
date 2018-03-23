#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int SIZE = 110;

//计算s开始连续的A的数量,并将s指向第一个不是A的字符
int countA(const char **s)
{
    int count = 0;

    while (**s && **s == 'A') {
        ++count;
        ++*s;
    }

    return count;
}

//读取一行到s中，并丢弃换行符
void getLine(char *s, int size)
{
    int len;

    fgets(s, size, stdin);
    len = strlen(s);
    //丢弃末尾换行
    if (len > 0) {
        s[len - 1] = '\0';
    }
}

bool condition1(const char *s)
{
    while (*s && (*s == 'P' || *s == 'A' || *s == 'T')) {
        ++s;
    }

    return *s == '\0';
}

bool condition2(const char *s)
{
    int x;
    //前缀A
    x = countA(&s);
    //中间的PAT
    if (*s && *s == 'P') {
        ++s;
    }
    else {
        return false;
    }
    if (*s && *s == 'A') {
        ++s;
    }
    else {
        return false;
    }
    if (*s && *s == 'T') {
        ++s;
    }
    else {
        return false;
    }

    return x == countA(&s);
}

bool condition3(const char *s)
{
    const char *aPbATca = s;
    char aPbTc[SIZE];
    int a, b, c, ca;
    int size = 0;

    a = countA(&s);
    //使s指向P后面的字符
    ++s;
    b = countA(&s) - 1;
    //使s指向T后面的字符
    ++s;
    ca = countA(&s);
    c = ca - a;

    if (b < 0) {
        return false;
    }
    
    //构造aPbTc
    for (int i = 0; i < a; ++i) {
        aPbTc[size++] = 'A';
    }
    aPbTc[size++] = 'P';
    for (int i = 0; i < b; ++i) {
        aPbTc[size++] = 'A';
    }
    aPbTc[size++] = 'T';
    for (int i = 0; i < c; ++i) {
        aPbTc[size++] = 'A';
    }
    aPbTc[size] = '\0';

    return condition2(aPbTc) || condition3(aPbTc);
}

int main(void)
{
    int n;
    char s[SIZE];

    scanf("%d", &n);
    getchar();
    while (n--) {
        getLine(s, SIZE);
        if (condition1(s) && (condition2(s) || condition3(s))) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
