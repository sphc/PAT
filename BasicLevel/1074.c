#include <stdio.h>
#include <string.h>

#define SIZE 30

int ctoi(char c)
{ return c - '0'; }

char itoc(int i)
{ return i + '0'; }

//读取一行并丢弃换行
void getLine(char *s, int size)
{ 
    fgets(s, size, stdin);
    s[strlen(s) - 1] = '\0';
}

//在数字前补count个0
void addZero(char *s, size_t count)
{
    char tmp[SIZE];

    strcpy(tmp, s);
    while (count--) {
        *s++ = '0';
    }
    strcpy(s, tmp);
}

//反转字符串
void reverse(char *s)
{
    char *p = s + strlen(s) - 1;

    while (s < p) {
        char tmp = *s;

        *s = *p;
        *p = tmp;
        ++s;
        --p;
    }
}

//打印num
void printNum(const char *num)
{
    //忽略前导0
    while (*num && *num == '0') {
        ++num;
    }
    if (!*num) {
        putchar('0');
    }
    printf("%s", num);
}

int main(void)
{
    char table[SIZE]; //进制表
    char a[SIZE], b[SIZE], c[SIZE];
    int size = 0;
    int flag = 0;
    int i, j, k;

    getLine(table, SIZE);
    getLine(a, SIZE);
    getLine(b, SIZE);

    i = strlen(a);
    j = strlen(b); 
    k = strlen(table);

    //短的数字前面补0
    if (i < j) {
        addZero(a, j - i);
        i = j;
    }
    else {
        addZero(b, i - j);
    }

    //从后往前逐项计算
    while (--i >= 0 && --k >= 0) {
        int base = table[k] == '0' ? 10 : ctoi(table[k]);

        flag += ctoi(a[i]) + ctoi(b[i]);    
        c[size++] = itoc(flag % base);
        flag /= base;
    }
    //进位
    if (flag) {
        c[size++] = itoc(flag);
    }
    c[size] = '\0';

    reverse(c);
    printNum(c);
    printf("\n");
}
