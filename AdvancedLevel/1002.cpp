#include <iostream>
#include <list>

//解题思路:
//1.使用list,便于插入
//2.重载+=运算符:将b加到a上
//依次比较a和b中每个项的指数,大于a则插入,相等则使系数相加

using namespace std;

//多项式类
class Polynomial {
public:
    friend ostream &operator << (ostream &os, const Polynomial &polynomial);
    //构造函数,输入多项式
    Polynomial()
    {
        int count; //项数

        cin >> count;
        for (int i = 0; i < count; ++i) {
            int exponent;
            double coefficient;

            cin >> exponent >> coefficient;
            //系数不为0则插入尾端
            if (coefficient) {
                data.push_back({exponent, coefficient});
            }
        }
    }

    Polynomial &operator += (const Polynomial &rhs)
    {
        auto i = data.begin(); 
        auto j = rhs.data.begin();

        while (i != data.end() && j != rhs.data.end()) {
            //此时j->exponent更大,将其插入i前
            if (i->exponent < j->exponent) {
                i = data.insert(i, Element{j->exponent, j->coefficient});
                ++j;
            }
            else if (i->exponent == j->exponent) { //指数相等,系数相加
                i->coefficient += j->coefficient;
                //系数相加后为0则删除
                if (i->coefficient == 0) {
                    i = data.erase(i);
                }
                ++j;
            }
            ++i;
        }

        //连接rhs中剩余项
        while (j != rhs.data.end()) {
            data.insert(data.end(), Element{j->exponent, j->coefficient});
            ++j;
        }

        return *this;
    }

private:
    //项的结点
    struct Element {
        int exponent;
        double coefficient;

        Element(int exponent, double coefficient) 
        { this->exponent = exponent; this->coefficient = coefficient;  }
    };

    list<Element> data;
};

//输出多项式
ostream &operator << (ostream &os, const Polynomial &polynomial)
{
    cout << polynomial.data.size();

    cout.setf(ios::fixed);
    cout.precision(1);
    for (auto i = polynomial.data.begin(); i != polynomial.data.end(); ++i) {
        cout << " " << i->exponent << " " << i->coefficient;
    }

    return os;
}

int main()
{
    Polynomial a, b;

    cout << (a += b) << endl;

    return 0;
}
