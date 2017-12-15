#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int num;
    int morality;
    int possibility;
    int sumOfGrade;
} Student;

//初始化数组
void initStudents(Student **students, size_t size)
{
    *students = malloc(sizeof(Student) * size);
    memset(*students, 0, sizeof(Student) * size);
}

//设置学生属性
void setAttribute(Student *student, int num, int morality, int possibility)
{ 
    student->num = num;
    student->morality = morality;
    student->possibility = possibility;
    student->sumOfGrade = student->morality + student->possibility;
}

//输出students
void printStudents(Student *students, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d %d %d\n", students[i].num, 
                students[i].morality, students[i].possibility);
    }
}

// 按总成绩降序排序，若总成绩相等，按德分降序，若德分相等，按学号升序
int cmp(const void *student1, const void *student2)
{
    Student *first = (Student *)student1;
    Student *second = (Student *)student2;

    if (first->sumOfGrade != second->sumOfGrade) {
        return second->sumOfGrade - first->sumOfGrade;
    }
    else if (first->morality != second->morality) {
        return second->morality - first->morality;
    }
    else {
        return first->num - second->num;
    }
}

int main(void)
{
    int n, l, h; //n:考生数; l:录取最低分数线; h:优先录取线
    int num, morality, possibility;
    int size1 = 0, size2 = 0, size3 = 0, size4 = 0;
    Student *students1, *students2, *students3, *students4;

    scanf("%d%d%d", &n, &l, &h);
    initStudents(&students1, n);
    initStudents(&students2, n);
    initStudents(&students3, n);
    initStudents(&students4, n);

    //输入学生数据，并分类
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &num, &morality, &possibility);
        if (morality < l || possibility < l) {
            continue;
        }
        if (morality >= h && possibility >= h) {
            setAttribute(students1 + size1++, num, morality, possibility);
        }
        else if (morality >= h) {
            setAttribute(students2 + size2++, num, morality, possibility);
        }
        else if (morality >= possibility) {
            setAttribute(students3 + size3++, num, morality, possibility);
        }
        else {
            setAttribute(students4 + size4++, num, morality, possibility);
        }
    }

    //排序
    qsort(students1, size1, sizeof(Student), cmp);
    qsort(students2, size2, sizeof(Student), cmp);
    qsort(students3, size3, sizeof(Student), cmp);
    qsort(students4, size4, sizeof(Student), cmp);

    //输出结果
    printf("%d\n", size1 + size2 + size3 + size4);
    printStudents(students1, size1);
    printStudents(students2, size2);
    printStudents(students3, size3);
    printStudents(students4, size4);

    return 0;
}
