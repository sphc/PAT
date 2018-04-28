#include <iostream>
#include <string>
#include <vector>

//解题思路:
//用string保存密码,遍历替换,若有替换的字符,
//则将该账户存入vector中,最后检查vector.size()
//不为0则打印之,并打印vector中的元素
//否则输出提示信息

using namespace std;

class Account {
public:
    void input()
    { cin >> username >> password; }

    void show() const
    { cout << username << " " << password; }

    bool modified()
    {
        bool changed = false;

        for (auto &x : password) {
            switch (x) {
                case '1' : x = '@'; changed = true; break;
                case '0' : x = '%'; changed = true; break;
                case 'l' : x = 'L'; changed = true; break;
                case 'O' : x = 'o'; changed = true; break;
            }
        }

        return changed;
    }
private:
    string username;
    string password;
};

int main()
{
    int n;
    vector<Account> result;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        Account account;

        account.input();
        if (account.modified()) {
            result.push_back(std::move(account));
        }
    }

    if (result.size()) {
        cout << result.size() << endl;
        for (const auto &x : result) {
            x.show();
            cout << endl;
        }
    }
    else {
        cout << "There " << (n == 1 ? "is" : "are") << " " << n 
             << " " << (n == 1 ? "account" : "accounts") 
             << " and no account is modified" << endl;
    }

    return 0;
}
