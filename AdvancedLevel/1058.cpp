#include <iostream>

//解题思路:
//实现货币的加法运算,比较简单

using namespace std;

class Currency {
public:
    friend istream &operator >> (istream &is, Currency &currency);
    friend ostream &operator << (ostream &os, const Currency &currency);
    friend Currency operator + (const Currency &left, const Currency &right);

    Currency() = default;
    Currency(int g, int s, int k) : galleon{g}, sickle{s}, knut{k}
    { }

private:
    int galleon;
    int sickle;
    int knut;
};

istream &operator >> (istream &is, Currency &currency) 
{
    char c;
    is >> currency.galleon >> c >> currency.sickle >> c >> currency.knut;
    return is;
}

ostream &operator << (ostream &os, const Currency &currency)
{ return os << currency.galleon << "." << currency.sickle << "." << currency.knut; }

Currency operator + (const Currency &left, const Currency &right)
{
    int galleon, sickle, knut;

    knut = left.knut + right.knut;
    sickle = left.sickle + right.sickle + knut / 29;
    knut %= 29;
    galleon = left.galleon + right.galleon + sickle / 17;
    sickle %= 17;

    return {galleon, sickle, knut};
}

int main()
{
    Currency a, b;

    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}
