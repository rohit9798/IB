Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.



int Solution::lengthOfLongestSubstring(string A) {
    
    map<char, pair<int, int>> m;
    int length = INT_MIN;
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i < A.size();)
    {
        int start = i;
        while(i < A.size() && m.count(A[i]) == 0)
        {
            m[A[i]] = {1, i};
            i++;
        }
        if(length < i - start)
        {
            index1 = start;
            index2 = i;
            length = i - start;
        }
        if(i < A.size() && m.count(A[i]) != 0)
            i = m[A[i]].second + 1;
        
        m.clear();
    }
    return length;
}
