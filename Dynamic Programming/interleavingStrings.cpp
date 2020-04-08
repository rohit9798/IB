Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
    
    
    
int Solution::isInterleave(string A, string B, string C) {
    
    map<char, int> m1, m2;
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();
    if(n3 != n1 + n2)
        return 0;
    else
    {
        int j = 0;
        for(int i = 0; i < n3; i++)
        {
            if(A[j] == C[i])
            {
                m1[A[j]]++;
                j++;
            }
        }
        if(j < n1)
            return 0;
        j = 0;
        for(int i = 0; i < n3; i++)
        {
            if(B[j] == C[i])
            {
                m1[B[j]]++;
                j++;
            }
        }
        if(j < n2)
            return 0;
        for(int i = 0; i < n3; i++)
        {
            m2[C[i]]++;
        }
        if(m1 != m2)
        {
            cout<<m1.size()<<m2.size();
            return 0;
        }
    }
    return 1;
}
