vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode *ptr = A;
    s.push(A);
    while(!s.empty())
    {
        ptr = s.top();
        s.pop();
        result.push_back(ptr -> val);
        if(ptr -> right != NULL)
            s.push(ptr -> right);
        if(ptr -> left != NULL)
            s.push(ptr -> left);
    }
    return result;
}
