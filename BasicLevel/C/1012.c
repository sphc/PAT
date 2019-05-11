#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    int num;
    bool flag = false; //标记是否有A2
    int sym = 1; //符号位，用于计算A2
    int count = 0; //A4中数的个数
    int a[5] = {0}; // a[0]表示A1，a[1]表示A2...

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        //分类
        switch (num % 5) {
            case 0 : 
                if (num % 2 == 0) {
                    a[0] += num;
                }
                break;
            case 1 : 
                a[1] += sym * num;
                sym = -sym;
                flag = true;
                break;
            case 2 : 
                ++a[2];
                break;
            case 3 : 
                a[3] += num; //累加和
                ++count;     //计算个数，便于之后求平均值
                break;
            case 4 : 
                if (a[4] < num) {
                    a[4] = num;
                }
                break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (i) { //除了第一个外，每个输出前打印一个空格
            putchar(' ');
        }
        if (i == 1) {
            if (flag) {
                printf("%d", a[i]);
            }
            else {
                putchar('N');
            }
        }
        else if (i == 3) {
            if (a[i] > 0) {
                printf("%.1f", (double)a[i] / count);
            }
            else {
                putchar('N');
            }
        }
        else {
            if (a[i] > 0) {
                printf("%d", a[i]);
            }
            else {
                putchar('N');
            }
        }
    }
    putchar('\n');

    return 0;
}
