Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.





vector<int> Solution::plusOne(vector<int> &A) {
    
    vector<int> result;
    int c = 0, digit;
   for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != 0)
        {
            digit = i; 
            break;
        }
    }
    if(A[A.size() - 1] + 1 > 9)
    {
        c = 1;
        result.push_back(0);
    }
    else
        result.push_back(A[A.size() - 1] + 1);
    
    for(int i = A.size() - 2; i >= 0 ; i--)
    {
        if(A[i] + c > 9)
        {    
            result.push_back(0);
            c = 1;
        }
        else
        {
            if(A[i] + c > 0 || i >= digit)
                result.push_back(A[i] + c);
            c = 0;
        }
    }
    if(c == 1)
        result.push_back(1);
    reverse(result.begin(), result.end());
    return result;
}
