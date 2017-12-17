#include <stdio.h>

//打印n个sym符号，spaceCount前导空格数
void printNSym(int spaceCount, int n, char sym)
{
    if (n > 0) {
        while (spaceCount--) {
            putchar(' ');
        }
        while (n--) {
            putchar(sym);
        }
        putchar('\n');
    }
}

//打印最外层end个sym字符的沙漏
//max表示最多一层字符的个数，用于控制空格数目
void printHourglass(int max, int end, char sym)
{
    int spaceCount = (max - end) / 2;

    if (end < 3) {
        printNSym(spaceCount, end, sym);
    }
    else {
        printNSym(spaceCount, end, sym);
        printHourglass(max , end - 2, sym);
        printNSym(spaceCount , end, sym);
    }
}

//计算能打印的最外层字符的个数,并将剩余字符保存在left中
int calculate(int n, char sym, int *left)
{
    int end = n > 0 ? 1 : 0; //最后一层字符的个数
    n -= end;

    //计算最多能打印的一层的字符的个数end
    //end + 2表示每增加一层字符数加2，乘以2表示有对称的两层
    while (n - (end + 2) * 2 >= 0) {
        end += 2;
        n -= end * 2;
    }
    *left = n;

    return end;
}

int main(void)
{
    int n, left, end;
    char sym;

    scanf("%d %c", &n, &sym);
    end = calculate(n, sym, &left),
    printHourglass(end, end, sym);
    printf("%d\n", left);

    return 0;
}
