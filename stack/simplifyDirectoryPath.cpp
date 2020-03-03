Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
    
    
    
string Solution::simplifyPath(string A) {
    
    stack<string> s;
    stack<string> t;
    string temp = "";
    for(int i = 1; i < A.length(); i++)
    {
        if(A[i] == '.' && A[i + 1] == '.')
        {
            if(!s.empty())
                s.pop();
            i++;
        }
        else if(A[i] == '.')
        {
            i++;
        }
        else
        {
            while(i < A.length() && A[i] != '/')
            {
                temp = temp + A[i];
                i++;
            }
            if(i == A.length() && temp.length() != 0)
                s.push(temp);
            if(i < A.length() && A[i] == '/')
            {
                if(temp.length() != 0)
                {
                    s.push(temp);
                    temp = "";
                }
            }
        }
    }
    while(!s.empty())
    {
        t.push(s.top());
        s.pop();
    }
   temp = "";
    while(!t.empty())
    {
        temp += "/" + t.top();
        t.pop();
    }
    if(temp.length() == 0)
        temp = "/";
    /**/
    return temp;
}
