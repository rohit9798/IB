vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    stack<TreeNode*> s1, s2;
    vector<int> result;
    s1.push(A);
    TreeNode *ptr = A;
    while(!s1.empty())
    {
        ptr = s1.top();
        s1.pop();
        result.push_back(ptr -> val);
        if(ptr -> left != NULL)
            s1.push(ptr -> left);
        if(ptr -> right != NULL)
            s1.push(ptr -> right);

    }
    reverse(result.begin(), result.end());
    return result;
}
