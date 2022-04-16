Set union_2_sets(Set a, Set b)
{
    Set ans;
    init(ans);
    DNode *cur1 = a.pHead;
    DNode *cur2 = b.pHead;

    if (!cur1 && !cur2)
        return ans;
    if (!cur1)
        return b;
    if (!cur2)
        return a;

    while (1)
    {
        if (cur1 == nullptr)
        {
            while (cur2)
            {
                add(ans, cur2->data);
                cur2 = cur2->pNext;
            }
        }
        if (cur2 == nullptr)
        {
            while (cur1)
            {
                add(ans, cur1->data);
                cur1 = cur1->pNext;
            }
        }
        if (!cur1 && !cur2)
            return ans;

        while (cur1->data <= cur2->data && cur1 && cur2)
        {
            add(ans, cur1->data);
            cur1 = cur1->pNext;
            if (cur1->data == cur2->data)
                cur2 = cur2->pNext;
        }
        while (cur1->data > cur2->data && cur2 && cur2)
        {
            add(ans, cur2->data);
            cur2 = cur2->pNext;
        }
    }
    return ans;
}
