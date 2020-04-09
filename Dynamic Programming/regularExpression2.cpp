Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem




int Solution::isMatch(const string A, const string B) {
    
    int n1 = B.length();
    int n2 = A.length();
    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= n1; i++)
    {
        if(B[i - 1] == '*')
            dp[i][0] = dp[i - 2][0];
        else
            dp[i][0] = 0;
    }
    for(int i = 1; i <= n2; i++)
        dp[0][i] = 0;    
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(B[i - 1] == A[j - 1] || B[i - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(B[i - 1] == '*')
            {
                dp[i][j]=dp[i - 2][j];
                if(B[i-2]==A[j-1] or B[i-2]=='.')
                {
                   dp[i][j]=dp[i][j] || dp[i][j - 1];
                }
            }
            else
                dp[i][j] = 0;
        }
    }
     /*for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    return dp[n1][n2];
}
