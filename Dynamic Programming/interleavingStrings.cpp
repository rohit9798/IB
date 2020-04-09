Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
    
    
    
int Solution::isInterleave(string A, string B, string C) {
    
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    if(n3 != n1 + n2)
        return 0;
    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= n1; i++)
    {
        if(A[i - 1] == C[i - 1])
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
    }
    for(int j = 1; j <= n2; j++)
    {
        if(B[j - 1] == C[j - 1])
            dp[0][j] = dp[0][j - 1];
        else
            dp[0][j] = 0;
    }
    int k;
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if(A[i - 1] == C[i + j - 1])
                dp[i][j] = dp[i - 1][j];
            else if(B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    
    return dp[n1][n2];
}
