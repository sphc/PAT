#include <iostream>
#include <vector>

//解题思路:
//1.将元素存入一个vector nums
//2.用一个vector count统计每个元素出现的次数
//3.遍历nums,查看每个元素在count中的值,即其
//出现的次数,若为1,则说明是第一个unique number

using namespace std;

int main()
{
    int n, winner = 0;
    vector<int> nums; //保存元素,主要目的是保存元素出现的次序
    vector<int> count(10010, 0); //下标表示元素,值表示该元素出现次数

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;

        cin >> x;
        if (x >= 1 && x <= 10000) {
            nums.push_back(x);
            ++count[x];
        }
    }

    for (const auto x : nums) {
        if (count[x] == 1) {
            winner = x;
            break;
        }
    }

    if (winner) {
        cout << winner << endl;
    }
    else {
        cout << "None" << endl;
    }

    return 0;
}
