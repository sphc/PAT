#include <stdio.h>
#include <stdbool.h>

//下标表示查缴物品编号,true表示该编号物品为查缴物品
bool contraband[10000] = {0};

int main(void)
{
    int n, m;
    int studentCount = 0; //存在问题学生数
    int conCount = 0; //被查缴物品数

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x; //查缴物品编号
        
        scanf("%d", &x);
        contraband[x] = true;
    }

    for (int i = 0; i < n; ++i) {
        char name[10];
        int num[15]; //被查缴物品编号
        int k; //个人物品数
        int size = 0;

        scanf("%s%d", name, &k);
        for (int j = 0; j < k; ++j) {
            int x;//个人物品编号

            scanf("%d", &x);
            if (contraband[x]) {
                num[size++] = x;
            }
        }
        if (size > 0) {
            ++studentCount;
            printf("%s:", name);
            for (int l = 0; l < size; ++l) {
                printf(" %.4d", num[l]);
            }
            printf("\n");
        }
        conCount += size;
    }
    printf("%d %d\n", studentCount, conCount);

    return 0;
}
