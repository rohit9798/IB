Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True





string str = "";
 void inorder(TreeNode *ptr)
 {
    if(ptr != NULL)
    {
        inorder(ptr -> left);
        str = str + to_string(ptr -> val);
        inorder(ptr -> right);
    }
 }
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    string str1 = "", str2 = "";
    inorder(A);
    str1 = str;
    str = "";
    inorder(B);
    str2 = str;
    if(str1.compare(str2) == 0)
        return 1;
    return 0;
}
