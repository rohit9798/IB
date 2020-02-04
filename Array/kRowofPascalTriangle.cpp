Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?


vector<int> Solution::getRow(int A) {
    
    vector<vector<int>> result(A + 1);
    for(int i = 0; i < A + 1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j || j == 0)
            {
                result[i].push_back(1);
            }
            else
            {
                result[i].push_back(result[i-1][j] + result[i - 1][j - 1]);
            }
        }
    }
    return result[A];
}
