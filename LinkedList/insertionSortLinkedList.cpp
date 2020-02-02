Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3



ListNode* Solution::insertionSortList(ListNode* A) {
    
    ListNode *ptr = A, *qtr = A, *dummy;
    dummy = new ListNode(-1);
    dummy -> next = A;
    while(ptr -> next != NULL)
    {
        if(ptr -> val <= ptr -> next -> val)
        {
            ptr = ptr -> next;
        }
        else
        {
            qtr = NULL;
            ListNode *ptr2 = ptr;
            ptr = ptr -> next;
            if(A -> val > ptr -> val)
            {
                if(ptr2 != A)
                    ptr2 -> next = ptr -> next;
                else
                    A -> next = ptr -> next;
                ptr -> next = A;
                A = ptr;
                dummy = A;
            }
            else
            {
                qtr = dummy;
                
                while(qtr -> next != NULL && ptr != NULL && qtr -> next -> val <= ptr -> val)
                {
                    qtr = qtr -> next;
                }
                ListNode* temp = ptr -> next;
                ptr -> next = qtr -> next;
                qtr -> next = ptr;
                while(ptr -> next != qtr -> next)
                    ptr = ptr -> next;
                ptr -> next = temp;
            }
        }
    }
    return A;
}
