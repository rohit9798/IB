Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]



void Solution::setZeroes(vector<vector<int> > &A) {
   
   vector<pair<int, int>> index;
   int flag = 0;
   /*for(int i = 0; i < A.size(); i++)
   {
       for(int j = 0; j < A[i].size(); j++)
       {
           if(A[i][j] == 0)
           {
                
           }
       }
   }
   if(flag == A.size() * A[0].size())
        return;
   vector<pair<int, int>> :: iterator itr;
   for(itr = index.begin(); itr != index.end(); itr++)
   {
       int i = itr->first;
       for(int j = 0; j < A[i].size(); j++)
       {
           A[i][j] = 0;
       }
       int j = itr -> second;
       for(i = 0; i < A.size(); i++)
       {
           A[i][j] = 0;
       }
   }*/
   bool row = false, column = false;
   for(int i = 0; i < A.size(); i++)
   {
       for(int j = 0; j < A[i].size(); j++)
       {
           if(i == 0 && A[i][j] == 0)
                row = true;
           if(j == 0 && A[i][j] == 0)
                column = true;
           if(A[i][j] == 0)
           {
               A[i][0] = 0;
               A[0][j] = 0;
           }
       }
   }
   
   for(int i = 1; i < A.size(); i++)
   {
       for(int j = 1; j < A[i].size(); j++)
       {
           if(A[0][j] == 0 || A[i][0] == 0)
                A[i][j] = 0;
       }
   }
   if(row == true)
   {
       for(int i = 0; i < A[0].size(); i++)
       {
           A[0][i] = 0;
       }
   }
   if(column == true)
   {
       for(int i = 0; i < A.size(); i++)
       {
           A[i][0] = 0;
       }
   }
}
