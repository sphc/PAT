#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPal(const char *num)
{
    const char *end = num + strlen(num) - 1;

    while (*num == *end) {
        ++num;
        --end;
    }

    return num > end;
}

//得到逆转的数并存入dest
void getReverse(char *dest, const char *src)
{
    const char *p = src + strlen(src) - 1;

    while (p >= src) {
        *dest++ = *p--;
    }
    *dest = '\0';
}

//字符转数字
int ctoi(char c)
{ return c - '0'; }

//数字转字符
char itoc(int num)
{ return num + '0'; }

//求left和right的和并存入left
void sum(char *left, const char *right)
{
    int x = 0; //进位
    int stack[1010];
    int top = 0;

    for (int i = strlen(right) - 1; i >= 0; --i) {
        x = x + ctoi(left[i]) + ctoi(right[i]);
        stack[top++] = x % 10;
        x /= 10;
    }
    //最后的进位
    if (x > 0) {
        stack[top++] = x;
    }
    while (top != 0) {
        *left++ = itoc(stack[--top]);
    }
    *left = '\0';
}

int main(void)
{
    char a[1010], b[1010];
    int count = 0;

    scanf("%s", a);
    while (!isPal(a) && count < 10) {
        getReverse(b, a);
        printf("%s + %s = ", a, b);
        sum(a, b);
        printf("%s\n", a);
        ++count;
    }
    if (isPal(a)) {
        printf("%s is a palindromic number.\n", a);
    }
    else {
        printf("Not found in 10 iterations.\n");
    }

    return 0;
}
