#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100

//读取一行,丢弃换行
void getLine(char *s, int size)
{
    fgets(s, SIZE, stdin);
    s[strlen(s) - 1] = '\0';
}

void check(char *s)
{
    bool hasDigit = false, hasAlpha = false;

    if (strlen(s) < 6) {
        printf("Your password is tai duan le.\n");
        return;
    }
    else {
        while (*s) {
            if (isalpha(*s)) {
                hasAlpha = true;
            }
            else if (isdigit(*s)) {
                hasDigit = true;
            }
            else if (*s != '.') {
                printf("Your password is tai luan le.\n");
                return;
            }
            ++s;
        }
    }
    if (!hasAlpha) {
        printf("Your password needs zi mu.\n");
    } 
    else if (!hasDigit) {
        printf("Your password needs shu zi.\n");
    }
    else {
        printf("Your password is wan mei.\n");
    }
}

int main(void)
{
    int n;
    char s[SIZE];

    scanf("%d", &n);
    getLine(s, SIZE);
    while (n--) {
        getLine(s, SIZE);
        check(s);
    }

    return 0;
}
