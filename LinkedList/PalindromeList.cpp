Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


ListNode *reverse(ListNode *head)
 {
    ListNode *ptr = NULL, *qtr = head, *rtr = head;
    while(rtr != NULL)
    {
        rtr = qtr -> next;
        qtr -> next = ptr;
        ptr = qtr;
        qtr = rtr;
    }
    return ptr;
 }
int Solution::lPalin(ListNode* A) {
    
    ListNode *ptr = A, *qtr = A;
    while(ptr != NULL && ptr -> next != NULL)
    {
        ptr = ptr -> next -> next;
        qtr = qtr -> next;
    }
    if(ptr != NULL)
        qtr = qtr -> next;
    
    ListNode *head = reverse(qtr);
    ptr = A;
    qtr = head;
    while(ptr != NULL && qtr != NULL)
    {
        if(ptr -> val != qtr -> val)
            return 0;
        ptr = ptr -> next;
        qtr = qtr -> next;
    }
    return 1;
}
