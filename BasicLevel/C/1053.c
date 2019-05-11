#include <stdio.h>

int main(void)
{
    int n, d;
    double e;
    int empty = 0, maybeEmpty = 0; //empty:空置,maybeEmpty:可能空置

    scanf("%d%lf%d", &n, &e, &d);
    for (int i = 0; i < n; ++i) {
        int k;
        int count = 0; //用电量低于e的日子数量

        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            double x; //用电量

            scanf("%lf", &x);
            if (x < e) {
                ++count;
            }
        }
        if (count > k / 2) {
            if (k > d) {
                ++empty;
            }
            else {
                ++maybeEmpty;
            }
        }
    }
    printf("%.1f%% %.1f%%\n", 
            (double)maybeEmpty / n * 100, (double)empty / n * 100);

    return 0;
}
