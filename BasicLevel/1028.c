#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[7];
    char birth[12];
} Resident;

//年龄合理
bool ageValid(const Resident *resident)
{
    return strcmp(resident->birth, "2014/09/06") <= 0 &&
           strcmp(resident->birth, "1814/09/06") >= 0;
}

int cmp(const void *first, const void *second)
{
    const Resident *resident1 = first;
    const Resident *resident2 = second;

    return strcmp(resident1->birth, resident2->birth);
}

Resident residents[100010];

int main(void)
{
    int n, age;
    int count = 0; //有效生日个数

    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", residents[count].name, &residents[count].birth);
        //若年龄合理，才录入
        if (ageValid(residents + count)) {
            ++count;
        }
    }
    qsort(residents, count, sizeof(Resident), cmp);
    if (count > 0) {
        printf("%d %s %s\n", count, residents[0].name, residents[count - 1].name);
    }
    else {
        printf("0\n");
    }

    return 0;
}
