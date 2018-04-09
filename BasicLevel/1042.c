#include <stdio.h>
#include <ctype.h>

#define SIZE 129

int count[SIZE] = {0}; //统计各字符个数

int main(void)
{
    int c;
    int max = 0;

    //统计字符
    while ((c = getchar()) != EOF && c != '\n') {
        if (isalpha(c)) {
            ++count[tolower(c)];
        }
    }
    //找到出现次数最多的字符,保存在max中
    for (int i = 'a'; i <= 'z'; ++i) {
        if (count[max] < count[i]) {
            max = i;
        }
    }
    printf("%c %d\n", max, count[max]);

    return 0;
}
