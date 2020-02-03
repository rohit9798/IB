Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.



int myCompare(string s1, string s2)
{
    string s1s2 = s1.append(s2);
    string s2s1 = s2.append(s1);
    return s1s2.compare(s2s1) > 0 ? 1 : 0;
}
string Solution::largestNumber(const vector<int> &A) {
    
    vector<string> B;
    string result = "";
    for(int i = 0; i < A.size(); i++)
    {
        B.push_back(to_string(A[i]));
    }
    sort(B.begin(), B.end(), myCompare);
    result = B[0];
    if(B[0] == "0")
        return "0";
    for(int i = 1; i < B.size(); i++)
    {
        result = result + B[i];
    }
    return result;/**/
}
