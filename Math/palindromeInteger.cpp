Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False


int Solution::isPalindrome(int A) {
    
    int reverse = 0;
    int i = 0;
    int num = A;
    if(A < 0)
        return false;
    int digits = 0;
    while(num != 0)
    {
        digits++;
        num = num / 10;
    }
    num = A;
    while(num != 0)
    {
        reverse = reverse + (num % 10) * pow(10, digits - i - 1);
        i++;
        num = num / 10;
    }
    if(reverse == A)
        return true;
    return false;
}
