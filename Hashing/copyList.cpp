A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.


/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    vector<RandomListNode*> v;
    RandomListNode* ptr = A;
    while(ptr != NULL)
    {
        v.push_back(ptr -> random);
        ptr = ptr -> next;
    }
    ptr = A;
    RandomListNode* head = NULL, *qtr = NULL;
    while(ptr != NULL)
    {
        if(head == NULL)
        {
            head = new RandomListNode(ptr -> label);
            ptr -> random = head;
            ptr = ptr -> next;
            qtr = head;
        }
        else
        {
            qtr -> next = new RandomListNode(ptr -> label);
            qtr = qtr -> next;
            ptr -> random = qtr;
            ptr = ptr -> next;
        }
    }
    qtr = head;
    vector<RandomListNode*> :: iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++)
    {
        if(*itr == NULL)
            qtr -> random = NULL;
        else
            qtr -> random = (*itr) -> random; 
        qtr = qtr -> next;
    }
    return head;
}
