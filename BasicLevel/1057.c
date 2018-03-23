#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[100010];
    int sum = 0, oneCount = 0, zeroCount = 0;

    fgets(str, 100010, stdin);
    for (int i = 0; i < strlen(str); ++i) {
        if (isalpha(str[i])) {
            sum += tolower(str[i]) - 'a' + 1;
        }
    }
    while (sum) {
        if (sum & 1) {
            ++oneCount;
        }
        else {
            ++zeroCount;
        }
        sum >>= 1;
    }
    printf("%d %d\n", zeroCount, oneCount);

    return 0;
}
