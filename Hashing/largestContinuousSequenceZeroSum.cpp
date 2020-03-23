Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
 
 
 vector<int> Solution::lszero(vector<int> &A) {
    
    int sum[A.size()];
    vector<int> result;
    sum[0] = A[0];
    for(int i = 1; i < A.size(); i++)
    {
        sum[i] = A[i] + sum[i - 1];
    }
    unordered_map<int, int> m;
    int index1 = -1;
    int index2 = -1;
    int maximum = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
        if(sum[i] == 0)
        {
            if(i > maximum)
            {
                maximum = i + 1;
                index1 = -1;
                index2 = i;
            }
        }
        if(m.find(sum[i]) != m.end())
        {
            if(i - m[sum[i]] > maximum)
            {
                maximum = i - m[sum[i]];
                index1 = m[sum[i]];
                index2 = i;
            }
        }
        else
        {
            m[sum[i]] = i;
        }
    }
    index1++;
    while(index1 <= index2)
    {
        result.push_back(A[index1]);
        index1++;
    }
    return result;
}
