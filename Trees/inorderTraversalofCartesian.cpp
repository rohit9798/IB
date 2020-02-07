Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
      
    
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max(vector<int> A, int low, int high)
{
    int maximum = low;
    while(low <= high)
    {
        if( A[low] > A[maximum])
        {
            maximum = low;
            
        }
        low++;
    }
    return maximum;
}
TreeNode* build(vector<int> A, int low, int high)
{
    if(high >= low)
    {
        int maximum = max(A, low, high);
        TreeNode* ptr = new TreeNode(A[maximum]);
        ptr -> left = build(A, low, maximum - 1);
        ptr -> right = build(A, maximum + 1, high); 
        return ptr;
    }
    else
        return NULL;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    
    if(A.size() == 0)
        return NULL;
    if(A.size() == 1)
        return new TreeNode(A[0]);
    TreeNode* head = build(A, 0, A.size() - 1); 
    return head;
    
}
