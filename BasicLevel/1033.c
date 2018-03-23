#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NPOS -1 //表示未找到

typedef bool (*valid)(int);

char badKey[100010];

int cmp(const void *first, const void *second)
{ return strcmp((char *)first, (char *)second); }

int binarySearch(int c, int left, int right)
{
    int mid = (left + right) / 2;

    if (left > right) {
        return NPOS;
    }
    else if (badKey[mid] < c) {
        return binarySearch(c, mid + 1, right);
    }
    else if (badKey[mid] > c) {
        return binarySearch(c, left, mid - 1);
    }
    else {
        return mid;
    }
}

//检查是否可以打出
bool check1(int c)
{ 
    if (isalpha(c)) {
        c = toupper(c);
    }

    return binarySearch(c, 0, strlen(badKey)) == NPOS; 
}

//上档键坏了的版本
bool check2(int c)
{ 
    if (isalpha(c) && isupper(c)) {
        return false;
    }

    return check1(c); 
}

int main(void)
{
    int c;
    int flag;
    valid isValid[2] = { check1, check2 }; 

    gets(badKey);
    qsort(badKey, strlen(badKey), sizeof(char), cmp);
    flag = !check1('+'); //若找到'+'号，表示上档键坏了,调用换挡键坏了的检查函数

    while ((c = getchar()) != '\n' && c != EOF) {
        if (isValid[flag](c)) {
            putchar(c);
        }
    }
    putchar('\n');

    return 0;
}
