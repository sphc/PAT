#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 18

//权重
const int weight[SIZE - 1] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
//校验码
const char *verify = "10X98765432";

bool isValid(const char *id)
{
    int sum = 0;

    for (int i = 0; i < SIZE - 1; ++i) {
        if (!isdigit(id[i])) {
            return false;
        }
        sum += (id[i] - '0') * weight[i];
    }

    return verify[sum % 11] == id[SIZE - 1] ; 
}

int main(void)
{
    int n;
    char id[SIZE];
    int count = 0; //不合法个数

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", id);
        if (!isValid(id)) {
            printf("%s\n", id);
            ++count;
        }
    }

    if (!count) {
        printf("All passed\n");
    }

    return 0;
}
