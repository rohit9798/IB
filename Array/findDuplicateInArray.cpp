Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1


int Solution::repeatedNumber(const vector<int> &A) {
    
     int n = A.size();
     n = n -1;
     int sq = sqrt(n); 
  
    int range = (n / sq) + 1; 
  
    int count[range];
    for( int i = 0; i < range; i++)
        count[i] = 0;
  
    for (int i = 0; i <= n; i++) 
    {
        count[(A[i] - 1) / sq]++; 
    } 
  
    int selected_block = range - 1; 
    for (int i = 0; i < range - 1; i++) 
    { 
        if (count[i] > sq) 
        { 
            selected_block = i; 
            break; 
        } 
    } 
  
    unordered_map<int, int> m; 
    for (int i = 0; i <= n; i++) 
    { 
        if ( ((selected_block * sq) < A[i]) && 
                (A[i] <= ((selected_block + 1) * sq))) 
        { 
            m[A[i]]++; 
  
            if (m[A[i]] > 1) 
                return A[i]; 
        } 
    } 
  
    return -1; 
} 
