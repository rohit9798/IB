Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.



int Solution::firstMissingPositive(vector<int> &A) {
    
    int temp1 = 0, temp2;
    while(temp1 < A.size())
    {
        if(A[temp1] > 0 && A[temp1] <= A.size())
        {
            temp2 = A[temp1] - 1;
            if(A[temp2] != A[temp1])
            {
                int temp = A[temp1];
                A[temp1] = A[temp2];
                A[temp2] = temp;
                temp1--;
            }
        }
        temp1++;
    }
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != i + 1)
            return i + 1;
    }
    return A[2];
}
