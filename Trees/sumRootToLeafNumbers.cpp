Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void create(TreeNode* A, vector<string> &result, string &str)
{
    if(A == NULL)
        return;
    string str2 = str;
    str = str + to_string(A -> val);
    if(A -> left == NULL && A -> right == NULL)
    {
        result.push_back(str);
    }
    create(A -> left, result, str);
    create(A -> right, result, str);
    str = str2;
}

int Solution::sumNumbers(TreeNode* A) 
{
    string str = "";
    vector<string> result;
    int sum = 0, res = 0;
    create(A, result, str);
    for(int i = 0; i < result.size(); i++)
    {
        res = 0;
        for (int j = 0; j < result[i].length(); j++) 
            res = (res*10 + (int)result[i][j] - '0') % 1003;
        sum = (sum + res) % 1003;
    }
    return sum;
    
}
