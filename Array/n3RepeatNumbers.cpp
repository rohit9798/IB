You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 


int Solution::repeatedNumber(const vector<int> &A) {

    int first = INT_MAX, second = INT_MAX, count1 = 0, count2 = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(first == A[i])
            count1++;
        else if(second == A[i])
            count2++;
        else if(count1 == 0)
        {
            count1++;
            first = A[i];
        }
        else if(count2 == 0)
        {
            count2++;
            second = A[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(first == A[i])
            count1++;
        else if(second == A[i])
            count2++;
    }
    if(count1 > A.size() / 3)
        return first;
    else if(count2 > A.size()/3)
        return second;
    else
        return -1;
}
