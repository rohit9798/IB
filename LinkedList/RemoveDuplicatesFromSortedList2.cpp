Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.



ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *prev = NULL, *next1 = A -> next, *ptr = A;
    while(next1 != NULL)
    {
        if(ptr -> val != next1 -> val)
        {
            prev = ptr;
            ptr = ptr -> next;
            next1 = next1 -> next;
        }
        else
        {
            while(ptr -> val == next1 -> val)
            {
                if(prev == NULL)
                {
                    prev = ptr;
                }
                else
                {
                    prev -> next = prev -> next -> next;    
                    ptr = ptr -> next;
                    next1 = next1 -> next;
                }1
            }
        }
    }
    return A;
}
