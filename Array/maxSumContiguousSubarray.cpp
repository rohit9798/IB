Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.
Constraints:

1 <= N <= 1e6
-1000 <= A[i] <= 1000
For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.
    
    
int Solution::maxSubArray(const vector<int> &A) {
    int *max = new int[A.size()];
    int n1 = A.size();
    for(int i = 0; i < n1; i++)
    {
        max[i] = A[i];
    }
    for(int i = 1; i < n1; i++)
    {
        if(A[i] + max[i - 1] > max[i])
            max[i] = A[i] + max[i - 1];
    }
    int maximum = max[0];
    for(int  i = 0; i < n1; i++)
    {
        if(maximum < max[i])
            maximum = max[i];
    }
    return maximum;
}
