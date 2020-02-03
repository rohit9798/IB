Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)




int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
   int Lmin[n], Rmax[n];
   Lmin[0] = A[0];
   for(int i = 1; i < n; i++)
   {
       Lmin[i] = A[i] < Lmin[i - 1] ? A[i] : Lmin[i - 1]; 
   }
   Rmax[n - 1] = A[n - 1];
   for(int i = n - 2; i >= 0; i--)
   {
       Rmax[i] = A[i] > Rmax[i + 1] ? A[i] : Rmax[i + 1];
   }
   int i = 0, j = 0, max = 0;
   while(i < n && j < n)
   {
       if(Lmin[i] <= Rmax[j])
       {
           max = max < j - i ? j - i : max;
           j++;
       }
       else
       {
           i++;
       }
   }
   return max;
}
