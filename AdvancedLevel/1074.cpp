#include <iostream>
#include <stack>
#include <iomanip>

//解题思路:
//1.用数组存储链表,下标表示其地址
//2.利用堆栈实现反转:每次将n个元素的地址入栈,
//若足够n个元素,则依次出栈并连接到结果链表,若不足,
//则将剩余元素的第一个结点连接到结果链表

using namespace std;

class List {
public:
    friend ostream &operator << (ostream &os, List &l);
    static const int MAXSIZE = 100010;
    static const int null = -1;

    List() 
    {
        head = MAXSIZE - 1; //将数组最后一个元素作为头结点
        elements[head].next = null;
    }

    //size个元素,第一个元素地址为firstAddress
    List(int firstAddress, int size) : List()
    {
        elements[head].next = firstAddress;
        while (size--) {
            int address, data, next;

            cin >> address >> data >> next;
            elements[address].data = data;
            elements[address].next = next;
        }
    }

    //取第一个元素的地址
    int getFirstAdd ()
    { return elements[head].next; }

    int getFirstAdd () const
    { return elements[head].next; }

    //反转链表,每n个元素反转一次
    void reverse(size_t n)
    {
        int p = getFirstAdd();
        int q = head;
        stack<int> s;

        while (p != null) {
            for (size_t i = 0; i < n && p != null; ++i) {
                s.push(p);
                p = elements[p].next;
            }
            //满足n个元素,反转之
            if (s.size() == n) {
                while (!s.empty()) {
                    q = elements[q].next = s.top();
                    s.pop();
                }
                //若p为null,说明最后一次反转的恰好是最后n个元素,则将尾结点的next置空
                //否则将尾结点与p指向的链表连接(用于处理末尾元素不足n个的情况)
                elements[q].next = p; 
            }
        }
    }

private:
    struct Node {
        int data;
        int next;
    };

    Node elements[MAXSIZE];
    int head; //指向头结点
};

//输出链表
ostream &operator << (ostream &os, List &l)
{
    int p = l.getFirstAdd();

    while (p != List::null) {
        cout << setw(5) << setfill('0') << p << " " << l.elements[p].data << " "; 
        if (l.elements[p].next == List::null) {
            cout << l.elements[p].next << endl;
        }
        else {
            cout << setw(5) << setfill('0') << l.elements[p].next << endl;
        }
        p = l.elements[p].next;
    }

    return os;
}

int main()
{
    int n, k, firstAddress;
    
    cin >> firstAddress >> n >> k;

    List l(firstAddress, n);
    l.reverse(k);
    cout << l;

    return 0;
}
