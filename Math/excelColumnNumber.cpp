Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
    
    
    
int Solution::titleToNumber(string A) {
    
    int len = A.length();
    int result = 1;
    if(len == 1)
    {
        result = A[0] - 64;
        return result;
    }
    for(int i = 0; i < len; i++)
    {
        int j = A[i] - 64;
        result += j * pow(26, len - i -1);
    }
    return result - 1;
}
