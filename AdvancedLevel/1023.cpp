#include <iostream>
#include <algorithm>
#include <string>

//解题思路:
//1.数存入string
//2.用另一个string保存doubling后的结果
//3.sort排序后若一样,则第doubling后的数是原数的一个排列

using namespace std;

string doubling(string num)
{
    int flag = 0; //进位

    for (string::reverse_iterator i = num.rbegin(); i != num.rend(); ++i) {
        int digit = flag + (*i - '0') * 2;
        flag = digit / 10;
        *i = digit % 10 + '0';
    }

    if (flag) {
        num = static_cast<char>(flag + '0') + num;
    }

    return num;
}

int main()
{
    string original, result, tmp;

    cin >> original;
    tmp = result = doubling(original); 
    sort(original.begin(), original.end());
    sort(tmp.begin(), tmp.end());
    cout << (tmp == original ? "Yes" : "No") << endl;
    cout << result << endl;

    return 0;
}
