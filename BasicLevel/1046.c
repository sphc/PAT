#include <stdio.h>

int main(void)
{
    int n;
    int jia = 0, yi = 0; //甲乙分别喝的酒的杯数

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int jiahan, jiahua, yihan, yihua;

        scanf("%d%d%d%d", &jiahan, &jiahua, &yihan, &yihua);
        if (jiahua != yihua) {
            if (jiahua == jiahan + yihan) {
                ++yi;
            }
            else if (yihua == jiahan + yihan) {
                ++jia;
            }
        }
    }
    printf("%d %d\n", jia, yi);

    return 0;
}
