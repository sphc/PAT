#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//解题思路:
//在输入时多次使用查找会导致运行超时,
//我这里先将输入项保存到一个数组中,
//然后进行排序,这样学校相同的项将会位于相邻位置,
//第二遍遍历的时候将其成绩汇总并计算加权总分,
//再保存到结果数组

#define SIZE 100010

typedef struct Grade {
    char school[10];//学校
    int grade;      //加权总分
    int count;      //人数
} Grade;

typedef struct InputInfo {
    char id[10];    //准考证号
    int grade;      //得分
    char school[10];//学校
} InputInfo;

int cmp_in(const void *left, const void *right)
{ return strcmp(((const InputInfo *)left)->school, 
                ((const InputInfo *)right)->school); }

int cmp_g(const void *left, const void *right)
{ 
    const Grade *first = left, *second = right;

    if (first->grade != second->grade) {
        return second->grade - first->grade; 
    }
    if (first->count != second->count) {
        return first->count - second->count; 
    }
    return strcmp(first->school, second->school);
}

void initGrade(Grade *grade)
{ grade->count = 0; }

//将字符串s转为小写
void Lower(char *s)
{ 
    while (*s) {
        *s = tolower(*s);
        ++s;
    }
}

int main(void)
{
    int n, rank = 1;    //rank:排名
    Grade grades[SIZE]; //保存结果
    InputInfo in[SIZE]; //保存输入项
    int size = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%s", in[i].id, &in[i].grade, in[i].school);
        Lower(in[i].school);
    }
    qsort(in, n, sizeof(InputInfo), cmp_in);

    for (int i = 0; i < n; ) {
        int j;
        int basic = 0;      //乙级
        int advance = 0;    //甲级
        int top = 0;        //顶级

        initGrade(grades + size);
        strcpy(grades[size].school, in[i].school);
        //找出学校相同的输入项,并将成绩汇总
        for (j = i; j < n && strcmp(in[j].school, in[i].school) == 0; ++j) {
            ++grades[size].count;
            switch(in[j].id[0]) {
                case 'A' : advance += in[j].grade; break;
                case 'B' : basic += in[j].grade; break;
                case 'T' : top += in[j].grade; break;
            }
        }
        //计算加权总分
        grades[size++].grade = basic / 1.5 + advance + top * 1.5; 
        i = j;
    }
    qsort(grades, size, sizeof(Grade), cmp_g);

    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
        //若和上一名成绩不同,则排名为下标加一
        if (i && grades[i].grade != grades[i - 1].grade) {
            rank = i + 1;
        }
        printf("%d %s %d %d\n", rank, grades[i].school, grades[i].grade, grades[i].count);
    }

    return 0;
}
