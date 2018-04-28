#include <cstdio>
#include <map>

//解题思路:
//1.map存储,下标为颜色值,值为出现次数,找出出现次数最多的颜色值即可
//2.用cin会超时

using namespace std;

int main()
{
    int m, n;
    map<int, int> colors;

    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;

            scanf("%d", &x);
            ++colors[x];
        }
    }

    map<int, int>::const_iterator max = colors.begin();
    for (map<int, int>::const_iterator i = colors.begin(); i != colors.end(); ++i) {
        if (i->second > max->second) {
            max = i;
        }
    }

    printf("%d\n", max->first);

    return 0;
}
