You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4



int Solution::nTriang(vector<int> &A) {
    
    int i = A.size() - 1, j = 0, k = 0;
    int count = 0;
    sort(A.begin(), A.end());
    while(i >= 0)
    {
        j = 0; 
        k = i - 1;
        while(j < k)
        {
            if(A[k] + A[j] > A[i])
            {
                count += (k - j);
                k--;
            }
            else
                j++;
        }
        i--;
    }
    return count;
}
