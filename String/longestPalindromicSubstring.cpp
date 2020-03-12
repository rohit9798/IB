Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"




string Solution::longestPalindrome(string A) {
    
    int start = 0, low, high, maxlength = INT_MIN;
    string result = "";
    if(A.length() == 1)
        return A;
    if(A.length() == 2)
    {
        if(A[0] == A[1])
            return A;
        else
        {
            result = A[0];
            return result;
        }
    }
    for(int i = 1; i < A.length(); i++)
    {
        low = i - 1;
        high = i;
        while(low >= 0 && high < A.length() && A[low] == A[high])
        {
            if(high - low + 1 > maxlength)
            {
                start = low;
                maxlength = high - low + 1;
            }
            low--;
            high++;
        }
        
        low = i - 1;
        high = i + 1;
        while(low >= 0 && high < A.length() && A[low] == A[high])
        {
            if(high - low + 1 > maxlength)
            {
                start = low;
                maxlength = high - low + 1;
            }
            low--;
            high++;
        }
    }
    int i = 0;
    while(i < maxlength)
    {
        result = result + A[start + i];
        i++;
    }
    return result;
}
