You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).



vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    map<string, queue<int>> m1;
    string temp = "";
    int len = B[0].length();
    int n = B.size(), p = 0;
    vector<int> result;
    for(int i = 0; i < B.size(); i++)
    {
        m1[B[i]].push(i);
    }
    for(int i = 0; i < A.length(); i++)
    {
        p = 0;
        int k = i;
        while(p < n)
        {
            temp = "";
            for(int j = k; j < k + len; j++)
            {
                temp = temp + A[j];
            }
            if(m1.count(temp) > 0 && m1[temp].size() > 0)
            {
                p++;
                k = k + len;
                m1[temp].pop();
            }
            else
                break;
        }
        if(p == n)
        {
            result.push_back(i);
        }
        m1.clear();
        for(int i = 0; i < B.size(); i++)
        {
            m1[B[i]].push(i);
        }
    }
    return result;
}
