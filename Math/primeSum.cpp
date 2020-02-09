Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 



int isPrime(int number)
{
    if(number <= 1)
        return 0;
    for(int i = 2; i <= number / 2; i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}
vector<int> Solution::primesum(int A) {
    
    vector<int> result;
    for(int i = 2; i < A; i++)
    {
        if(isPrime(i) == 1)
        {
            int r = A - i;
            if(isPrime(r) == 1)
            {
                result.push_back(i);
                result.push_back(r);
                break;
            }
        }
            
    }
    return result;
}
