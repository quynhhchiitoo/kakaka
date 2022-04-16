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
    if (cur->data == x)
        return;
    if (cur->data > x)
    {
        p->pNext = s.pHead;
        s.pHead->pPrev = p;
        s.pHead = p;
        return;
    }

    // Normal case
    while (cur->pNext)
    {
        if (cur->pNext->data == x)
            return;
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

    // Case when it is the largest compared to all data in set

    if (cur->data == x) // to check if the last element is x, we wont append it to Set s
        return;

    cur->pNext = p;
    s.pTail = p;
    p->pPrev = cur;
    return;
}

// 6
Set substraction_of_2_sets(Set a, Set b)
{
    DNode *cur1 = a.pHead;
    DNode *cur2 = b.pHead;
    while (cur1->data == cur2->data)
    {
        a.pHead = a.pHead->pNext;
        cur2 = cur2->pNext;
    }
    while (cur1 && cur2)
    {
        while (cur1->pNext->data < cur2->data)
        {
            cur1 = cur1->pNext;
            if (cur1->pNext == nullptr)
                return a;
        }
        if (cur1->pNext->data == cur2->data)
        {
            DNode *tmp = cur1->pNext->pNext;
            cur1->pNext = tmp;
            tmp->pPrev = cur1;
        }
        cur2 = cur2->pNext;
    }
    return a;
}

void print(Set s)
{
    DNode *cur = s.pHead;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->pNext;
    }
    cout << endl;
    return;
}

int main()
{
    Set s1, s2;
    init(s1);
    init(s2);

    add(s1, 7);
    add(s1, 3);
    add(s1, 1);
    add(s1, 2);

    add(s2, 2);
    add(s2, 3);
    add(s2, 4);

    print(s1);
    print(s2);
    Set ans = substraction_of_2_sets(s1, s2);
    print(ans);
}
