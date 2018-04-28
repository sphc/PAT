#include <iostream>
#include <string>
#include <cctype>
#include <set>

//解题思路:
//用一个set good保存第二次输入中出现过的字符,这些按键是完好的
//用一个set exist保存已经输出过的字符,避免多次输出同一字符
//对原始字符串中的每一个字符,到good和exist中查找,若均未找到,
//则说明该键是坏的,并且是第一次遇到,输出之,并将其存入exist

using namespace std;

int main()
{
    set<char> good, exist; //good:打印的字符中完好的按键,exist:已经输出的字符
    string origin; //原始字符串
    int c;

    getline(cin, origin);
    while ((c = cin.get()) != EOF) {
        good.insert(toupper(c));
    }
    for (auto x : origin) {
        char tmp = toupper(x);
        if (good.find(tmp) == good.end() && exist.find(tmp) == exist.end()) {
            cout << tmp;
            exist.insert(tmp);
        }
    }
    cout << endl;

    return 0;
}
