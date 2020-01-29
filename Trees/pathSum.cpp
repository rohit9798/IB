Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


int Solution::hasPathSum(TreeNode* A, int B) {
    
    if(A == NULL)
        return 0;
    if(B - A -> val == 0 && A -> left == NULL && A -> right == NULL)
        return 1;
    return hasPathSum(A -> left, B - A -> val) || hasPathSum(A -> right, B - A -> val);
    
}
