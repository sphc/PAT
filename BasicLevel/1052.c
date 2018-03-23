#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int SIZE = 12;

//读取一个字符集合
void getCollection(char s[][5], int *size)
{
    int c;
    int count = 0;

    while (true) {
        int i = 0;

        while ((c = getchar()) != EOF && c != '\n' && c != '[') {
        }
        if (c == EOF || c == '\n') {
            break;
        }
        while ((c = getchar()) != EOF && c != '\n' && c != ']') {
            s[count][i++] = c;
        }
        if (c == EOF || c == '\n') {
            break;
        }
        s[count][i] = '\0';
        ++count;
    }
    *size = count;
}

int main(void)
{
    char hand[SIZE][5];
    char eye[SIZE][5];
    char mouth[SIZE][5];
    int size1, size2, size3; //三个数组的元素个数
    int k;

    getCollection(hand, &size1);
    getCollection(eye, &size2);
    getCollection(mouth, &size3);

    scanf("%d", &k);
    while (k--) {
        int leftHand, rightHand;
        int leftEye, rightEye;
        int m;

        scanf("%d%d%d%d%d", &leftHand, &leftEye, &m, &rightEye, &rightHand);
        if (leftHand < 1 || leftHand > size1 || rightHand < 1 || 
            rightHand > size1 || leftEye < 1 || leftEye > size2 || 
            rightEye < 1 || rightEye > size2 || m < 1 || m > size3) {
            printf("Are you kidding me? @\\/@\n");
        }
        else {
            printf("%s(%s%s%s)%s\n", hand[leftHand - 1], eye[leftEye - 1], 
                    mouth[m - 1], eye[rightEye - 1], hand[rightHand - 1]);
        }
    }

    return 0;
}
