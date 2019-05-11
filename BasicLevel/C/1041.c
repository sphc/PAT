#include <stdio.h>

#define NPOS -11111 //表示未找到

typedef struct {
    char num[15]; //准考证号
    int testMachineNum; //试机座位号
    int examNum; //考试座位号
} Examinee;

//输入考生信息
void inputAttributes(Examinee *examinee)
{ 
    scanf("%s", examinee->num);
    scanf("%d", &examinee->testMachineNum);
    scanf("%d", &examinee->examNum);
}

//输出考生考试作为信息
void printExamInfo(const Examinee *examinee)
{ printf("%s %d\n", examinee->num, examinee->examNum); }

//通过试机号查找学生,返回下标
int search(const Examinee *examinees, int size, int testMachineNum)
{
    for (int i = 0; i < size; ++i) {
        if (examinees[i].testMachineNum == testMachineNum) {
            return i;
        }
    }

    return NPOS;
}

int main(void)
{
    int n, m;
    Examinee examinees[1010];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        inputAttributes(examinees + i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int testMachineNum;

        scanf("%d", &testMachineNum);
        printExamInfo(examinees + search(examinees, 1010, testMachineNum));
    }

    return 0;
}
