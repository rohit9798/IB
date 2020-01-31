You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    vector<int> result;
    int a, b; 
    long long n = A.size();
    long long sum_of_array = 0, sum_of_int = 0, sum_of_sq_array = 0, sum_of_sq_int = 0;
    for(int i = 0; i < A.size(); i++)
    {
        sum_of_array += (long long)A[i];
    }
    sum_of_int = n * (n + 1)/2;
    result.push_back(sum_of_array);
    result.push_back(sum_of_int);
    return result;
    for(int i = 0; i < A.size(); i++)
    {
        sum_of_array += (long long)((long long)A[i] * (long long)A[i]);
    }
    sum_of_sq_int = n * (n + 1) * (2 * n + 1)/6;
    long long c = sum_of_int - sum_of_array;
    long long d = sum_of_sq_int - sum_of_sq_array;
    result.push_back(c);
    result.push_back(d);
    return result;
    d = d / c;
    long long d0, d1, d2;
    d0 = -2;
    d1 = c - d;
    d2 = -(d + c);
    a = d1/d0;
    b = d2/d0;
    result.push_back(a);
    result.push_back(b);
    return result;
}
