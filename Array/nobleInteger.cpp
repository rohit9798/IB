Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.


int Solution::solve(vector<int> &A) {
    
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++)
    {
        if(i + 1 < A.size() && A[i] == A[i + 1])
            continue;
        if(A[i] >= 0)
        {
            if(A[i] == A.size() - i - 1)
                return 1;
        }
    }
    return -1;
}
