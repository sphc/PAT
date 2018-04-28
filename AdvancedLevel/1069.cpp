#include <iostream>
#include <algorithm>
#include <string>

//解题思路:
//string保存数字,sort排序,用stod转换后计算

using namespace std;

//转为字符串,占4位,其余位补0
string toString(int num)
{
    string s(4, '0');
    string::reverse_iterator i = s.rbegin();

    while (num && i != s.rend()) {
        *i++ = num % 10 + '0';
        num /= 10;
    }
    
    return s;
}

int main()
{
    string num;
    int result = -1;

    //这样写,使输入0时得到0000而不是0
    int x; 
    cin >> x;
    num = toString(x);

    while (result != 0 && result != 6174) {
        sort(begin(num), end(num), [] (const char &left, const char &right) { return left > right; });
        result = stod(num);
        cout << num << " - ";
        sort(begin(num), end(num));
        result -= stod(num);
        cout << num << " = "; 
        num = toString(result);
        cout << num << endl;
    }

    return 0;
}
