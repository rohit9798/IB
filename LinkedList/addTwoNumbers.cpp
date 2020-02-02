You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.



ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int carry = 0;
    ListNode *ptr = NULL, *head;
    while(A != NULL && B != NULL)
    {
        if(ptr == NULL)
        {
            ptr = new ListNode((A -> val + B -> val + carry) % 10);
            carry = (A -> val + B -> val + carry) / 10;
            head = ptr;
        }
        else
        {
            ptr -> next = new ListNode((A -> val + B -> val + carry) % 10);
            carry = (A -> val + B -> val + carry) / 10;
            ptr = ptr -> next;
        }
        A = A -> next;
        B = B -> next;
    }
    while(A != NULL)
    {
        ptr -> next = new ListNode((A -> val + carry) % 10);
        carry = (A -> val + carry) / 10;
        ptr = ptr -> next;
        A = A -> next;
    }
    while(B != NULL)
    {
        ptr -> next = new ListNode((B -> val + carry) % 10);
        carry = (B -> val + carry) / 10;
        ptr = ptr -> next;
        B = B -> next;
    }
    if(carry == 1)
    {
        ptr -> next = new ListNode(carry);
        ptr = ptr -> next;
    }
    return head;
}
