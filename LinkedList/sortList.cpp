Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5





ListNode* merge(ListNode* A, ListNode* B){
   
    if(A == NULL)
        return B;
    if(B == NULL)
        return A;
    ListNode *dummy = NULL;
    if(A -> val <= B -> val)
    {
        dummy = A;
        A = A -> next;
    }
    else
    {
        dummy = B;
        B = B -> next;
    }
    ListNode *head = dummy;
    while( A != NULL && B != NULL )
    {
        if(A -> val <= B -> val)
        {
            dummy -> next = A;
            A = A -> next; 
        }
        else
        {
            dummy -> next = B;
            B = B -> next;
        }
        dummy = dummy -> next;
    }
    if(A == NULL)
    {
        dummy -> next = B;
    }
    else if(B == NULL)
    {
        dummy -> next = A;
    }
    return head;
} 

ListNode* Solution::sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL || A -> next == NULL)
        return A;
    
    ListNode *head = A;
    ListNode *ptr = A, *qtr = A -> next;
    while(qtr != NULL && qtr -> next != NULL)
    {
        ptr = ptr -> next;
        qtr = qtr -> next -> next;   
    }
    qtr = ptr -> next;
    ptr -> next = NULL;
    ListNode *s1 = sortList(head);
    ListNode *s2 = sortList(qtr);
    head = merge(s1, s2); /**/
    return head;
}
