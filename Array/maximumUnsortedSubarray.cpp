You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.


vector<int> Solution::subUnsort(vector<int> &A) {
    
    int start = 0, end = A.size() - 1, i, max, min;
    vector<int> result;
    for(start = 0; start < end; start++)
    {
        if(A[start] > A[start + 1])
            break;
    }
    if(start == end)
    {
        result.push_back(-1);
        return result;
    }
    for(end = A.size() - 1; end > 0; end--)
    {
        if(A[end] < A[end - 1])
            break;
    }
    max = A[start];
    min = A[start];
    for(i = start + 1; i <= end; i++)
    {
        if(A[i] < min)
            min = A[i];
        if(A[i] > max)
            max = A[i];
    }
    for(i = 0; i < start; i++)
    {
        if(A[i] > min)
        {
            start = i;
            break;
        }
    }
    for(i = A.size() - 1; i >= end + 1; i--)
    {
        if(A[i] < max)
        {
            end = i;
            break;
        }
    }
    result.push_back(start);
    result.push_back(end);
    return result;
}
