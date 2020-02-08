You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]



void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Solution::rotate(vector<vector<int> > &A) {
    
    int k = 0, l = 0;
    for(int i = 0; i < A.size(); i++)
    {
        l = 0;
        for(int j = A.size() - 1; j >= 0; j--)
        {
            swap(&A[k][l], &A[j][i]);
            l++;
        }
        k++;
    }
    
}
