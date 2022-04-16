bool check_value_X(DNode *head, int x)
{
    if (head == nullptr)
        return false;
    if (head->data == x)
        return true;
    return check_value_X(head->pNext, x);
}
