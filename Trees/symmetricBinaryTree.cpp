Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem



/*vector<int> result;
void inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        result.push_back(root -> val);
        inorder(root -> right);
    }
}
int Solution::isSymmetric(TreeNode* A) {
    
    inorder(A);
    int len = result.size();
    for(int i = 0; i < len / 2; i++)
    {
        if(result[i] != result[len - i - 1])
        {
            return 0;
        }
    }
    
    return 1;
}*/
int ismirror(TreeNode* n1, TreeNode* n2){

 if(!n1||!n2)
 return n1==n2;
 
 if(n1->val!=n2->val)
 return 0;
 
 return (ismirror(n1->left,n2->right)&& ismirror(n1->right,n2->left));
}
int Solution::isSymmetric(TreeNode* A) {

return ismirror(A->left,A->right);
}
