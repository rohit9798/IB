For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1


int Solution::colorful(int A) {
    
    map<int, int> m;
    int rem;
    while(A > 0)
    {
        int num = 0;
        int temp = A;
        int product = 1;
        while(temp > 0)
        {
            rem = temp % 10;
            num = num * 10 + rem;
            product *= rem;
            temp = temp / 10;
            if(m.find(product) == m.end())
                m[product] = num;
            else
                return 0;
        }
        A = A/ 10;
    }
    return 1;
}
