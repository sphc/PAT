#include <stdio.h>
#include <limits.h>

#define SIZE 10010

int main(void)
{
    int n, min = INT_MAX, max = INT_MIN;
    int minNum, maxNum; //与靶心距离最小(最大)的运动员的编号

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num, x, y;
        int distance; //与靶心的距离

        scanf("%d%d%d", &num, &x, &y);
        distance = x * x + y * y;
        if (distance < min) {
            min = distance;
            minNum = num;
        }
        if (max < distance) {
            max = distance;
            maxNum = num;
        }
    }
    printf("%.4d %.4d\n", minNum, maxNum);

    return 0;
}
