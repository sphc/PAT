#include <stdio.h>

int main(void)
{
    int count[10] = {0};
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        ++count[c - '0'];
    }

    for (int i = 0; i < 10; ++i) {
        if (count[i]) {
            printf("%d:%d\n", i, count[i]);
        }
    }

    return 0;
}

