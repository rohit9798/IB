Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
    
    
int Solution::sqrt(int A) {
    
    long mid, high = A;
    int low = 1;
    if(A == 0 || A == 1)
        return A;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(mid * mid == A)
        {
            return mid;
        }
        else if( mid * mid < A)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
    return high;
}
