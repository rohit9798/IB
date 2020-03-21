Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

struct myComparator 
{
    bool operator() (const vector<int>& A, const vector<int>& B) const
    {
        int i = 0, j = 0;
        while(i < 4 && j < 4)
        {
            if(A[i] == B[j])
            {
                i++;
                j++;
                continue;
            }
            break;
        }
        return A[i] < B[j];
    }
};


vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    int i = 0, j = 1, k, l, sum;
    vector<int> v;
    vector<vector<int>> result;
    sort(A.begin(), A.end());
    map<vector<int>, int, myComparator> m;
    for(i = 0; i < A.size() - 3; i++)
    {
        for(j = i + 1; j < A.size() - 2; j++)
        {
            int temp_sum = A[i] + A[j];
            k = j + 1;
            l = A.size() - 1;
            while(k < l)
            {
                sum = temp_sum + A[k] + A[l]; 
                if(sum == B)
                {
                    v.push_back(A[i]);
                    v.push_back(A[j]);
                    v.push_back(A[k]);
                    v.push_back(A[l]);
                    m[v] = 1;
                    v.clear();
                    k++;
                    l--;
                }
                else if(sum < B)
                    k++;
                else if(sum > B)
                    l--;
            }
        }
    }
    map<vector<int>, int, myComparator> :: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        result.push_back(itr -> first);
    }
    return result;
    
}
