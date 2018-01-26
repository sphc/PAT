#include <stdio.h>
#include <ctype.h>

void input(char *a, char *b)
{
    int c;

    while (isspace(c = getchar())) {
    }
    *a = c;
    getchar();
    *b = getchar();
}

int main(void)
{
    int n;
    char result[110];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char a, b; //a:选项，b:真假
        
        for (int j = 0; j < 4; ++j) {
            input(&a, &b);
            if (b == 'T') {
                result[i] = a - 'A' + '1';
            }
        }
    }
    result[n] = '\0';
    puts(result);

    return 0;
}
