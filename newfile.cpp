#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *pNext;
    DNode *pPrev;
};

struct Set
{
    DNode *pHead;
    DNode *pTail;
    int size;
};

DNode *createNode(int x)
{
    DNode *newNode = new DNode;
    newNode->data = x;
    newNode->pNext = nullptr;
    newNode->pPrev = nullptr;
    return newNode;
}

void init(Set &s)
{
    s.pHead = s.pTail = nullptr;
    s.size = 0;
}

void add(Set &s, int x)
{
    if (!s.pHead)
    {
        s.pHead = createNode(x);
        s.pTail = s.pHead;
        return;
    }

    DNode *cur = s.pHead;
    DNode *p = createNode(x);

    // Case when x is the smallest compare to all the data in set
    if (cur->data > x)
    {
        p->pNext = s.pHead;
        s.pHead->pPrev = p;
        s.pHead = p;
        return;
    }

    while (cur->pNext)
    {
        if (cur->pNext->data > x)
        {
            DNode *tmp = cur->pNext;

            cur->pNext = p;
            p->pNext = tmp;

            p->pPrev = cur;
            tmp->pPrev = p;
            return;
        }
        cur = cur->pNext;
    }
    cur->pNext = p;
    s.pTail = p;
    p->pPrev = cur;
    return;
}

void print(Set s)
{
    DNode *cur = s.pHead;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->pNext;
    }
    return;
}

int main()
{
    Set s;
    init(s);
    add(s, 2);
    add(s, 3);
    add(s, 1);
    print(s);
}
