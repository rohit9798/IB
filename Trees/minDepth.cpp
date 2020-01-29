Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.




int Solution::minDepth(TreeNode* A) {
    
    if(A -> left == NULL && A -> right == NULL)
        return 1;
    int hl , hr;
    if(A -> left != NULL)
        hl = minDepth(A -> left) ;
    if(A -> right != NULL)
        hr = minDepth(A -> right) ;
    if(hl < hr)
        return hl + 1;
    else 
        return hr + 1;
}
