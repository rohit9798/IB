Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.


ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    ListNode *ptr = NULL, *qtr = A;
    int i = 0, flag = 0;
    if(A -> next == NULL)
        return A;
    while(i < B - 1)
    {
        if(ptr == NULL)
            ptr = A;
        else
            ptr = ptr -> next;
        i++;
    }
    i = 0;
    while(i < C)
    {
        qtr = qtr -> next;
        i++;
    }
    ListNode *atr = ptr, *btr = ptr, *temp;
    if(ptr == NULL)
    {
        ptr = A;
        flag = 1;
    }
    else
        ptr = ptr -> next;
    temp = ptr;
    ListNode *rtr = A;
    while(rtr != qtr)
    {
        rtr = ptr -> next;
        ptr -> next = atr;
        atr = ptr;
        ptr = rtr;
    }
    if(flag == 0)
        btr -> next = atr;
    else
        A = atr;
    temp -> next = qtr;
    return A;
}
