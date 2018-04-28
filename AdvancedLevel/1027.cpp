#include <iostream>
#include <string>

//解题思路:
//比较简单,只需将每个数转换为13进制

using namespace std;

//转换num为13进制
string trans(int num)
{
    string result;

    while (num) {
        char digit;
        if (num % 13 > 9) {
            digit = num % 13 - 10 + 'A';
        }
        else {
            digit = num % 13 + '0';
        }
        result = digit + result;
        num /= 13;
    }
    //补0,用while是考虑num为0的情况
    while (result.size() < 2) {
        result = "0" + result;
    }

    return result;
}

int main()
{
    int first, second, third;

    cin >> first >> second >> third;
    cout << "#" << trans(first) << trans(second) << trans(third) << endl;

    return 0;
}
