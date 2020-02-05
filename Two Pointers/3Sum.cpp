Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)



int min(int i, int j)
{
    return i < j ? i : j;
}
int max(int i, int j)
{
    return i < j ? j : i;
}
int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int minimum_sum = INT_MAX, minimum = INT_MAX;
    int left = 0, right = 0, i = 0, sum = 0;
    sort(A.begin(), A.end());
    while(i < A.size() - 2)
    {
        left = i + 1;
        right = A.size() - 1;
        while(right > left)
        {
            sum = A[i] + A[left] + A[right];
            int diff = abs(sum - B);
            if(diff == 0)
                return B;
            if(diff < minimum)
            {
                minimum = diff;
                minimum_sum = sum;
            }
            if(sum < B)
            {
                left++;
            }
            else
                right--;
        }
        i++;
    }
    return minimum_sum;
}
