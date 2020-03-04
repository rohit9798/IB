Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.


int Solution::diffPossible(vector<int> &A, int k) {
    
    int i = 0;
    int j = 0;
    while(A[i] < k)
        i++;
    while(i < A.size())
    {
        while(j != i && A[i] - A[j] > k)
        {
            j++;       
        }
        if(A[i] - A[j] == k && i!= j)
            return 1;
        else
            i++;
    }
    return 0;
}
