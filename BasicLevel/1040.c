#include <stdio.h>

int p[100010] = {0}; //存放P字符的下标
int a[100010] = {0}; //存放A字符的下标
int t[100010] = {0}; //存放T字符的下标
int z[100010] = {0}; //A字符后面的T字符的个数,如：z[3]的值代表a[3]后面的T字符的个数
int x[100010] = {0}; //A字符后面所有z的总和，如：x[3] = z[3] + ... + z[asize - 1]

int main(void)
{
    int c;
    int len = 0; //计算字符的下标
    int count = 0; //满足PAT的数量
    int psize = 0, asize = 0, tsize = 0;

    //保存各字符的下标
    while ((c = getchar()) != EOF && c != '\n') {
        switch (c) {
            case 'P' : p[psize++] = len; break;
            case 'A' : a[asize++] = len; break;
            case 'T' : t[tsize++] = len; break;
       }
       ++len; 
    }

    //计算每个a[i]后面的T的个数，并存入z[i]
    for (int i = 0, tmpj = 0; i < asize && tmpj < tsize; ++i) {
        for (int j = tmpj; j < tsize; ++j) {
            if (a[i] < t[j]) {
                z[i] = tsize - j;
                tmpj = j;
                break;
            }
        }
    }
    //计算x[i]
    for (int i = asize - 1, tmp = 0; i >= 0; --i) {
        tmp += z[i];
        x[i] = tmp;
    }
    //计算count,此时只需要满足p[i]<a[j],则x[j]就代表a[j]（包括a[j]）之后的满足PAT条件的数量
    for (int i = 0, tmpj = 0; i < psize && tmpj < asize; ++i) {
        for (int j = tmpj; j < asize; ++j) {
            if (p[i] < a[j]) {
                count += x[j];
                count %= 1000000007;
                tmpj = j;
                break;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}
