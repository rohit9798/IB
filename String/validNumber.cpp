
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem






int Solution::isNumber(const string A) {
    
    int index = 0, flag = 0, flagdot  = 0;
    int i = 0;
    while(index < A.length() && A[index] != 'e')
    {
        index++;
    }
    if(index < A.length())
    {
        while(A[i] == ' ')
            i++;
        if(A[i] == '-')
            i++;
        else if(A[i] == '+')
            i++;
        while(i < A.length() && A[i] == ' ')
            i++;
        if(A.length() == i)
            return 0;
        while(A[i] >= 48 && A[i] <= 57)
        {
            i++;
        }
        if(A[i] == '.')
        {
            i++;
            flagdot = 1;
            while(A[i] >= 48 && A[i] <= 57)
            {
                i++;
                flag = 1;
            }
        }
        if(A[i] != 'e' || (flagdot == 1 && flag == 0))
            return 0;
        else
        {
            i++;
            if(A[i] == '-' || A[i] == '+')
                i++;
            while(i < A.length() && A[i] >= 48 && A[i] <= 57)
                i++;
        }
        while(i < A.length() && A[i] == ' ')
            i++;
        if(i == A.length())
            return 1;
        else
            return 0;
    }
    else
    {
        while(A[i] == ' ')
            i++;
        if(A[i] == '-' || A[i] == '+')
            i++;
        while(i < A.length() && A[i] == ' ')
            i++;
        if(i == A.length())
            return 0;
        while(A[i] >= 48 && A[i] <= 57)
        {
            i++;
        }
        while(i < A.length() && A[i] == ' ')
            i++;
        if(A.length() == i)
            return 1;
        if(A[i] == '.')
        {    
            i++;
            while(i < A.length() && A[i] >= 48 && A[i] <= 57)
            {
                i++;
                flag = 1;
            }
        }
        while(i < A.length() && A[i] == ' ')
            i++;
        if(i == A.length() && flag == 0)
            return 0;
        else if(i == A.length() && flag == 1)
            return 1;
        if(i == A.length())
            return 0;
        while(i < A.length() && A[i] >= 48 && A[i] <= 57)
            i++;
        while(i < A.length() && A[i] == ' ')
            i++;
        if(i == A.length())
            return 1;
        else
            return 0;
    }
}
