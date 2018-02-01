#include <iostream>
#include <cmath>

//解题思路:
//本题并没有什么难点,关键是对于题意的理解,这个radix表示基数
//一个数的reverse版本即为它的radix进制表示反转后再转换为10进制的值
//如:输入23, 2; 
//23为素数,它的reverse版本为:
//23->(2进制表示)10111->(反转)11101->(10进制)29
//29也为素数,故输出Yes

using namespace std;

//判断是否素数
bool isPrime(int num)
{
    if (num < 2) {
        return false;
    }

    for (int i = 2; i < floor(sqrt(num) + 1); ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

//10进制数num的reverse版本
int reverse(int num, int radix)
{
    int result = 0;

    //num每次对radix取余恰好是其radix进制的反转表示
    //此时顺便计算出其十进制值即可
    while (num) {
        result = result * radix + num % radix;
        num /= radix;
    }

    return result;
}

int main()
{
    int n, d;

    while (cin >> n) {
        if (n < 0) {
            break;
        }
        cin >> d;
        cout << (isPrime(n) && isPrime(reverse(n, d)) ? "Yes" : "No") << endl;
    }

    return 0;
}

