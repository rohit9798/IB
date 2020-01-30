Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].


vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode *ptr = A;
    s.push(A);
    ptr = ptr -> left;
    while(ptr != NULL || s.size() != 0)
    {
        while(ptr != NULL)
        {
            s.push(ptr);
            ptr = ptr -> left;
        }
        ptr = s.top();
        s.pop();
        result.push_back(ptr -> val);
        ptr = ptr -> right;
    }
    return result;
}
