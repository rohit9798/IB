Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 


string Solution::convertToTitle(int n) {
    
    char str[100]; // To store result (Excel column name) 
    int i = 0; // To store current index in str which is result 

    while (n>0) 
    { 
        // Find remainder 
        int rem = n%26; 

        // If remainder is 0, then a 'Z' must be there in output 
        if (rem==0) 
        { 
            str[i++] = 'Z'; 
            n = (n/26)-1; 
        } 
        else // If remainder is non-zero 
        { 
            str[i++] = (rem-1) + 'A'; 
            n = n/26; 
        } 
    } 
    str[i] = '\0'; 

    // Reverse the string and print result 
    reverse(str, str + strlen(str)); 
    return str; 
} 
