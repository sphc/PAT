#include <iostream>
#include <string>
#include <set>
#include <cctype>

//解题思路:
//1.用string保存s1,set保存s2
//2.遍历s1,若s2中有,则不打印

using namespace std;

int main()
{
    string s1;
    set<char> s2;
    char c;
    
    getline(cin, s1);
    while ((c = cin.get()) != '\n') {
        s2.insert(c);
    }

    for (auto x : s1) {
        if (s2.find(x) == s2.end()) {
            cout << x;
        }
    }
    cout << endl;

    return 0;
}
