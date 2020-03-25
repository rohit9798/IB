Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])



int Solution::maxPoints(vector<int> &A, vector<int> &B) {

    map<pair<double, double>, int> m;
    int maximum = INT_MIN;
    if(A.size() < 2)
        return A.size();
    for(int i = 0; i < A.size(); i++)
    {
        int x = A[i];
        int y = B[i];
        for(int j = 0; j < A.size(); j++)
        {
            if(i != j)
            {
                int temp_x = A[j];
                int temp_y = B[j];
                if(temp_x - x == 0)
                    m[make_pair(INT_MAX, 0)]++;
                else
                {
                    double slope = (double)(temp_y - y) / (temp_x - x);
                    double c = y - slope * x;
                    m[{slope, c}]++;
                }
            }
        }
        map<pair<double, double>, int> :: iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
        {
            if(maximum < itr -> second)
                maximum = itr -> second;
        }
        m.clear();
    }
    return maximum + 1;
}
