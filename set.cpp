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
}

int main()
{
}
