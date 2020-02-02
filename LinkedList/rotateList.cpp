Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    ListNode *ptr = A, *qtr = A, *rtr = NULL;
    int i = 0, size = 0;
    if(A -> next == NULL)
    {
        return A;
    }
    if(A -> next -> next == NULL)
    {
        if(B == 1)
        {
            ListNode *atr = A;
            A = A -> next;
            A -> next = atr;
            atr -> next = NULL;
            return A;
        }
        else if(B == 1)
        {
            return A;
        }
    }
    ListNode *btr = A;
    while(btr != NULL)
    {
        btr = btr -> next;
        size++;
    }
    while(i < B % size && ptr != NULL)
    {
        i++;
        ptr = ptr -> next;
    }
    if(i == 0)
        return A;
    while(ptr != NULL && ptr -> next != NULL)
    {
        qtr = qtr -> next;
        ptr = ptr -> next;
    }
    rtr = qtr -> next;
    ListNode *temp = rtr;
    qtr -> next = NULL;
    while(rtr -> next != NULL)
    {
        rtr = rtr -> next;
    }
    rtr -> next = A;
    return temp;
}
