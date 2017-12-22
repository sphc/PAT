#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    long long k; //整数部分
    long long a; //分子
    long long b; //分母
    bool inf; //是否inf
} Fraction;

void swap(long long *a, long long *b)
{
    long long  x;
    
    x = *a;
    *a = *b;
    *b = x;
}

//求最大公约数
long long gcd(long long m, long long n)
{
    if (m < n) {
        swap(&m, &n);
    }
    if (n == 0) {
        return m;
    }

    return gcd(n, m % n);
}

void init(Fraction *fraction)
{ 
    fraction->k = fraction->a = 0;
    fraction->b = 1;
    fraction->inf = false;
}

//化简
void simplify(Fraction *fraction)
{
    //分母为0
    if (fraction->b == 0) {
        fraction->inf = true;

        return;
    }
    fraction->k = fraction->a / fraction->b;
    //符号移到整数部分
    if (fraction->k < 0) {
        fraction->a = fabs(fraction->a);
    }
    fraction->a %= fraction->b;
    if (fraction->a != 0) {
        int factor = gcd(fraction->b, fabs(fraction->a));

        fraction->b /= factor;
        fraction->a /= factor;
    }
}

//将整数部分化到分数部分
void extend(Fraction *fraction)
{
    //k小于0表示为负数,将符号复原到分数部分
    if (fraction->k < 0) {
        fraction->a = -fraction->a;
    }
    fraction->a += fraction->k * fraction->b;
    fraction->k = 0;
}

//输入一个分数
void input(Fraction *fraction)
{ 
    scanf("%lld/%lld", &fraction->a, &fraction->b); 
    simplify(fraction);
}

void plus(Fraction *left, Fraction *right, Fraction *result)
{
    extend(left);
    extend(right);
    result->a = left->a * right->b + left->b * right->a;
    result->b = left->b * right->b;
    simplify(left);
    simplify(right);
    simplify(result);
}

void subtract(Fraction *left, Fraction *right, Fraction *result)
{
    extend(left);
    extend(right);
    result->a = left->a * right->b - left->b * right->a;
    result->b = left->b * right->b;
    simplify(left);
    simplify(right);
    simplify(result);
}

void multiply(Fraction *left, Fraction *right, Fraction *result)
{
    extend(left);
    extend(right);
    result->a = left->a * right->a;
    result->b = left->b * right->b;
    simplify(left);
    simplify(right);
    simplify(result);
}

void divide(Fraction *left, Fraction *right, Fraction *result)
{
    extend(left);
    extend(right);
    result->a = fabs(left->a) * right->b;
    result->b = left->b * fabs(right->a);
    if (left->a < 0 && right->a >= 0 || 
        left->a >= 0 && right->a < 0) {
        result->a = -result->a;
    }
    simplify(left);
    simplify(right);
    simplify(result);
}

void output_(const Fraction *fraction)
{
    if (fraction->k) {
        printf("%lld", fraction->k);
        //分数部分不为零时才打印空格
        if (fraction->a) {
            putchar(' ');
        }
    }
    if (fraction->a) {
        printf("%lld/%lld", fraction->a, fraction->b);
    }
}

//输出一个分数
void output(const Fraction *fraction)
{
    if (fraction->inf) {
        printf("Inf");
        return;
    }

    if (fraction->k < 0 || fraction->a < 0) {
        printf("(");
        output_(fraction);
        printf(")");
    }
    else if (fraction->k > 0 || fraction->a > 0) {
        output_(fraction);
    }
    else if (fraction->k == 0) { //整数部分和分数部分都为零
        printf("0");
    }
}

int main(void)
{
    Fraction a, b, c;

    init(&a);
    init(&b);
    init(&c);
    input(&a);
    input(&b);

    plus(&a, &b, &c);
    output(&a);
    printf(" + ");
    output(&b);
    printf(" = ");
    output(&c);
    printf("\n");
    subtract(&a, &b, &c);
    output(&a);
    printf(" - ");
    output(&b);
    printf(" = ");
    output(&c);
    printf("\n");
    multiply(&a, &b, &c);
    output(&a);
    printf(" * ");
    output(&b);
    printf(" = ");
    output(&c);
    printf("\n");
    divide(&a, &b, &c);
    output(&a);
    printf(" / ");
    output(&b);
    printf(" = ");
    output(&c);
    printf("\n");

    return 0;
}
