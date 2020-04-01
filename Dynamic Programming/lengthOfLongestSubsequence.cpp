Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= N <= 3000
1 <= A[i] <= 1e7
Example:

Input 1:
    A = [1, 2, 1]

Output 1:
    3

Explanation 1:
    [1, 2, 1] is the longest subsequence.

Input 2:
    [1, 11, 2, 10, 4, 5, 2, 1]

Output 2:
    6
    
Explanation 2:
    [1 2 10 4 2 1] is the longest subsequence.
    
    
int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    int increasing[n];
    int decreasing[n];
    decreasing[n - 1] = 1;
    if(A.size() == 0)
        return 0;
    for(int i = 0; i < n; i++)
    {
        increasing[i] = 1;
        decreasing[i] = 1;
    }
    increasing[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(A[i] > A[j])
            {
                if(increasing[i] < increasing[j] + 1 )
                    increasing[i] = increasing[j] + 1;
            }
        }
    }
    for(int i = n - 1; i>= 0; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                if(decreasing[i] < decreasing[j] + 1)
                    decreasing[i] = decreasing[j] + 1;
            }
        }
    }
    /*for(int i = 0; i < n; i++)
    {
        cout<<increasing[i]<<" ";
    }
    for(int i = 0; i < n; i++)
    {
        cout<<decreasing[i]<<" ";
    }*/
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(maximum < (increasing[i] + decreasing[i] - 1))
            maximum = increasing[i] + decreasing[i] - 1;
    }
    return maximum;
}
