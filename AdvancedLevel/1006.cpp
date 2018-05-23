#include <iostream>
#include <string>

//解题思路:
//找最早的进入时间和最晚的离开时间

using namespace std;

class Time {
public:
    friend istream &operator >> (istream &is, Time &time);
    friend bool operator < (const Time &lhs, const Time &rhs);

    Time(int hour = 0, int minute = 0, int second = 0) :
        h{hour}, m{minute}, s{second} { }

private:
    int h, m, s;
};

class Record {
public:
    friend istream &operator >> (istream &is, Record &record);

    Record() { }
    Record(const string &idNumber,
           const Time &signInTime,
           const Time &signOutTime) :
        id{idNumber}, signIn{signInTime},
        signOut{signOutTime} { }

    string getId() const { return id; }
    Time getSignIn() const { return signIn; }
    Time getSignOut() const { return signOut; }
private:
    string id;
    Time signIn;
    Time signOut;
};

istream &operator >> (istream &is, Time &time)
{
    char c;
    is >> time.h >> c >> time.m >> c >> time.s;
    return is;
}

istream &operator >> (istream &is, Record &record)
{
    is >> record.id >> record.signIn >> record.signOut;
    return is;
}

bool operator < (const Time &lhs, const Time &rhs)
{
    if (lhs.h < rhs.h) {
        return true;
    } else if (lhs.h == rhs.h) {
        if (lhs.m < rhs.m) {
            return true;
        } else if (lhs.m == rhs.m) {
            return lhs.s < rhs.s;
        }
    }

    return false;
}

int main()
{
    Record max{"0", Time{ }, Time{ }}, min{"0", Time{23, 59, 59}, Time{23, 59, 59}}, tmp;
    int m;

    cin >> m;
    while (m--) {
        cin >> tmp;
        if (tmp.getSignIn() < min.getSignIn()) {
            min = tmp;
        }
        if (max.getSignOut() < tmp.getSignOut()) {
            max = tmp;
        }
    }
    cout << min.getId() << " " << max.getId() << endl;

    return 0;
}
