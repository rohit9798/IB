Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

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
 int search(vector<int> &A, int a)
 {
    int i = 0;
    while(a != A[i])
        i++;
    return i;
 }
TreeNode *build(vector<int> &pre, vector<int> &in, int start, int end, int &t)
{
    if(start > end)
        return NULL;
    int val = pre[t++];
    TreeNode *ptr = new TreeNode(val);
    int index = search(in, val);
    ptr -> left = build(pre, in, start, index - 1, t);
    ptr -> right = build(pre, in, index + 1, end, t);
    
    return ptr;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

    int t = 0;
    TreeNode* head = build(A, B, 0, A.size() - 1, t);
    return head;
}
