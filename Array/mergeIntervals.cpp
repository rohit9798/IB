Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.



vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
   
    vector<Interval> result;
    Interval create;
    int i, flag = 0;
    if(A.size() == 0)
    {
        result.push_back(newInterval);
        return result;
    }
    if(newInterval.end < A[0].start)
    {
        result.push_back(newInterval);
        for(int j = 0; j < A.size(); j++)
        {
            result.push_back(A[j]);
        }
        return result;
    }
    for(i = 0; i < A.size(); i++)
    {
        if( newInterval.start <= A[i].end)
        {
            flag = 1;
            break;
        }
        else
        {
            result.push_back(A[i]);
        }
    }
    if(flag == 1)
    {
        if(A[i].start <= newInterval.start)
            create.start = A[i].start;
        else
            create.start = newInterval.start;
        int j = i;
        while( i < A.size() && (!(A[i].start <= newInterval.end && A[i].end >= newInterval.end)) )
        {
            i++;
        }
        if(i == A.size())
        {
            if(A[j].start > newInterval.end)
            {
                create.end = newInterval.end;
                i = j;
            }
            else if(A[i - 1].end < newInterval.end)
            {
                create.end = newInterval.end;
            }
            else
            {
                for(int k = j; k < i - 1; k++)
                {
                    if(A[k].end < newInterval.end && A[k + 1].start > newInterval.end)
                    {
                        create.end = newInterval.end;
                        i = k + 1;
                    }
                }
            }
        }
        else
        {
            if(A[i].end >= newInterval.end)
                create.end = A[i].end;
            else
                create.end = newInterval.end;
            i++;
        }
        result.push_back(create);
        while(i < A.size())
        {
            result.push_back(A[i]);
            i++;
        }
    }
    else
    {
        result.push_back(newInterval);
    }
    return result;
}
