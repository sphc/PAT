#include <stdio.h>
#include <limits.h>

int a[100010] = {0};

int main(void)
{
    int n;
    int num, grade;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &num, &grade);
        a[num] += grade;
    }
    grade = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        //找出得分最高者,保存在grade和num中
        if (a[i] > grade) {
            grade = a[i];
            num = i;
        }
    }
    printf("%d %d\n", num, grade); 

    return 0;
}
