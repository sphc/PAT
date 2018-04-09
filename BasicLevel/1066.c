#include <stdio.h>

int main(void)
{
    int m, n;
    int a, b;
    int value; //替换值

    scanf("%d%d", &m, &n);
    scanf("%d%d", &a, &b);
    scanf("%d", &value);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int v;

            scanf("%d", &v);
            if (j) {
                putchar(' ');
            }
            if (v >= a && v <= b) {
                printf("%.3d", value);
            }
            else {
                printf("%.3d", v);
            }
        }
        putchar('\n');
    }
    
    return 0;
}
