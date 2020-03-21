Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.


int Solution::diffPossible(const vector<int> &A, int B) {
    
    int i = 0, j = 0;
    multimap<int, int> m;
    if(A.size() < 2)
        return 0;
    while(i < A.size())
    {
        if(m.find(A[i] + B) != m.end() || m.find(A[i] - B) != m.end())
            return 1;
        else
            m.insert(make_pair(A[i], 1));
        i++;
    }
    return 0;
}
