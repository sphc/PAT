#include <stdio.h>
#include <stdbool.h>

//判断一个数是否素数
bool isPrime(int num)
{
    if (num < 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

//生成一个大于num的素数
int generatePrime(int num)
{
    if (num < 1) {
        return 1;
    }

    while (!isPrime(++num)) {
    }

    return num;
}

int primeGuess(int n)
{
    int count = 0; //满足条件的素数对个数
    int prim1, prim2; // 用于保存第n个素数和第n+1个素数

    prim1 = 1; //第一个素数
    while ((prim2 = generatePrime(prim1)) <= n) { 
        if (prim2 - prim1 == 2) { 
            ++count;
        }
        prim1 = prim2;
    }

    return count;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", primeGuess(n));

    return 0;
}
