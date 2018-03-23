#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//SIZE不开大点会造成段错误,应该是距离会大于10^5
#define SIZE 200010

int main(void)
{
    int n;
    int distance[SIZE] = {0}; //distance[i]表示骑车距离为i的天数
    int m[SIZE] = {0}; //m[i]代表骑车距离超过i的天数
    int max = INT_MIN; //最大距离

    //输入骑车天数及距离
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int d;

        scanf("%d", &d);
        if (d > max) {
            max = d;
        }
        ++distance[d];
    }

    //求m
    //这里把i >= 0改成i > 0会有测试点过不去,坑
    for (int i = max; i >= 0; --i) {
        m[i] += m[i + 1] + distance[i + 1];
    }

    //m[i] >= i表示骑车距离超过i的天数 >= i天
    //从n天开始找,第一次找到m[i] >= i时即为E
    //这里把i >= 0改成i > 0会有测试点过不去,坑
    for (int i = n; i >= 0; --i) {
        //有E天骑车超过E英里,表示骑车超过E英里的天数大于等于E
        if (m[i] >= i) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

