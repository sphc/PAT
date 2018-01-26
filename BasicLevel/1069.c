#include <stdio.h>
#include <string.h>

#define NPOS -1

int find(const char names[][21], int size, const char *str)
{
    for (int i = 0; i < size; ++i) {
        if (strcmp(names[i], str) == 0) {
            return i;
        }
    }

    return NPOS;
}

int main(void)
{
    int m, n;
    char names[1010][21]; //中奖网友
    int size = 0;
    int preOrder; //上一次中奖序号

    scanf("%d%d%d", &m, &n, &preOrder);
    //curOrder:当前序号
    for (int curOrder = 1; curOrder <= m; ++curOrder) {
        char name[21];

        scanf("%s", name);
        if (curOrder - n == preOrder || curOrder == preOrder) { 
            //读到下一个未出现的编号
            while (find(names, size, name) != NPOS && curOrder <= m) {
                scanf("%s", name);
                ++curOrder;
            }
            if (curOrder <= m) {
                printf("%s\n", name); 
                preOrder = curOrder;
                strcpy(names[size++], name); //保存中奖网友
            }
        }
    }
    if (size == 0) {
        printf("Keep going...\n");
    }

    return 0;
}
