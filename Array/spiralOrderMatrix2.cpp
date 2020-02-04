Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]


vector<vector<int> > Solution::generateMatrix(int A) {
    
    vector<vector<int>> result(A, vector<int> (A));
    int last_row = A - 1;
    int last_column = A - 1;
    int l = 0, k = 0;
    int count = 1;
    while(k <= last_row && l <= last_column)
    {
        for(int i = l; i <= last_column; i++)
        {
            result[k][i] = count++;
        }
        k++;
        for(int i = k; i <= last_row; i++)
        {
            result[i][last_column] = count++;
        }
        last_column--;
        if(k <= last_row)
        {
            for(int i = last_column; i >= l; i--)
            {
                result[last_row][i] = count++;
            }
            last_row--;
        }
        if(l <= last_column)
        {
            for(int i = last_row; i >= k; i--)
            {
                result[i][l] = count++;
            }
            l++;
        }
    }
    return result;
}
