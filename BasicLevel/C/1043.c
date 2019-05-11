#include <stdio.h>

int main(void)
{
    int count[6] = {0}; //用于统计各字符个数 
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        switch(c) {
            case 'P' : ++count[0]; break;
            case 'A' : ++count[1]; break;
            case 'T' : ++count[2]; break;
            case 'e' : ++count[3]; break;
            case 's' : ++count[4]; break;
            case 't' : ++count[5]; break;
        }
    }
    while (count[0] > 0 || count[1] > 0 || count[2] > 0 ||
           count[3] > 0 || count[4] > 0 || count[5] > 0) {
        if (count[0]-- > 0) {
            putchar('P');
        }
        if (count[1]-- > 0) {
            putchar('A');
        }
        if (count[2]-- > 0) {
            putchar('T');
        }
        if (count[3]-- > 0) {
            putchar('e');
        }
        if (count[4]-- > 0) {
            putchar('s');
        }
        if (count[5]-- > 0) {
            putchar('t');
        }
    }
    putchar('\n');

    return 0;
}
