Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.




/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*bool path(TreeNode *A, vector<int> &r, int t)
{
    if(A == NULL)
    {
        return false;
    }
    r.push_back(A -> val);
    if(A -> val == t)
    {
        return true;
    }
    bool flag1 = path(A -> left, r, t);
    bool flag2 = path(A -> right, r, t);
    if(flag1 || flag2)
        return true;
    r.pop_back();
    return false;
}
int Solution::lca(TreeNode* A, int B, int C) 
{
    vector<int> result1;
    vector<int> result2;
    bool flag1 = path(A, result1, B);
    bool flag2 = path(A, result2, C);
    if(!(flag1 && flag2))
        return -1;
    int n1 = result1.size();
    int n2 = result2.size();
    int i = 0, j = 0, least = -1;
    while(i < n1 && j < n2)
    {
        if(result1[i] == result2[j])
            least = result1[i];
        i++;
        j++;
    }
    return least;
}*/




/*bool path(TreeNode *A, int t)
{
    if(A == NULL)
    {
        return false;
    }
    if(A -> val == t)
    {
        return true;
    }
    bool flag1 = path(A -> left, t);
    bool flag2 = path(A -> right, t);
    if(flag1 || flag2)
        return true;
    return false;
}
TreeNode* calculate(TreeNode *A, int B, int C)
{
    if(A == NULL)
        return NULL;
    if(A -> val == B || A -> val == C)
    {
        return A;
    }
    TreeNode* a = calculate(A -> left, B, C);
    TreeNode* b = calculate(A -> right, B, C);
    if(a && b) 
        return A;
    else if(a)
        return a;
    else if(b)
        return b;
        
}
int Solution::lca(TreeNode* A, int B, int C) 
{
    bool flag1 = path(A, B);
    bool flag2 = path(A, C);
    if(!(flag1 && flag2))
        return -1;
    TreeNode* least = calculate(A, B, C);
    return least -> val;
}*/
