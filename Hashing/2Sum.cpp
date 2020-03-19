Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2



vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    multimap<int, int> m;
    map<int, int> m1;
    vector<int> result;
    for(int i = 0; i < A.size(); i++)
    {
        m.insert(make_pair(A[i], i));
    }
    multimap<int, int> :: iterator itr, jtr;
    itr = m.begin();
    jtr = m.end();
    jtr--;
    while(itr != jtr)
    {
        int sum = itr -> first + jtr -> first;
        if(sum == B)
        {
            if(itr -> second < jtr -> second)
                m1[jtr -> second + 1] = itr -> second + 1;
            else
                m1[itr -> second + 1] = jtr -> second + 1;
            jtr--;
        }
        else if(sum < B)
        {
            itr++;
        }
        else if(sum > B)
            jtr--;
    }
    map<int, int> :: iterator ktr;
    ktr = m1.begin();
    if(m1.begin() == m1.end())
        return result;
    result.push_back(ktr -> second);
    result.push_back(ktr -> first);
    return result;
}
