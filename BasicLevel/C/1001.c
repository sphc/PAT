#include <stdio.h>

int guess(int n)
{
    int count = 0;

    while (n != 1) {
	n = (n % 2 ? 3 * n + 1 : n) / 2;
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

