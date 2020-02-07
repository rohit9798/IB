Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.



int Solution::solve(vector<string> &A) {
    
    int n = A.size();
    float first = stof(A[0]), second = stof(A[1]) , third = stof(A[2]);
    for(int i = 3; i < n; i++)
    {
            float result = first + second + third;
            if(result <= 1)
            {
                if(first < second && first < third)
                    first = stof(A[i]);
                else if(second < third && second < first)
                    second = stof(A[i]);
                else if(third < first && third < second)
                    third = stof(A[i]);
            }
            else if(result >= 2)
            {
                if(first > second && first > third)
                    first = stof(A[i]);
                else if(second > third && second > first)
                    second = stof(A[i]);
                else if(third > first && third > second)
                    third = stof(A[i]);
            }
            else
                return 1;
    }
    if(first + second + third < 2 && first + second + third > 1)
        return 1;
    return 0;
}
