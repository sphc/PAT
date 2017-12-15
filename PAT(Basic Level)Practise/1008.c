#include <stdio.h>

void moveArray(int *array, int size, int m)
{
}

int main(void)
{
    int n, m;
    int *array;

    scanf("%d%d", &n, &m);
    array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", array + i);
    }
    moveArray(array, n, m);

    return 0;
}
