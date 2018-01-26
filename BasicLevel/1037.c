#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int galleon;
    int sickle;
    int knut;
} Money;

void inputMoney(Money *money)
{ scanf("%d.%d.%d", &money->galleon, &money->sickle, &money->knut); }

void printMoney(const Money *money)
{ printf("%d.%d.%d", money->galleon, money->sickle, money->knut); }

//left大于等于right
bool isBiggerOrEqual(const Money *left, const Money *right)
{ 
     return (left->galleon > right->galleon) ||
            (left->galleon == right->galleon && left->sickle > right->sickle) ||
            (left->galleon == right->galleon && left->sickle == right->sickle && 
             left->knut >= right->knut); 
}

//减法
void subtract(const Money *left, const Money *right, Money *result)
{
    if (isBiggerOrEqual(left, right)) {
        result->galleon = left->galleon - right->galleon;
        result->sickle = left->sickle - right->sickle;
        result->knut = left->knut - right->knut;
        //如果小于0，则表明需要借位
        if (result->knut < 0) {
            result->knut += 29;
            --result->sickle;
        }
        if (result->sickle < 0) {
            result->sickle += 17;
            --result->galleon;
        }
    }
    else { //此时表明为负数
        subtract(right, left, result);
        result->galleon = -result->galleon;
    }
}

int main(void)
{
    Money p, a, c;

    inputMoney(&p);
    inputMoney(&a);
    subtract(&a, &p, &c);
    printMoney(&c);
    putchar('\n');

    return 0;
}
