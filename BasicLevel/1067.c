#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int SIZE = 25;
const int INPUT_SIZE = 110;

void getLine(char *s, int size)
{
    int c, i = 0;

    while (i++ < size && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    *s = '\0';
}

int main(void)
{
    char password[SIZE];
    char input[INPUT_SIZE];
    const char *end = "#";
    int count;
    int i = 0;

    scanf("%s%d", password, &count);
    getchar();

    getLine(input, INPUT_SIZE);
    while (i < count && strcmp(end, input) != 0) {
        if (strcmp(password, input) == 0) {
            printf("Welcome in\n");
            break;
        }
        else {
            printf("Wrong password: %s\n", input);
        }
        ++i;
        getLine(input, INPUT_SIZE);
    }

    if (i == count) {
        printf("Account locked\n");
    }

    return 0;
}
