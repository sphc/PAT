#include <stdio.h>
#include <float.h>
#include <stdlib.h>

typedef struct {
    double weight; //库存
    double price;  //单价
} Moncake;

int cmp(const void *first, const void *second)
{
    const Moncake *moncake1 = first;
    const Moncake *moncake2 = second;
    double difference;
    
    difference = moncake2->price / moncake2->weight - 
                 moncake1->price / moncake1->weight;
    if (difference > FLT_EPSILON) {
        return 1;
    }
    else if (difference < -FLT_EPSILON) {
        return -1;
    }
    else {
        return 0;
    }
}

int main(void)
{
    int n, d; //n：月饼种数，d：市场最大需求量
    double result = 0;
    double currentWeight = 0;
    Moncake *moncakes;

    scanf("%d%d", &n, &d);
    //分配内存
    moncakes = (Moncake *)malloc(sizeof(Moncake) * n);
    //输入库存
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &moncakes[i].weight);
    }
    //输入价格
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &moncakes[i].price);
    }

    //按单价从大到小排序
    qsort(moncakes, n, sizeof(Moncake), cmp);
    //计算收益
    for (int i = 0; i < n; ++i) {
        //当前月饼总重量与之前已近选择的重量之和小于最大需求，则全部选择
        if (moncakes[i].weight + currentWeight <= d) {
            result += moncakes[i].price;
            currentWeight += moncakes[i].weight;
        }
        else { //否则选则可以达到最大需求的量
            result += (d - currentWeight) / moncakes[i].weight * moncakes[i].price;
            break;
        }
    }
    //输出结果
    printf("%.2f\n", result);

    return 0;
}
