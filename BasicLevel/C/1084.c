#include <stdio.h>

#define SIZE 100000

int main(void)
{
    int n;
    int a[SIZE], result[SIZE]; //这里使用两个数组,以避免值被覆盖造成的错误
    int size = 0;

    scanf("%d%d", result + size++, &n);
    while (--n) {
        int tmp = 0;
        for (int i = 0; i < size; ++i) {
            int count = 1;

            a[tmp++] = result[i];
            //计算连续的相同值的个数
            while (i + 1 < size && result[i] == result[i + 1]) {
                ++count;
                ++i;
            }
            a[tmp++] = count;
        }
        //结果拷贝回去
        for (int i = 0; i < tmp; ++i) {
            result[i] = a[i];
        }
        size = tmp;
    }

    //打印结果
    for (int i = 0; i < size; ++i) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}
