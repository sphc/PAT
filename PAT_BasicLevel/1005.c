#include <stdio.h>
#include <stdbool.h>

void guessPlus(const int *a, int size)
{
    int flag[110] = {0};
    bool first = true;

    for (int i = 0; i < size; ++i) {
        int tmp = a[i];

        while (tmp != 1) {
            if (tmp % 2) {
                tmp = (3 * tmp + 1) / 2;
            }
            else {
                tmp /= 2;
            }
            flag[tmp] = 1;
        }
    }
    for (int i = size - 1; i > -1; --i) {
        if (flag[a[i]]) {
            first = false;
            if (!first) {
                putchar(' ');
            }
            printf("%d", i);
        }
    }
}

int main(void)
{
    int a[110];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    guessPlus(a, n);

    return 0;
}
