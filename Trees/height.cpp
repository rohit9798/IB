Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.




int Solution::maxDepth(TreeNode* A) {
    
    if(A == NULL)
        return 0;
    int hl = maxDepth(A -> left);
    int hr = maxDepth(A -> right);
    if(hl < hr)
        return hr + 1;
    else
        return hl + 1;
    
}
