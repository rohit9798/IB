Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0


void inorder(TreeNode *root, vector<int> &in)
{
    if(root != NULL)
    {
        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }
}
int Solution::t2Sum(TreeNode* A, int B) {
    
    vector<int> in;
    inorder(A, in);
    int j = in.size() - 1;
    for(int i = 0; i < j; )
    {
        if(in[i] + in[j] == B)
            return 1;
        else
        {
            if(in[i] + in[j] < B)
                i++;
            else
                j--;
        }
    }
    return 0;
}
