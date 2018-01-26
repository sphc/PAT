#include <stdio.h>

void swap(int *left, int *right)
{
    int x;

    x = *left;
    *left = *right;
    *right = x;
}

int main(void)
{
    int a[110];
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    m %= n;
    //当m <= n / 2时，可以用swap完成右移
    if (m <= n / 2) {
        for (int i = n - 1; i >= m; --i) {
            swap(a + i, a + (i + m) % n);
        }
    }
    else { //否则相当于左移n - m位
        m = n - m;
        for (int i = 0; i < n - m; ++i) {
            swap(a + i, a + (i - m + n) % n);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", a[i]);
    }
    putchar('\n');

    return 0;
}
