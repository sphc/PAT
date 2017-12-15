#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//一周的表示
const char *week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

//判断是否大写字母
bool isCapital(int c)
{ return c >= 'A' && c <= 'N'; }

void appointment(const char *s1, const char *s2, const char *s3, const char *s4)
{
    bool first = true; //是否是第一次
    const char *start = s3; //记录开始位置

    while (*s1 && *s2) {
        if (*s1 == *s2) {
            if (first && *s1 >= 'A' && *s1 <= 'G') { //满足第一个条件，打印星期
                printf("%s ", week[*s1 - 'A']);
                first = false;
            }
            else if (!first && (*s1 >= 'A' && *s1 <= 'N' || isdigit(*s1))) { //满足第二个条件，打印时钟
                printf("%.2d:", (isalpha(*s1)) ? *s1 - 'A' + 10 : *s1 - '0');
                break;
            }
        }
        ++s1;
        ++s2;
    }

    while (*s3 && *s4) {
        if (isalpha(*s3) && *s3 == *s4) { //满足第三个条件，打印秒钟
            printf("%.2d", (int)(s3 - start));
            break;
        }
        ++s3;
        ++s4;
    }
    putchar('\n');
}

int main(void)
{
    char s1[61], s2[61], s3[61], s4[61];

    scanf("%s%s%s%s", s1, s2, s3, s4);
    appointment(s1, s2, s3, s4);    

    return 0;
}
