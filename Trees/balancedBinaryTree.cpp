Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 
         

int height(TreeNode *A)
{
    if(A == NULL)
        return 0;
    int hl = height(A -> left);
    int hr = height(A -> right);
    if(hl == -1 || hr == -1)
        return -1;
    if(abs(hl - hr) > 1)
        return -1;
    if(hl < hr)
        return hr + 1;
    else
        return hl + 1;
}

int Solution::isBalanced(TreeNode* A) {
    
    int flag = height(A);
    if(flag == -1)
        return 0;
    else
        return 1;
}
