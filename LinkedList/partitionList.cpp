Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL)
    {
        return NULL;
    }
    ListNode* temp = A,*ptr, *qtr, *itr;
    ListNode* ptrn = new ListNode(-1);
    ptr = ptrn;
    ListNode* qtrn = new ListNode(-1);
    qtr = qtrn;
    itr = A;
    while(itr != NULL)
    {
        if(itr->val < B)
        {
            ptr->next = itr;
            ptr = itr;
        }
        else if(itr -> val >= B)
        {
            qtr->next = itr;
            qtr = itr;
   
        }
        itr = itr->next;
    }
    qtr->next = NULL;
    ptr->next = qtrn->next;
    return ptrn->next;
}
