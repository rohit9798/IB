Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


ListNode* Solution::swapPairs(ListNode* B) {
    
    int temp;
    ListNode * A= B;
    while(A != NULL && A -> next != NULL)
    {
        temp = A -> val;
        A -> val = A -> next -> val;
        A -> next -> val = temp;
        A = A -> next -> next;
    }
    return B;
}
