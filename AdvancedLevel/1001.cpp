#include <iostream>

//解题思路:
//1.计算这两个数的和
//2.通过递归打印
//递归的时候记录当前位置,若该位置后的数的个数能被3整除,则打印逗号

using namespace std;

//正整数的长度
int lenOfNum(int num)
{
    int len = 0;
    
    while (num) {
        num /= 10;
        ++len;
    }

    return len;
}

void _print(int num, int len, int &count)
{
    if (num) {
        _print(num / 10, len, count);
        cout << num % 10;
        //若后面的数的个数能被3整除则打印逗号
        if (++count != len && (len - count) % 3 == 0) {
            cout << ",";
        }
    }
}

void printFormat(int num)
{
    int count = 0; //已打印数的个数
    int len = lenOfNum(num);

    if (num < 0) {
        cout << "-";
        num = -num;
    }

    if (num == 0) {
        cout << "0";
    }
    else {
        _print(num, len, count);
    }
}

int main()
{
    int a, b;

    cin >> a >> b;
    printFormat(a + b);
    cout << endl;

    return 0;
}
