#include <stdio.h>
#include <stdbool.h>

bool compare(double a, double b, double c)
{ return a + b > c; }

int main(void)
{
    int n, a, b, c;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        printf("Case #%d: %s\n", i + 1, compare(a, b, c) ? "true" : "false");
    }

    return 0;
}
