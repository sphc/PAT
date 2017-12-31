#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int first; //行下标
    int second; //列下标
} Pair;

void setAttributes(Pair *pair, int first, int second)
{
    pair->first = first;
    pair->second = second;
}

int getFirst(const Pair *pair)
{ return pair->first; }

int getSecond(const Pair *pair)
{ return pair->second; }

bool isExisted(const int matrix [][1010], int n, int m, const Pair *pair)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = getFirst(pair);
            int y = getSecond(pair);

            if (!(i == x && j == y) && matrix[i][j] == matrix[x][y]) {
                return true;
            }
        }
    }

    return false;
}

void inputMatrix(int matrix [][1010], int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

//row, col处的值是否满足
bool isDifference(const int matrix [][1010], int n, int m, int row, int col, int tol)
{
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (i >= 0 && i < n && //行下标合法
                j >= 0 && j < m && //列下标合法
                !(i == row && j == col) && //不是本身
                (fabs(matrix[i][j] - matrix[row][col]) <= tol)) {
                return false;
            }
        }
    }

    return true;
}

int main(void)
{
    int m, n, tol;
    //像素矩阵
    int matrix[1010][1010];
    //可能结果的行列下标
    Pair maybe[1010];
    int size = 0;
    //结果个数
    int count = 0;
    int result; //结果下标

    scanf("%d%d%d", &m, &n, &tol);
    inputMatrix(matrix, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isDifference(matrix, n, m, i, j, tol)) {
                setAttributes(maybe + size++, i, j);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        if (!isExisted(matrix, n, m, maybe + i)) {
            ++count;
            result = i;
        }
    }
    if (count > 1) {
        printf("Not Unique\n");
    }
    else if (count == 1) {
        int i = getFirst(maybe + result);
        int j = getSecond(maybe + result);

        printf("(%d, %d): %d\n", j + 1, i + 1, matrix[i][j]);
    }
    else {
        printf("Not Exist\n");
    }

    return 0;
}
