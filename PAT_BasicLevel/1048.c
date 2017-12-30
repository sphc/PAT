#include <stdio.h>
#include <math.h>
#include <string.h>

//十三进制的表示
const char *thirteen = "0123456789JQK";

//字符转整数
int ctoi(int c)
{ return c - '0'; }

int main(void)
{
    char a[1010], b[1010];
    char result[1010];
    int alen, blen; //a的长度，b的长度
    int pos = 1; //位置,用以判断是奇数位还是偶数位
    int difference;
    char *p, *q, *r;

    scanf("%s%s", a, b);
    alen = strlen(a);
    blen = strlen(b);
    difference = fabs(blen - alen);
    r = result;
    //长度短的数高位补0
    while (difference--) {
        *r++ = '0';
    }
    if (blen < alen) {
        strcpy(r, b);
        strcpy(b, result);
        blen = strlen(b);
    }
    else {
        strcpy(r, a);
        strcpy(a, result);
        alen = strlen(a);
    }

    p = a + alen - 1;
    q = b + blen - 1;
    r = result + blen - 1;
    while (r >= result) {
        int tmp;

        if (pos++ % 2) {
            tmp = (ctoi(*p--) + ctoi(*q--)) % 13;
        }
        else if ((tmp = ctoi(*q--) - ctoi(*p--)) < 0) {
            tmp += 10;
        }
        *r-- = thirteen[tmp];
    }
    printf("%s\n", result);

    return 0;
}
