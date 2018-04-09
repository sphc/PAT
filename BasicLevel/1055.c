#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10010

typedef struct {
    char name[10];
    int height;
} People;

//输入属性
void inputPeople(People *people)
{ scanf("%s%d", people->name, &people->height); }

//按身高降序,若身高相等则按名字升序
int cmp(const void *left, const void *right)
{ 
    if (((People *)right)->height != ((People *)left)->height) {
        return ((People *)right)->height - ((People *)left)->height; 
    }
    else {
        return strcmp(((People *)left)->name, ((People *)right)->name);
    }
}

int main(void)
{
    People people[SIZE];
    char *result[12][SIZE];
    int n, k;
    int count, lastCount; //分别代表每行人数和最后一行人数
    int cur = 0; 
    int mid; //中间位置
    int diff; //与mid的距离

    scanf("%d%d", &n, &k);
    count = n / k;
    lastCount = count + n % k;
    for (int i = 0; i < n; ++i) {
        inputPeople(people + i);
    }

    qsort(people, n, sizeof(People), cmp);

    for (int i = 0; i < k; ++i) {
        int rCount = (i ? count : lastCount); //当前行人数
        diff = 1;
        mid = (i ? count : lastCount) / 2;

        result[i][mid] = people[cur++].name;
        while ((cur - lastCount) % rCount != 0) {
            result[i][mid - diff] = people[cur++].name;
            if ((cur - lastCount) % rCount == 0) {
                break;
            }
            result[i][mid + diff] = people[cur++].name;
            ++diff;
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (i ? count : lastCount); ++j) {
            if (j) {
                printf(" ");
            }
            printf("%s", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
