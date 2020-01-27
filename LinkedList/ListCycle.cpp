Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 






ListNode* Solution::detectCycle(ListNode* A) {

    ListNode *ptr = A, *qtr = A;
    int flag = 0;
    while(qtr != NULL && ptr != NULL && ptr -> next != NULL)
    {
        ptr = ptr -> next -> next;
        qtr = qtr -> next;
        if(ptr == qtr)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        qtr = A;
        while(qtr != ptr)
        {
            ptr = ptr -> next;
            qtr = qtr -> next;
        }
        return qtr;
    }
    return NULL;
}
