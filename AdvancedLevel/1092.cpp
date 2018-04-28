#include <iostream>
#include <map>

//解题思路
//用map存储,下标为字符,值为该字符的个数
//遍历需求串,并将其每个字符的个数与商品串中该字符的个数做差
//若差值大于0,则说明该字符缺少,将该差值(即该字符缺少的个数)累加到shortage变量
//每一次从商品串中减去该字符的需求个数(若不够,将其值赋0),这样最终该串中的字符个数即多余的字符数

using namespace std;

//m中字符的总数
int sum(const map<char, int> &m)
{
    int s = 0;

    for (auto i = m.cbegin(); i != m.cend(); ++i) {
        s += i->second;
    }

    return s;
}

int main()
{
    map<char, int> goods, need;
    int shortage = 0; //缺少的个数
    int c;

    while ((c = cin.get()) != EOF && c != '\n') {
        ++goods[c];
    }
    while ((c = cin.get()) != EOF && c != '\n') {
        ++need[c];
    }
    for (const auto &x : need) {
        int tmp = x.second - goods[x.first];

        if (tmp >= 0) {
            shortage += tmp;
            goods[x.first] = 0;
        }
        else {
            goods[x.first] -= x.second;
        }
    }
    if (shortage) {
        cout << "No " << shortage << endl;
    }
    else {
        cout << "Yes " << sum(goods) << endl;
    }

    return 0;
}
