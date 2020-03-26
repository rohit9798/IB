Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20



ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

    ListNode* head = NULL;
    multimap<int, ListNode*> m;
    for(int i = 0; i < A.size(); i++)
    {
        m.insert(make_pair(A[i] -> val, A[i]));
    }
    multimap<int, ListNode*> :: iterator itr = m.begin();
    head = itr -> second;
    ListNode *rtr = head;
    ListNode *qtr = itr -> second -> next;
    m.erase(itr);
    if(qtr != NULL)
        m.insert(make_pair(qtr -> val, qtr));
    while(m.size())
    {
        itr = m.begin();
        qtr = itr -> second;
        rtr -> next = qtr;
        rtr = rtr -> next;
        qtr = qtr -> next;
        m.erase(itr);
        if(qtr != NULL)
            m.insert(make_pair(qtr -> val, qtr));
    }
    return head;
}
