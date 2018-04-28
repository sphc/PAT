#include <iostream>
#include <list>
#include <vector>

//解题思路:
//1.将数字转换为base进制表示,结果存入一个vector中,
//其中vector的每一个元素为数字的一位,
//如: 200的160进制在vector中保存为: 1 40
//2.判断该vector保存的数是否回文

using namespace std;

//将num转换为base进制表示,结果存入result
void trans(int num, int base, vector<int> &result)
{
    list<int> tmp;

    if (num == 0) {
        tmp.push_front(num);
    }

    while (num) {
        tmp.push_front(num % base);
        num /= base;
    }
    for (list<int>::const_iterator i = tmp.cbegin(); i != tmp.cend(); ++i) {
        result.push_back(*i);
    }
}

//num是回文则返回true,否则返回false
bool isPalindromicity(const vector<int> &num)
{
    vector<int>::const_iterator i = num.cbegin(), j = num.cend() - 1;

    while (i < j && *i == *j) {
        ++i;
        --j;
    }

    return i >= j;
}

int main()
{
    int n, b;
    vector<int> result;

    cin >> n >> b;
    trans(n, b, result);
    cout << (isPalindromicity(result) ? "Yes" : "No") << endl;
    for (vector<int>::size_type i = 0; i < result.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;

    return 0;
}
