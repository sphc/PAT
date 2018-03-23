#include <stdio.h>
#include <math.h>

typedef struct {
    double real; //实部
    double imag; //虚部
} Complex;

//输入复数
void inputComplex(Complex *complex)
{
    double r, p;

    scanf("%lf%lf", &r, &p);
    complex->real = r * cos(p);
    complex->imag = r * sin(p);
}

//打印复数
void printComplex(const Complex *complex)
{
    if (complex->real > -0.005 && complex->real < 0) {
        printf("0.00");
    }
    else {
        printf("%.2f", complex->real);
    }
    if (complex->imag > -0.005) {
        putchar('+');
    }
    if (complex->imag > -0.005 && complex->imag < 0) {
        printf("0.00i");
    }
    else {
        printf("%.2fi", complex->imag);
    }
    putchar('\n');
}

//复数乘法
void multiply(const Complex *left, const Complex *right, Complex *result)
{
    result->real = left->real * right->real - left->imag * right->imag;
    result->imag = left->real * right->imag + left->imag * right->real;
}

int main(void)
{
    Complex complex1, complex2, result;

    inputComplex(&complex1);
    inputComplex(&complex2);
    multiply(&complex1, &complex2, &result);
    printComplex(&result);

    return 0;
}
