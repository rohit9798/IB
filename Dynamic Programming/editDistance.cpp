Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
    
    
    
int Solution::minDistance(string A, string B) {
    
    int dp[A.length() + 1][B.length() + 1];
    for(int i = 0; i <= B.length(); i++)
    {
        dp[0][i] = i;
    }
    for(int i = 0; i <= A.length(); i++)
    {
        dp[i][0] = i;
    }
    for(int i = 1; i <= A.length(); i++)
    {
        for(int j = 1; j <= B.length(); j++)
        {
            if(A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[A.length()][B.length()];
    
}
