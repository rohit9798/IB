Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]



int maxDepth(TreeNode* A) {
    
    if(A == NULL)
        return 0;
    int hl = maxDepth(A -> left);
    int hr = maxDepth(A -> right);
    if(hl < hr)
        return hr + 1;
    else
        return hl + 1;
    
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    int n = maxDepth(A);
    vector<vector<int>> result(n);
    queue<TreeNode*> q;
    q.push(A);
    TreeNode *ptr = A;
    int count1 = 1, count2 = 1, i = 0;
    while(count2 != 0 && q.size() != 0)
    {
        count2 = 0;
        while(count1 != 0 && q.size() != 0)
        {
            ptr = q.front();
            q.pop();
            result[i].push_back(ptr -> val);
            if(ptr -> left != NULL)
            {
                q.push(ptr -> left);
                count2++;
            }
            if(ptr -> right != NULL)
            {
                q.push(ptr -> right);
                count2++;
            }
            count1--;
        }
        count1 = count2;
        i++;
    }
    for(int j = 0; j < i; j++)
    {
        if(j % 2 == 1)
        {
            reverse(result[j].begin(), result[j].end()); 
        }
    }
    
    return result;
}
