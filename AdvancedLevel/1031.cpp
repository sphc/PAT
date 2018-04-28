#include <iostream>
#include <string>

//解题思路:
//1.计算n1,n2:通过循环枚举找k的最大取值即n1,同时保存n2的值
//2.将字符填入二维数组,U型之外的部分以空格填充

using namespace std;

//以U型打印s
void printU(const string &s)
{
    int n1 = 0, n2, size = s.size();
    char tmp[100][100];

    //计算n1,n2
    int t = size;
    while (t >= 3) {
        int k = t;
        while (k) {
            if (2 * k + t - 2 == size) {
                if (n1 < k) {
                    n1 = k;
                    n2 = t;
                }
                break;
            }
            --k;
        }
        --t;
    }

    //以空格填充
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            tmp[i][j] = ' ';
        }
    }

    //字符填入矩阵
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n1 - 1; ++i) {
        tmp[x++][y] = s[z++];
    }
    for (int i = 0; i < n2; ++i) {
        tmp[x][y++] = s[z++];
    }
    --y;
    for (int i = 0; i < n1; ++i) {
        tmp[--x][y] = s[z++];
    }

    //打印
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            cout << tmp[i][j];
        }
        cout << endl;
    }
}

int main()
{
    string s;

    cin >> s;
    printU(s);

    return 0;
}
