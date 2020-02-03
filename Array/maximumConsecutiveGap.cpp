Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.



int Solution::maximumGap(const vector<int> &A) {
/**/
    if(A.size() >= 2)
    {
        int min = A[0], max = A[0];
        for(int i = 0; i < A.size(); i++)
        {
            min = A[i] > min ? min : A[i];
            max = A[i] > max ? A[i] : max;
        }
        int bucket[max - min + 1];
        for(int i = 0; i < max - min + 1; i++)
        {
            bucket[i] = 0;
        }
        for(int i = 0; i < A.size(); i++)
        {
            bucket[A[i] - min] = A[i];
        }
        int max_diff = 0;
        int j = 0;
        for(int i = 0; i < max - min; )
        {
            j = i + 1;
            while(j < max - min + 1 && bucket[j] == 0)
            {
                j++;
            }
            if(j < max - min + 1)
            {
                if(max_diff < bucket[j] - bucket[i])
                    max_diff = bucket[j] - bucket[i];
                i = j;
            }
            else 
                break;
        }
        return max_diff;
    }
    else
        return 0;
}
