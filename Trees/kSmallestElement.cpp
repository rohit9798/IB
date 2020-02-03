Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST
 
 

void inorder(TreeNode *root, vector<int> &a)
 {
     if(root != NULL)
     {
         inorder(root -> left, a);
         a.push_back(root -> val);
         inorder(root -> right, a);
     }
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    vector<int> result;
    inorder(A, result);
    return result[B - 1];
}
