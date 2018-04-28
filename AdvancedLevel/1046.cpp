#include <iostream>
#include <vector>
#include <algorithm>

//解题思路:
//1.用一个vector保存距离d
//2.通过输入的路口,累加它们之间的距离放入distance
//再将其与sum - distance相比,较小的即路口间最短距离

using namespace std;

int main()
{
    int n, m;
    int sum = 0; //di的和
    vector<int> d;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;

        cin >> x;
        d.push_back(x);
        sum += x;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int first, second;
        int distance = 0; //路口间的距离

        cin >> first >> second;
        if (first > second) {
            swap(first, second);
        }
        for (int i = first; i < second; ++i) {
            distance += d[i - 1];
        }
        cout << min(distance, sum - distance) << endl;
    }

    return 0;
}
