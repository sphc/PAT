#include <stdio.h>
#include <stdbool.h>

//表示未找到
#define NPOS -1 
//已找过
#define VISITED -2222

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int find(const int *arr, int size, int value)
{
    static int visited[10010] = {0};

    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            if (visited[i]) {
                return VISITED;
            }
            else {
                visited[i] = 1;

                return i;
            }
        }
    }

    return NPOS;
}

int main(void)
{
    int final[10010] = {0}; //下标为最终排名减一，值为ID
    int n, k;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", final + i);
    }
    scanf("%d", &k);
    while (k--) {
        int id;
        int rank; //排名

        scanf("%d", &id);
        printf("%.4d: ", id);
        rank = find(final, n, id);
        switch (rank) {
            case 0 : printf("Mystery Award\n"); break;
            case NPOS : printf("Are you kidding?\n"); break;
            case VISITED : printf("Checked\n"); break;
            //因为数组索引从0开始，所以这里要加1
            default: printf("%s\n", isPrime(rank + 1) ? "Minion" : "Chocolate"); break;
        }
    }

    return 0;
}
