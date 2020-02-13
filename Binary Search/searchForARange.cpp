Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

 Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
    
    
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int low = 0;
    int high = A.size() - 1;
    int left = 0, right = 0;
    vector<int> result;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(A[mid] == B)
        {
            if(mid == low)
            {
                left = mid;
                break;
            }
            if(A[mid - 1] != A[mid])
            {
                left = mid;
                break;
            }
        }
        if(A[mid] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        left = -1;
    }
    result.push_back(left);
    low = 0;
    high = A.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(A[mid] == B)
        {
            if(mid == high)
            {
                right = mid;
                break;
            }
            if(A[mid + 1] != A[mid])
            {
                right = mid;
                break;
            }
        }
        if(A[mid] > B)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        right = -1;
    }
    result.push_back(right);
    return result;
}
