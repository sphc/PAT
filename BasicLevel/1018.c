#include <stdio.h>
#include <limits.h>

#define SIZE 3 //手势个数

typedef struct {
    int win; //胜次数
    int draw; //平次数
    int lose; //负次数
} Grade;

//初始化
void initGrade(Grade *grade)
{
    grade->win = 0;
    grade->draw = 0;
    grade->lose = 0;
}

//统计胜的手势的次数，a[0]统计B次数，a[1]统计C次数，a[2]统计J次数
//按字母从小到大排列，如果解不唯一，到时候可输出字母序最小的解
void countGesture(int *a, char gesture)
{
    switch (gesture) {
        case 'B' : ++a[0]; break;
        case 'C' : ++a[1]; break;
        case 'J' : ++a[2]; break;
    }
}

//根据索引得到手势
char getGesture(int index)
{
    char gesture;

    switch (index) {
        case 0 : gesture = 'B'; break;
        case 1 : gesture = 'C'; break;
        case 2 : gesture = 'J'; break;
    }

    return gesture;
}

//输出成绩
void printGrade(const Grade *grade)
{ printf("%d %d %d\n", grade->win, grade->draw, grade->lose); }

//取得最大索引
int getMax(const int *a, int size)
{
    int max = INT_MIN;
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (max < a[i]) {
            max = a[i];
            index = i;
        }
    }

    return index;
}

//输入手势
void inputGesture(char *gesture)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch == 'B' || ch == 'C' || ch == 'J') {
            *gesture = ch;
            return;
        }
    }
}

int main(void)
{
    int n;
    char jia, yi; //甲、乙所出手势
    Grade gradeOfJia, gradeOfYi; //甲、乙最终成绩
    int countOfJia[SIZE] = {0}; //甲获胜手势及次数
    int countOfYi[SIZE] = {0}; //乙获胜手势及次数

    //初始化
    initGrade(&gradeOfJia);
    initGrade(&gradeOfYi);

    //输入并统计
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        inputGesture(&jia);
        inputGesture(&yi);
        if (jia == yi) {
            ++gradeOfJia.draw;
            ++gradeOfYi.draw;
        }
        else if (jia == 'C' && yi == 'J' || 
                 jia == 'J' && yi == 'B' || 
                 jia == 'B' && yi == 'C') {
            ++gradeOfJia.win;
            ++gradeOfYi.lose;
            countGesture(countOfJia, jia);
        }
        else {
            ++gradeOfJia.lose;
            ++gradeOfYi.win;
            countGesture(countOfYi, yi);
        }
    }

    //打印结果
    printGrade(&gradeOfJia);
    printGrade(&gradeOfYi);
    printf("%c %c\n", getGesture(getMax(countOfJia, SIZE)), 
            getGesture(getMax(countOfYi, SIZE)));

    return 0;
}
