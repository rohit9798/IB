Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.



ListNode *reverse(ListNode* ptr)
{
    ListNode *atr = NULL, *qtr = ptr, *rtr = ptr;
    while(rtr != NULL)
    {
        rtr = qtr -> next;
        qtr -> next = atr;
        atr = qtr;
        qtr = rtr;
    }
    return atr;
}
ListNode* Solution::reorderList(ListNode* A) {
    
    ListNode *ptr = A, *qtr = A, *atr = A, *temp = A;
    while(ptr != NULL && ptr -> next != NULL)
    {
        ptr = ptr -> next -> next;
        qtr = qtr -> next;
    }
    atr = qtr;
    ptr = A;
    ListNode *head = reverse(qtr);
    while(ptr -> next != atr)
        ptr = ptr -> next;
    ptr -> next = NULL;
    ptr = A;
    while(ptr != NULL)
    {
        temp = ptr -> next;
        ptr -> next = head;
        qtr = head -> next;
        head -> next = temp;
        ptr = temp;
        head = qtr;
    }
    if(head != NULL)
    {
        ptr = A;
        while(ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = qtr;
    }
    return A;
    
}
