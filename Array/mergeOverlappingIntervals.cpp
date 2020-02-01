Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.



bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start <= i2.start); 
} 
vector<Interval> Solution::merge(vector<Interval> &A) {
   
   vector<Interval> result;
   Interval create;
   sort(A.begin(), A.end(), compareInterval);
   for(int i = 0; i < A.size(); i++)
   {
       create.start = A[i].start;
       create.end = A[i].end;
       while((i + 1 < A.size() && A[i].end >= A[i + 1].start) || (i + 1 < A.size() && create.end >= A[i + 1].start))
        {
            create.end = A[i].end < create.end ? create.end : A[i].end;
            i++;   
        }
        create.end = A[i].end < create.end ? create.end : A[i].end;
        result.push_back(create);
   }
   return result;
}
