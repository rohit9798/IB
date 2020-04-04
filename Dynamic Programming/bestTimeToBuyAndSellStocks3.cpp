Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


Input Format:

The first and the only argument is an integer array, A.
Output Format:

Return an integer, representing the maximum possible profit.
Constraints:

1 <= length(A) <= 7e5
1 <= A[i] <= 1e7
Examples:

Input 1:
    A = [1, 2, 1, 2]

Output 1:
    2

Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell

Input 2:
    A = [7, 2, 4, 8, 7]

Output 2:
    6

Explanation 2:
    Day 1 : Buy
    Day 3 : Sell
    
    
int Solution::maxProfit(const vector<int> &A) {
    
    int n = A.size();
    int dp[3][n];
    int maxDiff = 0;
    if(A.size() < 2)
        return 0;
    for(int i = 0; i < 3; i++)
    {
        maxDiff = -A[0];
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = max(dp[i][j - 1], A[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - A[j]);
            }
        }
    }
    return dp[2][n - 1];
}
