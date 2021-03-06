Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3



TreeNode *f(const vector<int> &A, int start, int end)
{
    if(start == end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode * ptr = new TreeNode(A[mid]);
    ptr -> left = f(A, start, mid);
    ptr -> right = f(A, mid + 1, end);
    return ptr;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
        
    TreeNode *head = f(A, 0, A.size());
    return head;
}
