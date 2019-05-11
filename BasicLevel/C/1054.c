#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100

//若字符串s合法则将其转换为double并赋予*num,返回true,否则返回false
bool sToDouble(const char *s, double *num)
{
    double intPart = 0, decimalPart = 0;
    int i = 0, j;

    //点出现在首部,非法
    if (s[i] == '.') {
        return false;
    }
    //第一个字符为负,跳过
    if (s[i] == '-') {
        ++i;
    }

    //累加整数部分
    while (s[i] && s[i] != '.') {
        if (!isdigit(s[i])) {
            return false;
        }
        intPart = intPart * 10 + s[i++] - '0';
    }

    //将j置于小数点后的位置
    j = s[i] == '.' ? i + 1 : i;

    //考虑末尾带点非法会导致测试点过不去
    /*
    if (j == i + 1 && s[j] == '\0') {
        return false;
    }
    */

    //累加小数部分
    while (s[j]) {
        //j - i > 2代表精度超过2
        if (!isdigit(s[j]) || j - i > 2) {
            return false;
        }
        decimalPart = decimalPart * 10 + s[j++] - '0';
    }

    //将小数点置回原位
    while (j-- > i + 1) {
        decimalPart /= 10;
    }

    intPart += decimalPart;

    //范围之外,非法
    if (intPart < -1000 || intPart > 1000) {
        return false;
    }

    *num = intPart;
    //补上负号
    if (s[0] == '-') {
        *num *= -1;
    }

    return true;
}

int main(void)
{
    int n;
    char s[SIZE];
    double num, sum = 0;
    int count = 0; //合法数的个数

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (sToDouble(s, &num)) {
            sum += num;
            ++count;
        }
        else {
            printf("ERROR: %s is not a legal number\n", s);
        }
    }

    if (count) {
        printf("The average of %d %s is %.2f\n", count, 
                count == 1 ? "number" : "numbers", sum / count);
    }
    else {
        printf("The average of 0 numbers is Undefined\n");
    }

    return 0;
}
