Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3
          

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**/int index(vector<int> &A, int start, int end, int val)
{
    int i = start;
    while(i <= end)
    {
        if(A[i] == val)
        {
            return i;
        }
        i++;
    }
}
TreeNode* build(vector<int> &A, vector<int> &B, int start, int end, int &t)
{
    if(start > end)
        return NULL;
    int val = B[t--];
    TreeNode* ptr = new TreeNode(val);
    if(start == end)
        return ptr;
    int i = index(A, start, end, val);
    ptr -> right = build(A, B, i + 1, end, t);
    ptr -> left = build(A, B, start, i - 1, t);
    
    return ptr;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int t = B.size() - 1;
    TreeNode* root = build(A, B, 0, t, t);
    return root;
    
}


