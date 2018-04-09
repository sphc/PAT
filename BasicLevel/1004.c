#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    char name[11]; //姓名
    char num[11];  //学号
    int grade;     //年龄
} Student;

//用于保存一对指向最高成绩和最低成绩的学生的指针
typedef struct {
    Student *first;
    Student *second;
} Pair;

//构造Pair
Pair *constructPair(Student *first, Student *second)
{
    Pair *pair = malloc(sizeof(Pair));

    if (!pair) {
        exit(-1);
    }
    else {
        pair->first = first;
        pair->second = second;

        return pair;
    }
}

//释放Pair
void freePair(Pair *pair)
{ free(pair); }

//输入学生属性
void inputAttributes(Student *student)
{
    scanf("%s", student->name);
    scanf("%s", student->num);
    scanf("%d", &student->grade);
}

//获取成绩最高与成绩最低的学生，并保存在Pair中
Pair *getMax_MinStudent(Student *students, int size)
{
    int max = INT_MIN, min = INT_MAX;
    int maxIndex = 0, minIndex = 0;

    for (int i = 0; i < size; ++i) {
        if ((students + i)->grade > max) {
            max = (students + i)->grade;
            maxIndex = i;
        }
        if ((students + i)->grade < min) {
            min = (students + i)->grade;
            minIndex = i;
        }
    }

    return constructPair(students + maxIndex, students + minIndex);
}

//打印结果
void printInfo(const Pair *pair)
{
    printf("%s %s\n", pair->first->name, pair->first->num);
    printf("%s %s\n", pair->second->name, pair->second->num);
}

int main(void)
{
    Student students[1000];
    Pair *result;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        inputAttributes(students + i);
    }
    result = getMax_MinStudent(students, n);
    printInfo(result);
    freePair(result);

    return 0;
}
