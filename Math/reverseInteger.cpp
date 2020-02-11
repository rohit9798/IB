Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer



int Solution::reverse(int A) {
    
    double reverse_int = 0;
    int digits = 0;
    int n = A;
    int flag = 0;
    if(n < 0)
    {
        flag = 1;
        A = -A;
        n = -n;
    }
    while(n != 0)
    {
        digits++;
        n = n / 10;
    }
    n = A;
    while(n != 0)
    {
        reverse_int += (n % 10) * pow(10, digits - 1);
        digits--;
        n = n / 10;
    }
    if(reverse_int >= 2147483642 || reverse_int <= -2147483642)
        return 0;
    if(flag == 1)
        return -reverse_int;
    else
        return reverse_int;
}
