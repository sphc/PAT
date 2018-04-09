#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define SIZE 30010

//解题思路:
//1.将数据全部存储到一个数组中,然后按学号排序,目的是使学号相同的元素相邻
//2.遍历数组,并将学号相同的相邻项合并
//3.计算总评并检查是否合法,若合法,则保存至另一个数组,否则丢弃这个结果

typedef struct {
    char num[35]; //学号
    int program; //编程成绩
    int middle; //期中成绩
    int final; //期末成绩
    int grade; //期终成绩
} Student;

int cmp(const void *left, const void *right)
{ return strcmp(((Student *)left)->num, ((Student *)right)->num); }

int cmp2(const void *left, const void *right)
{
    const Student *first = left;
    const Student *second = right;

    return first->grade == second->grade ? 
        strcmp(first->num, second->num) : second->grade - first->grade;
}

//初始化
void initStudent(Student *student)
{
    student->program = INT_MIN;
    student->middle = INT_MIN;
    student->final = INT_MIN;
    student->grade = INT_MIN;
}

//打印student信息
void printStudent(const Student *student) 
{
    printf("%s ", student->num);
    printf("%d ", student->program != INT_MIN ? student->program : -1);
    printf("%d ", student->middle != INT_MIN ? student->middle : -1);
    printf("%d ", student->final != INT_MIN ? student->final : -1);
    printf("%d\n", student->grade != INT_MIN ? student->grade : -1);
}

//将right拷贝至left
void copyStudent(Student *left, const Student *right)
{
    strcpy(left->num, right->num);
    left->program = right->program;
    left->middle = right->middle;
    left->final = right->final;
    left->grade = right->grade;
}

//合并属性,若left未录入,则将right赋予它
void addAttribute(int *left, int right)
{
    if (*left == INT_MIN) {
        *left = right;
    }
}

//将left与right的成绩相加并存入left中
void addStudent(Student *left, const Student *right)
{
    addAttribute(&left->program, right->program);
    addAttribute(&left->middle, right->middle);
    addAttribute(&left->final, right->final);
}

//计算期终成绩,返回值true表示成绩合格,false表示不合格
bool calculateGrade(Student *student)
{
    student->grade = student->middle > student->final ? 
        student->middle * 0.4 + student->final * 0.6 + 0.5 : student->final;

    return student->program >= 200 && student->grade >= 60;
}


int main(void)
{
    int p, m, n;
    int studentSize = 0, resultSize = 0;
    Student students[SIZE];
    Student result[SIZE];

    //读入数据
    scanf("%d%d%d", &p, &m, &n);
    for (int i = 0; i < p; ++i) {
        initStudent(students + studentSize);
        scanf("%s%d", students[studentSize].num, &students[studentSize].program);
        ++studentSize;
    }
    for (int i = 0; i < m; ++i) {
        initStudent(students + studentSize);
        scanf("%s%d", students[studentSize].num, &students[studentSize].middle);
        ++studentSize;
    }
    for (int i = 0; i < n; ++i) {
        initStudent(students + studentSize);
        scanf("%s%d", students[studentSize].num, &students[studentSize].final);
        ++studentSize;
    }

    //按学号排序,目的是将学号相同的元素放在相邻位置,便于合并
    qsort(students, studentSize, sizeof(Student), cmp);

    for (int i = 0; i < studentSize; ++i) {
        //先将students[i]拷贝至result[resultSize]
        copyStudent(result + resultSize, students + i);
        //将学号相等的元素加到result[resultSize],即合并成绩
        //因同一学号至多出现三次,并且每一次只含有一项成绩,故不会多加
        while (i + 1 < studentSize && strcmp(result[resultSize].num, students[i + 1].num) == 0) {
            ++i;
            addStudent(result + resultSize, students + i);
        }
        //计算总评,若不合格则丢弃
        if (calculateGrade(result + resultSize)) {
            ++resultSize;
        }
    }

    //总评分数递减,并列则学号递增排序
    qsort(result, resultSize, sizeof(Student), cmp2);

    //打印结果
    for (int i = 0; i < resultSize; ++i) {
        printStudent(result + i);
    }

    return 0;
}
