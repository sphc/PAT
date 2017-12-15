#include <stdio.h>
#include <stdlib.h>

int combine(int a, int b)
{ return a * 10 + b; }

int combineSum(int *nums, int size)
{
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                sum += combine(nums[i], nums[j]);
            }
        }
    }

    return sum;
}

int main(void)
{
    int n;
    int *nums;

    scanf("%d", &n);
    nums = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", nums + i);
    }
    printf("%d\n", combineSum(nums, n));

    return 0;
}
