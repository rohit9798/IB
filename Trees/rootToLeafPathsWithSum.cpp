Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]



void summ(TreeNode *A, int B, vector<vector<int>> &sol, vector<int> &vec, int sum)
{
    if (A == NULL)
        return;
    sum = sum + A->val;
    vec.push_back(A->val);
    if(sum == B && (A->right == NULL && A->left==NULL))
    {
        sol.push_back(vec);
    }
    summ(A->left, B, sol, vec, sum);
    summ(A->right, B, sol, vec, sum);
    vec.pop_back();
}
vector<vector<int>> Solution::pathSum(TreeNode *A, int B) 
{
    vector<vector<int>> sol;
    vector<int> vec;
    summ(A, B, sol, vec, 0);
    return sol;
}
