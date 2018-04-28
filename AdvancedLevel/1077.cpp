#include <iostream>
#include <stack>
#include <string>

//解题思路:
//先用一个变量保存第一个字符串
//然后每次与新的字符串取最长公共后缀,并更新之

using namespace std;

//获取最长公共后缀
string getMaxSuffix(const string left, const string right)
{
    string result;
    stack<char> s;

    for (auto i = left.crbegin(), j = right.crbegin(); 
            i != left.crend() && j != right.crend() && *i == *j; 
            ++i, ++j) {
        s.push(*i);
    }
    while (!s.empty()) {
        result.push_back(s.top());    
        s.pop();
    }

    return result;
}

int main()
{
    int n;
    string s, result;

    cin >> n;
    getline(cin, result); //读掉末尾的回车
    getline(cin, result); //第一行字符串
    while (--n) {
        getline(cin, s);
        result = getMaxSuffix(result, s);
    }

    cout << (!result.empty() ? result : "nai")  << endl;

    return 0;
}
