#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    double result = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int real, imag;
        double m; //模

        scanf("%d%d", &real, &imag);
        if ((m = sqrt(real * real + imag * imag)) > result) {
            result = m;
        }
    }
    printf("%.2f\n", result);

    return 0;
}
