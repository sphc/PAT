#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define ANSWER_SIZE 110

typedef struct {
    char option; //选项
    int count; //错误次数
} MistakeOption;

typedef struct {
    int score; //满分
    int count; //选项个数
    int correct; //正确选项个数
    char options[10]; //答案选项
    MistakeOption mistakeOptions[10]; //选错选项
    int mistakeSize; //选错选项个数
    int maxMistakeCount; //最大选错次数
} Answer;

typedef struct {
    int num; //题目编号
    char mistakeOptions[10]; //错的最多的选项
} Result;

int cmp(const void *left, const void *right)
{ return ((Result *)left)->num - ((Result *)right)->num; }

int cmp2(const void *left, const void *right)
{ return *(char *)left - *(char *)right; }

//字符转整数
int ctoi(char c)
{ return c - '0'; }

//读取选项,并存入option
void readChoice(char *options, int size)
{
    int c;
    char *p = options;

    while ((c = getchar()) != EOF && c != '\n' && p - options < size) {
        //忽略空白
        while (isspace(c)) {
            c = getchar();
        }
        *p++ = c;
    }
    *p = '\0';
}

//输入答案
void inputAnswer(Answer *answer)
{
    scanf("%d%d%d", &answer->score, &answer->count, &answer->correct);
    readChoice(answer->options, 10);
    answer->mistakeSize = 0;
    answer->maxMistakeCount = 0;
}

//将错误选项mistakeOption加入到answer中
void pushMistake(Answer *answer, char mistakeOption)
{
    bool existed = false;

    //若已存在,增加其计数器
    for (int i = 0; i < answer->mistakeSize; ++i) {
        if (answer->mistakeOptions[i].option == mistakeOption) {
            if (answer->maxMistakeCount < ++answer->mistakeOptions[i].count) {
                answer->maxMistakeCount = answer->mistakeOptions[i].count;
            }
            existed = true;
            break;
        }
    }
    //不存在则添加到其中
    if (!existed) {
        answer->mistakeOptions[answer->mistakeSize].option = mistakeOption;
        answer->mistakeOptions[answer->mistakeSize++].count = 1;
        if (answer->maxMistakeCount < 1) {
            answer->maxMistakeCount = 1;
        }
    }
}

//找出错误的选项并添加到answer,若全错则返回TRUE,否则返回false
//全错：即options中包含错误选项
bool findMistake(Answer *answer, char *options)
{
    int index = 0;
    bool mistake = false;

    while (options[index]) {
        int i = 0;

        while (i < answer->correct && answer->options[i] != options[index]) {
            ++i;
        }
        if (i == answer->correct) {
            pushMistake(answer, options[index]);
            mistake = true;
        }
        ++index;
    }

    for (int i = 0; i < answer->correct; ++i) {
        int cur = 0;

        while (options[cur] && answer->options[i] != options[cur]) {
            ++cur;
        }
        if (!options[cur]) {
            pushMistake(answer, answer->options[i]);
        }
    }

    return mistake;
}

//从answer中找出错误次数最多的选项,存入result中
void getMaxMistakeOptions(const Answer *answer, char *result)
{
    for (int i = 0; i < answer->mistakeSize; ++i) {
        if (answer->mistakeOptions[i].count == answer->maxMistakeCount) {
            *result++ = answer->mistakeOptions[i].option;
        }
    }
    *result = '\0';
}

//读取学生的一题选项答案,存入option
void readStudentChoice(char *options, int size)
{
    int c;
    char *p = options;

    while ((c = getchar()) != EOF && c != '(') {
    }

    while ((c = getchar()) != EOF && c != ')' && p - options < size) {
        //忽略空白
        while (isspace(c)) {
            c = getchar();
        }
        *p++ = c;
    }
    *p = '\0';
}

int main(void)
{
    int n, m;
    Answer answer[ANSWER_SIZE];
    Result result[ANSWER_SIZE];
    int resultSize = 0;
    int max = INT_MIN; //保存错误最多的次数
    char s[100]; //仅用于读取scanf后残余的空白

    scanf("%d%d", &n, &m);
    fgets(s, 100, stdin);

    for (int i = 0; i < m; ++i) {
        inputAnswer(answer + i);
    }
    for (int i = 0; i < n; ++i) {
        double grade = 0;

        for (int j = 0; j < m; ++j) {
            char options[40]; //学生选的选项

            readStudentChoice(options, 40);
            if (!findMistake(answer + j, options + 1)) {
                //ctoi(options[0]) == answer[j].correct说明全对
                grade += answer[j].score / (ctoi(options[0]) == answer[j].correct ? 1.0 : 2.0);
            }
        }
        printf("%.1f\n", grade);
    }

    //找出错误最多的次数
    for (int i = 0; i < m; ++i) {
        if (answer[i].maxMistakeCount > max) {
            max = answer[i].maxMistakeCount;
        }
    }

    //将所有错误次数为max的题的信息存入result
    for (int i = 0; i < m; ++i) {
        if (max && answer[i].maxMistakeCount == max) {
            result[resultSize].num = i + 1;
            getMaxMistakeOptions(answer + i, result[resultSize].mistakeOptions);
            ++resultSize;
        }
    }

    //按编号从小到大排序
    qsort(result, resultSize, sizeof(Result), cmp);

    for (int i = 0; i < resultSize; ++i) {
        char *p = result[i].mistakeOptions;

        //按字母从小到大排序
        qsort(p, strlen(p), sizeof(char), cmp2);
        while (*p) {
            printf("%d %d-%c\n", max, result[i].num, *p);
            ++p;
        }
    }
    
    if (resultSize == 0) {
        printf("Too simple\n");
    }

    return 0;
}
