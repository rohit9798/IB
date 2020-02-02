Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.



ListNode* Solution::reverseList(ListNode* A, int B) {
    
    ListNode *ptr = A, *atr = NULL, *rtr = NULL;
    int i = 0;
    while(ptr != NULL && i < B)
    {
        rtr = ptr -> next;
        ptr -> next = atr;
        atr = ptr;
        ptr = rtr;
        i++;
    }
    if(rtr != NULL)
        A -> next = reverseList(rtr, B);
    return atr;
}
