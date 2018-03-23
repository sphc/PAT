#include <stdio.h>

#define SIZE 100100
#define null -1

typedef struct {
    int data;
    int next;
} Node;

//初始化链表,构造头结点head
void initList(Node *list, int *head)
{
    static int start = 100000;

    *head = start++;
    list[*head].next = null;
}

//删除head后的结点
int deleteNode(Node *list, int head)
{ 
    int tmp = list[head].next;

    list[head].next = list[tmp].next; 

    return tmp;
}

//将node插入到head后
void insertNode(Node *list, int head, int node)
{
    list[node].next = list[head].next;
    list[head].next = node;
}

//打印以head为头结点的链表
void printList(Node *list, int head)
{
    int p = list[head].next;

    while (p != null) {
        printf("%.5d %d ", p, list[p].data);
        printf(list[p].next != null ? "%.5d\n" : "%d\n", list[p].next);
        p = list[p].next;
    }
}

int main(void)
{
    int n, k;
    //head1指向小于0的元素构成的链表
    //head2指向[0,k]区间元素构成的链表
    //head3指向大于k的元素构成的链表
    int head1, head2, head3;
    int p, q, r;
    Node list[SIZE];

    initList(list, &head1);
    initList(list, &head2);
    initList(list, &head3);
    scanf("%d%d%d", &list[head3].next, &n, &k);

    //输入链表
    for (int i = 0; i < n; ++i) {
        int add;

        scanf("%d", &add);
        scanf("%d%d", &list[add].data, &list[add].next);
    }

    p = head3;
    q = head1;
    r = head2;

    //链表元素分类
    while (list[p].next != null) {
        if (list[list[p].next].data < 0) {
            int t = deleteNode(list, p);

            insertNode(list, q, t);
            q = list[q].next;
        }
        else if (list[list[p].next].data <= k) {
            int t = deleteNode(list, p);

            insertNode(list, r, t);
            r = list[r].next;
        }
        else {
            p = list[p].next;
        }
    }

    //连接3个链表
    if (q != head1 && r != head2) {
        list[q].next = list[head2].next;
        list[r].next = list[head3].next;
    }
    else if (q == head1) {
        head1 = head2;
        list[r].next = list[head3].next;
    }
    else if (r == head2) {
        list[q].next = list[head3].next;
    }
    else {
        head1 = head3;
    }

    //打印结果
    printList(list, head1);

    return 0;
}
