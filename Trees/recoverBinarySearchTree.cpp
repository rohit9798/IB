Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST        


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    
    int previous = 0, next;
    TreeNode *temp = A;
    vector<int> inorder;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    previous = temp -> val;
    TreeNode *current = A, *pre = NULL;
    vector<int> result;
    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            /*next = current -> val;
            if(next < previous)
            {
                result.push_back(next);
                result.push_back(previous);
                return result;
            }
            previous = next;*/
            inorder.push_back(current -> val);
            current = current -> right;
        }
        else
        {
            pre = current -> left;
            while(pre -> right != NULL && pre -> right != current)
            {
                pre = pre -> right;
            }
            
            if(pre -> right == NULL)
            {
                pre -> right = current;
                current = current -> left;
            }
            else
            {
                pre -> right = NULL;
                /*next = current -> val;
                if(next < previous)
                {
                    result.push_back(next);
                    result.push_back(previous);
                    return result;
                }
                previous = next;*/
                inorder.push_back(current -> val);
                current = current -> right;
            }
        }
    }
    int i = 1, first, middle, last;
    while(inorder[i - 1] < inorder[i] && i < inorder.size())
    {
        i++;
    }
    if(i == inorder.size())
        return result;
    else
    {
        first = i - 1;
        middle = i++;
    }
    while(inorder[i - 1] < inorder[i] && i < inorder.size())
    {
        i++;
    }
    if(i == inorder.size())
    {
        result.push_back(inorder[middle]);
        result.push_back(inorder[first]);
        return result;
    }
    else
        last = i;
    result.push_back(inorder[last]);
    result.push_back(inorder[first]);
    return result;
}
