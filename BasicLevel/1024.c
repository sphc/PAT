#include <stdio.h>
#include <stdbool.h>

char num[10010];

int main(void)
{
    int size = 0; 
    int count = 0; //E与指数符号之后的值
    int c;
    bool notZero = false;
    char sym; 

    //如果第一个符号是负，则打印
    sym = getchar();
    //将到E为止的数存入数组
    while ((c = getchar()) != 'E') {
        num[size++] = c;
        if (c != '.' && c != '0') {
            notZero = true;
        }
    }
    num[size] = '\0';
    //打印符号
    if (sym == '-' && notZero) {
        putchar('-');
    }

    sym = getchar(); //指数符号
    while ((c = getchar()) != '\n' && c != EOF) {
        count = count * 10 + c - '0';
    }
    //指数为0，原样打印
    if (count-- == 0) {
        printf("%s", num);
    }
    else if (sym == '-') {
        printf("0.");
        while (count--) {
            putchar('0');
        }
        for (int i = 0; i < size; ++i) {
            if (num[i] != '.') {
                putchar(num[i]);
            }
        }
    }
    else if (sym == '+') {
        //size-2表示小数点后的数字的个数,因为count之前已经自减一次，所以这里减3
        count -= size - 3;
        if (count > 0) { //点的位置超过数字部分长度，则不必打印
            for (int i = 0; i < size; ++i) {
                if (num[i] != '.') {
                    putchar(num[i]);
                }
            }
            while (count--) { //打印多出的0
                putchar('0');
            }
        }
        else {
            for (int i = 0; i < size; ++i) {
                if (i == count + size) { //在恰当位置打印点
                    putchar('.');
                }
                if (num[i] != '.') {
                    putchar(num[i]);
                }
            }
        }
    }
    putchar('\n');

    return 0;
}
