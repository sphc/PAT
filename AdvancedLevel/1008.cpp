#include <iostream>

//解题思路:
//模拟电梯运行过程

using namespace std;

int main()
{
    int n;
    int total = 0; //总时间
    int start = 0; //保存起始位置

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int floor; //请求楼层

        cin >> floor;
        //电梯上升
        if (floor > start) {
            total += (floor - start) * 6 + 5;
        }
        else { //电梯下降
            total += (start - floor) * 4 + 5;
        }

        start = floor;
    }

    cout << total << endl;

    return 0;
}
