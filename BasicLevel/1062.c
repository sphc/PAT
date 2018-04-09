#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x; //分子
    int y; //分母
} Fraction;

//最大公因数
int gcd(int m, int n)
{ return n ? gcd(n, m % n) : m; }

//输入分数
void inputFraction(Fraction *fraction)
{ scanf("%d/%d", &fraction->x, &fraction->y); }

//打印分数
void printFraction(const Fraction *fraction)
{ printf("%d/%d", fraction->x, fraction->y); }

//交换两个分数
void swap(Fraction *left, Fraction *right)
{
    Fraction tmp = *left;
    *left = *right;
    *right = tmp;
}

//设置分数的值
void setFraction(Fraction *fraction, int x, int y)
{
    fraction->x = x;
    fraction->y = y;
}

//left < right则返回true
bool isLess(const Fraction *left, const Fraction *right)
{ return left->x * right->y < right->x * left->y; }

//left == right则返回true
bool isEqual(const Fraction *left, const Fraction *right)
{ return left->x * right->y == right->x * left->y; }

int main(void)
{
    int k;
    bool first = true;
    Fraction a, b;

    inputFraction(&a);
    inputFraction(&b);
    scanf("%d", &k);

    if (!isLess(&a, &b)) {
        swap(&a, &b);
    }

    for (int i = 1; i < k; ++i) {
        Fraction c;

        setFraction(&c, i, k);
        //跳过小于等于a的分数
        if (isLess(&c, &a) || isEqual(&c, &a)) {
            continue;
        }
        //大于等于b则跳出
        if (!isLess(&c, &b)) {
            break;
        }

        //分子分母没有公约数时打印
        if (gcd(i, k) == 1) {
            if (!first) {
                printf(" ");
            }
            printFraction(&c);
            first = false;
        }
    }
    printf("\n");

    return 0;
}
