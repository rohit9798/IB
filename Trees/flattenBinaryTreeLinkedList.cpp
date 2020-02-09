Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.


void preorder(TreeNode* A, queue<int> &v)
{
    if(A != NULL)
    {
        v.push(A -> val);
        preorder(A -> left, v);
        preorder(A -> right, v);
        free(A);
    }
}
TreeNode* Solution::flatten(TreeNode* A) {
    
    queue<int> v;
    preorder(A, v);
    TreeNode* ptr = new TreeNode(v.front());
    TreeNode *head = ptr;
    v.pop();
   while(v.size() != 0)
    {
        ptr -> right = new TreeNode(v.front());
        v.pop();
        ptr -> left = NULL;
        ptr = ptr -> right;
    } /**/
   return head;
}
