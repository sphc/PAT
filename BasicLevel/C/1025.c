#include <stdio.h>
#include <stdbool.h>

#define null -1

typedef struct {
    int value;
    int next;
} Node;

typedef struct {
    int capacity[100010];
    int top;
} Stack;

void initStack(Stack *stack)
{ stack->top = 0; }

void push(Stack *stack, int address)
{ stack->capacity[stack->top++] = address; }

int getTop(const Stack *stack)
{ return stack->capacity[stack->top - 1]; }

int pop(Stack *stack)
{ return stack->capacity[--stack->top]; }

bool isEmpty(const Stack *stack)
{ return stack->top == 0; }

void setValue(Node *node, int value)
{ node->value = value; }

void setNext(Node *node, int next)
{ node->next = next; }

int getValue(const Node *node)
{ return node->value; }

int getNext(const Node *node)
{ return node->next; }

//打印链表，head为头指针
void printList(const Node *node, int head)
{
    while (head != null) {
        printf("%.5d %d ", head, getValue(node + head));
        printf(getNext(node + head) != null ? "%.5d" : "%d", getNext(node + head));
        printf("\n");
        head = getNext(node + head);
    }
}

//当链表用，下标表示地址
Node a[100010];

int main(void)
{
    int address, n, k;
    int head; //保存第一个节点地址
    int count = 0; //计数器
    Stack stack;
    int last = 100002; //作为反转后的链表的头结点

    initStack(&stack);
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &address);
        scanf("%d", &a[address].value);
        scanf("%d", &a[address].next);
    }

    //每次往栈中push k个元素，然后反转链接
    while (head != null) {
        push(&stack, head);
        head = getNext(a + head);
        if (++count % k == 0) {
            while (!isEmpty(&stack)) {
                setNext(a + last, pop(&stack));
                last = getNext(a + last);
            }
        }
    }
    setNext(a + last, null);
    //此时若栈不为空，则栈顶保存剩余链表的最后一个节点，将其next指针置空
    if (!isEmpty(&stack)) {
        setNext(a + getTop(&stack), null);
    }
    //链接剩余链表
    while (!isEmpty(&stack)) {
        setNext(a + last, pop(&stack));
    }
    //之前已经将100002作为头结点下标，从头结点的下一个节点开始打印
    printList(a, getNext(a + 100002)); 

    return 0;
}
