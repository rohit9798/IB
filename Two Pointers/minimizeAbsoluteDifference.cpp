Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.


int max(int i, int j)
{
    return i < j ? j : i;
}
int min(int i, int j)
{
    return i < j ? i : j;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int i = 0, j = 0, k = 0, minimum = INT_MAX, minn;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        if(minimum > abs(max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k]))))
        {
            minimum = abs(max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k])));
        }
        minn = min(A[i], min(B[j], C[k]));
        if(A[i] == minn)
            i++;
        else if(B[j] == minn)
            j++;
        else if(C[k] == minn)
            k++;
    }
    return minimum;
}
