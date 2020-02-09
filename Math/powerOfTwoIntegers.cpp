Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 


int Solution::isPower(int A) {
    
    int n = A;
    int flag = 0;
    if(A == 1)
        return 1;
    for(int i = 2; i <= sqrt(A); i++)
    {
        n = A;
        while(n != 1)
        {
            if(n % i == 0)
            {
                n = n / i;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return 1;
        flag = 0;
    }
    return 0;
    
}
