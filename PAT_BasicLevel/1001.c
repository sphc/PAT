#include <stdio.h>

int guess(int n)
{
    int count = 0;

    while (n != 1) {
        if (n % 2) {
            n = (3 * n + 1) / 2;
        }
        else {
            n /= 2;
        }
        ++count;
    }

    return count;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d", guess(n));

    return 0;
}
