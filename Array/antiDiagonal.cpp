Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i = 0, j = 0, k = 0, initial_k, initial_j;
    vector<vector<int>> result(A.size() + A.size() - 1);
    for(i = 0; i < A.size(); i++)
    {
        j = i;
        k = 0;
        initial_k = k;
        initial_j = j;
      /* */do
       {
           result[i].push_back(A[k][j]);
           k++;
           j--;
       }while(initial_k != j && initial_j != k && j > 0 && k < A.size());
       if(j >= 0 && k < A.size())
        result[i].push_back(A[k][j]);
    }
    for(int l = 1; l < A.size(); l++)
    {
        j = A.size() - 1;
        k = l;
        initial_k = k;
        initial_j = j;
       do
       {
           result[i].push_back(A[k][j]);
           k++;
           j--;
       }while(initial_k != j && initial_j != k && j > 0 && k < A.size());
       if(j >= 0 && k < A.size())
        result[i].push_back(A[k][j]);
       i++;
    }
    return result;
}
