Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.

Input format:

First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
The next N lines, consists of M integers each denoting the strength of each cell.

1 <= N <= 1500
1 <= M <= 1500
-200 <= Cell Strength <= 200
Output:

The largest sum of strength that you can get by choosing one sub-matrix.
Example:

Input:
3 3
-5 -4 -1
-3 2 4
2 5 8

Output:
19

Explanation:
Bomb the sub-matrix from (2,2) to (3,3): 2 + 4 + 5 + 8 = 19



int Solution::solve(vector<vector<int> > &A) {
    
    int r = A.size();
    int c = A[0].size();
    int dp[r + 1][c + 1];
    int result = INT_MIN;
    for(int i = r; i >= 0; i--)
    {
        for(int j = c; j >= 0; j--)
        {
            if(i == r || j == c)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i + 1][j] - dp[i + 1][j + 1] + dp[i][j + 1] + A[i][j];
                result = max(result,dp[i][j]);
            }
        }
    }
    /*for(int i = 0; i <= r; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return result;
}
