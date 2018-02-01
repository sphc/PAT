#include <iostream>
#include <iomanip>

//解题思路:
//每次从三个数里找最大值,输出其标志,并累乘到收益中
//最后按公式计算结果

using namespace std;

const int SIZE = 3;

int main()
{
    double profit = 1;

    for (int i = 0; i < SIZE; ++i) {
        double w, t, l;

        cin >> w >> t >> l;
        if (w > t && w > l) {
            cout << "W" << " ";
            profit *= w;
        }
        else if (t > w && t > l) {
            cout << "T" << " ";
            profit *= t;
        }
        else if (l > w && l > t) {
            cout << "L" << " ";
            profit *= l;
        }
    }
    profit = (profit * 0.65 - 1) * 2;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << profit << endl;

    return 0;
}
