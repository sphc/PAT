#include <stdio.h>

int main(void) {
    int T, K;

    scanf("%d%d", &T, &K);
    for (int i = 0; i < K; ++i) {
        int n1, b, t, n2;

        scanf("%d%d%d%d", &n1, &b, &t, &n2);
        if (T == 0) {
            printf("Game Over.\n");
            break;
        }
        if (t > T) {
            printf("Not enough tokens. Total = %d.", T);
        }
        else if (b == 0 && n1 > n2 || b == 1 && n1 < n2) {
            T += t;
            printf("Win %d! Total = %d.", t, T);
        }
        else {
            T -= t;
            printf("Lose %d. Total = %d.", t, T);
        }
        putchar('\n');
    }

    return 0;
}
