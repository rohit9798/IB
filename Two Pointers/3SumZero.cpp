Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 



vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    sort(A.begin(), A.end());
    map<vector<int>, bool> m;
    int i = 0, itr = 0, left = 0, right = 0;
    vector<vector<int>> result;
    if(A.size() < 3)
        return result;
    while(itr < A.size() - 2)
    {
        left = itr + 1;
        right = A.size() - 1;
        while(right > left)
        {
            int sum = A[itr] + A[left] + A[right];
            if(sum == 0)
            {
                vector<int> temp;
                temp.push_back(A[itr]);
                temp.push_back(A[left]);
                temp.push_back(A[right]);
                if(m.find(temp) == m.end())
                {
                    m[temp]++;
                    result.push_back(temp);
                }
                left++;
                right--;
            }
            else if(sum < 0)
                left++;
            else
                right--;
        }
        itr++;
    }
    return result;
}
