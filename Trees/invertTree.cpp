Given a binary tree, invert the binary tree and return it.
Look at the example for more details.

Example :
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4



void swap(TreeNode** ptr, TreeNode** qtr)
{
    TreeNode* temp = *ptr;
    *ptr = *qtr;
    *qtr = temp;
}
void invert(TreeNode* ptr)
{
    if(ptr != NULL)
    {
        swap(&ptr -> left, &ptr -> right);
        invert(ptr -> left);
        invert(ptr -> right);
    }
}
TreeNode* Solution::invertTree(TreeNode* A) {
    
    invert(A);
    return A;
    
}
