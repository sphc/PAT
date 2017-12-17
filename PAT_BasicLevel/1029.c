#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define NPOS -9999 //表示未找到

int cmp(const void *first, const void *second)
{ return strcmp((const char *)first, (const char *)second); }

int binarySearch(char c, const char *arr, int left, int right)
{
    int mid = (left + right) / 2;

    if (left > right) {
        return NPOS;
    }
    if (arr[mid] > c) {
        return binarySearch(c, arr, left, mid - 1);
    }
    else if (arr[mid] < c) {
        return binarySearch(c, arr, mid + 1, right);
    }
    else {
        return mid;
    }
}

void toUpper(char *str)
{
    while (*str) {
        if (isalpha(*str)) {
            *str = toupper(*str);
        }
        ++str;
    }
}

bool exist(const char *str, char sym) {
    while (*str) {
        if (sym == *str) {
            return true;
        }
        ++str;
    }

    return false;
}

int main(void)
{
    char input[90];
    char output[90];
    char result[90];
    int size = 0;

    scanf("%s%s", input, output);
    toUpper(input);
    toUpper(output);
    qsort(output, strlen(output), sizeof(char), cmp);
    for (int i = 0; i < strlen(input); ++i) {
        if (binarySearch(input[i], output, 0, strlen(output)) == NPOS
            && !exist(result, input[i])) {
            result[size++] = input[i];
            result[size] = '\0';
        }
    }
    printf("%s\n", result);

    return 0;
}
