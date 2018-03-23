#include <stdio.h>

void drawSquare(int n, char c)
{
    int cow = ((double)n / 2) + 0.5;
    for (int i = 0; i < cow; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == cow - 1 || j == 0 || j == n - 1) {
                putchar(c);
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(void)
{
    int n, c;

    scanf("%d %c", &n, &c);
    drawSquare(n, c);

    return 0;
}
