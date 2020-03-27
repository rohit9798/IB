Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)



vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    map<pair<int, int>, int> m;
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    vector<int> result;
    int start = 0;
    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    m[{n - 1, n - 1}]++;
    while(start < n)
    {
        auto temp = pq.top();
        pq.pop();
        result.push_back(temp.first);
        pair<int, int> p1 = {temp.second.first - 1, temp.second.second};
        if(m[p1] == 0)
        {
            pq.push(A[p1.first] + B[p1.second], p1);
            m[p1]++;
        }
        pair<int, int> p2 = {temp.second.first, temp.second.second - 1};
        if(m[p2] == 0)
        {
            pq.push(A[p2.first] + B[p2.second], p2);
            m[p2]++;
        }
        start++;
    }
    return result;
}
